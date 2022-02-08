#include "utils_lm.h"

// [[Rcpp::export]]
Rcpp::List EL_lm(const Eigen::MatrixXd& x,
                 const Eigen::VectorXd& y,
                 const Eigen::VectorXd& beta,
                 const double threshold,
                 const int maxit,
                 const double abstol) {
  // check design matrix
  const int p = x.cols();
  if (x.rows() <= p) {
    Rcpp::stop("design matrix must have full column rank");
  }
  const Eigen::FullPivLU<Eigen::MatrixXd> lu_decomp(x);
  if (lu_decomp.rank() != p) {
    Rcpp::stop("design matrix must have full column rank");
  }

  // overall test
  const EL el(x.array().colwise() * (y - x * beta).array(),
              threshold, maxit, abstol);
  const Eigen::VectorXd bhat = x.colPivHouseholderQr().solve(y);
  const Eigen::VectorXd fitted_values = x * bhat;
  const Eigen::VectorXd residuals = y - fitted_values;

  // test for each coefficient
  // chi-square statistic
  std::vector<double> chisq_statistic(p);
  // convergence
  std::vector<bool> convergence(p);
  // p-value
  Rcpp::Function pchisq("pchisq");
  std::vector<double> p_value(p);

  // // progress bar
  // SEXP bar = PROTECT(
  //   cli_progress_bar(p, Rcpp::List::create(
  //       Rcpp::Named("name") = "testing parameters",
  //       Rcpp::Named("type") = "tasks")));

  for (int i = 0; i < p; ++i) {
    Rcpp::checkUserInterrupt();
    Eigen::MatrixXd lhs = Eigen::MatrixXd::Zero(1, p);
    lhs(i) = 1;
    minEL lm_result = test_lm(bhat, x, y, lhs,
                              Eigen::Matrix<double, 1, 1>(0),
                              20, maxit, abstol);
    chisq_statistic[i] = 2 * lm_result.nlogLR;
    convergence[i] = lm_result.convergence;
    p_value[i] = Rcpp::as<double>(pchisq(chisq_statistic[i],
                                         Rcpp::Named("df") = 1,
                                         Rcpp::Named("lower.tail") = false));
    // // progress update
    // if (CLI_SHOULD_TICK) cli_progress_set(bar, i);

  }
  // cli_progress_done(bar);
  // UNPROTECT(1);

  Rcpp::List result = Rcpp::List::create(
    Rcpp::Named("optim") = Rcpp::List::create(
      Rcpp::Named("lambda") = el.lambda,
      Rcpp::Named("logLR") = -el.nlogLR,
      Rcpp::Named("iterations") = el.iterations,
      Rcpp::Named("convergence") = el.convergence,
      Rcpp::Named("par.tests") = Rcpp::List::create(
        Rcpp::Named("statistic") = chisq_statistic,
        Rcpp::Named("p.value") = p_value,
        Rcpp::Named("convergence") = convergence)),
    Rcpp::Named("coefficients") = bhat,
    Rcpp::Named("residuals") = residuals,
    Rcpp::Named("rank") = p,
    Rcpp::Named("fitted.values") = fitted_values);
  result.attr("class") = Rcpp::CharacterVector({"el_lm", "melt"});
  return result;
}
