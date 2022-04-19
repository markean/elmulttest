#include "EL.h"

// [[Rcpp::export]]
Rcpp::List glm_(
    const std::string family,
    const std::string link,
    const Eigen::Map<Eigen::MatrixXd>& x,
    const Eigen::Map<Eigen::VectorXd>& par0,
    const bool intercept,
    const int maxit,
    const int maxit_l,
    const double tol,
    const double tol_l,
    const Rcpp::Nullable<double> th,
    const int nthreads,
    const Eigen::Map<Eigen::ArrayXd>& wt)
{
  const std::string method = family + "_" + link;
  const int p = x.cols() - 1;
  // Eigen::ArrayXd w;
  // if (wt.isNotNull()) {
  //   w = Rcpp::as<Eigen::ArrayXd>(wt);
  // }

  // overall test
  Eigen::VectorXd par(p);
  Eigen::VectorXd l(p);
  double nllr{};
  int iter{};
  bool conv{};
  Eigen::ArrayXd logp(x.rows());
  double loglik{};
  if (intercept && p > 1) {
    Eigen::MatrixXd lhs(p - 1, p);
    lhs.col(0) = Eigen::MatrixXd::Zero(p - 1, 1);
    lhs.rightCols(p - 1) = Eigen::MatrixXd::Identity(p - 1, p - 1);
    const Eigen::VectorXd rhs = Eigen::VectorXd::Zero(p - 1);
    const double test_th = th_nloglr(p - 1, th);
    const MINEL el(method, par0, x, lhs, rhs, maxit, maxit_l, tol, tol_l,
                   test_th, wt);
    par = el.par;
    l = el.l;
    nllr = el.nllr;
    iter = el.iter;
    conv = el.conv;
    logp = el.logp(x);
    loglik = el.loglik();
  } else {
    par = Eigen::VectorXd::Zero(p);
    const double test_th = th_nloglr(p, th);
    const EL el(method, par, x, maxit_l, tol_l, test_th, wt);
    l = el.l;
    nllr = el.nllr;
    iter = el.iter;
    conv = el.conv;
    logp = el.logp(x);
    loglik = el.loglik();
  }

  // parameter tests
  Rcpp::NumericVector chisq_val(p);
  Rcpp::LogicalVector par_conv(p);
  const double test_th = th_nloglr(1, th);
  // default(none) shared(p, maxit) schedule(auto)
  #pragma omp parallel for num_threads(nthreads)
  for (int i = 0; i < p; ++i) {
    Eigen::MatrixXd lhs = Eigen::MatrixXd::Zero(1, p);
    lhs(i) = 1.0;
    const MINEL par_test(method, par0, x, lhs, Eigen::VectorXd::Zero(1), maxit,
                         maxit_l, tol, tol_l, test_th, wt);
    chisq_val[i] = 2.0 * par_test.nllr;
    par_conv[i] = par_test.conv;
  }

  Rcpp::List result = Rcpp::List::create(
    Rcpp::Named("optim") = Rcpp::List::create(
      Rcpp::Named("method") = method,
      Rcpp::Named("par") = par,
      Rcpp::Named("lambda") = l,
      Rcpp::Named("logLR") = -nllr,
      Rcpp::Named("iterations") = iter,
      Rcpp::Named("convergence") = conv),
    Rcpp::Named("par.tests") = Rcpp::List::create(
      Rcpp::Named("statistic") = chisq_val,
      Rcpp::Named("convergence") = par_conv),
    Rcpp::Named("log.prob") = logp,
    Rcpp::Named("loglik") = loglik,
    Rcpp::Named("statistic") = 2.0 * nllr);
  return result;
}