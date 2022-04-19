#include "EL.h"

// [[Rcpp::export]]
Rcpp::List eval_(
    const std::string method,
    const Eigen::Map<Eigen::VectorXd>& par0,
    const Eigen::Map<Eigen::MatrixXd>& x,
    const int maxit_l,
    const double tol_l,
    const Rcpp::Nullable<double> th,
    const Rcpp::Nullable<const Eigen::Map<const Eigen::ArrayXd>&> wt =
      R_NilValue)
{
  const double test_th = th_nloglr(par0.size(), th);
  const EL el(method, par0, x, maxit_l, tol_l, test_th, wt);

  Rcpp::List result = Rcpp::List::create(
    Rcpp::Named("optim") = Rcpp::List::create(
      Rcpp::Named("method") = method,
      Rcpp::Named("par") = el.par,
      Rcpp::Named("lambda") = el.l,
      Rcpp::Named("logLR") = -el.nllr,
      Rcpp::Named("iterations") = el.iter,
      Rcpp::Named("convergence") = el.conv),
    Rcpp::Named("log.prob") = el.logp(x),
    Rcpp::Named("loglik") = el.loglik(),
    Rcpp::Named("statistic") = 2.0 * el.nllr);
  return result;
}

// [[Rcpp::export]]
Rcpp::List eval_g_(
    const Eigen::Map<Eigen::MatrixXd>& g,
    const int maxit_l,
    const double tol_l,
    const Rcpp::Nullable<double> th,
    const Rcpp::Nullable<const Eigen::Map<const Eigen::ArrayXd>&> wt =
      R_NilValue)
{
  const double test_th = th_nloglr(g.cols(), th);
  const EL el(g, maxit_l, tol_l, test_th, wt);

  Rcpp::List result = Rcpp::List::create(
    Rcpp::Named("optim") = Rcpp::List::create(
      Rcpp::Named("lambda") = el.l,
      Rcpp::Named("logLR") = -el.nllr,
      Rcpp::Named("iterations") = el.iter,
      Rcpp::Named("convergence") = el.conv),
    Rcpp::Named("log.prob") = el.logp_g(g),
    Rcpp::Named("loglik") = el.loglik(),
    Rcpp::Named("statistic") = 2.0 * el.nllr);
  return result;
}
