// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppEigen.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// get_max_threads
int get_max_threads();
RcppExport SEXP _melt_get_max_threads() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(get_max_threads());
    return rcpp_result_gen;
END_RCPP
}
// get_rank
int get_rank(const Eigen::Map<Eigen::MatrixXd>& x);
RcppExport SEXP _melt_get_rank(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd>& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(get_rank(x));
    return rcpp_result_gen;
END_RCPP
}
// boot_
Rcpp::NumericVector boot_(const int B, const int seed, const int nthreads, const std::string method, const Eigen::Map<Eigen::MatrixXd>& x, const Eigen::Map<Eigen::VectorXd>& par, const int maxit_l, const double tol_l, const Rcpp::Nullable<double> th, const Eigen::Map<Eigen::ArrayXd>& wt);
RcppExport SEXP _melt_boot_(SEXP BSEXP, SEXP seedSEXP, SEXP nthreadsSEXP, SEXP methodSEXP, SEXP xSEXP, SEXP parSEXP, SEXP maxit_lSEXP, SEXP tol_lSEXP, SEXP thSEXP, SEXP wtSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const int >::type B(BSEXP);
    Rcpp::traits::input_parameter< const int >::type seed(seedSEXP);
    Rcpp::traits::input_parameter< const int >::type nthreads(nthreadsSEXP);
    Rcpp::traits::input_parameter< const std::string >::type method(methodSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd>& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::VectorXd>& >::type par(parSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit_l(maxit_lSEXP);
    Rcpp::traits::input_parameter< const double >::type tol_l(tol_lSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type th(thSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::ArrayXd>& >::type wt(wtSEXP);
    rcpp_result_gen = Rcpp::wrap(boot_(B, seed, nthreads, method, x, par, maxit_l, tol_l, th, wt));
    return rcpp_result_gen;
END_RCPP
}
// confint_
Eigen::MatrixXd confint_(const std::string method, const Eigen::Map<Eigen::VectorXd>& par0, const Eigen::Map<Eigen::MatrixXd>& x, const double cutoff, const Rcpp::IntegerVector& idx, const int maxit, const int maxit_l, const double tol, const double tol_l, const Rcpp::Nullable<double> step, const Rcpp::Nullable<double> th, const int nthreads, const Eigen::Map<Eigen::ArrayXd>& w);
RcppExport SEXP _melt_confint_(SEXP methodSEXP, SEXP par0SEXP, SEXP xSEXP, SEXP cutoffSEXP, SEXP idxSEXP, SEXP maxitSEXP, SEXP maxit_lSEXP, SEXP tolSEXP, SEXP tol_lSEXP, SEXP stepSEXP, SEXP thSEXP, SEXP nthreadsSEXP, SEXP wSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string >::type method(methodSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::VectorXd>& >::type par0(par0SEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd>& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const double >::type cutoff(cutoffSEXP);
    Rcpp::traits::input_parameter< const Rcpp::IntegerVector& >::type idx(idxSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit(maxitSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit_l(maxit_lSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const double >::type tol_l(tol_lSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type step(stepSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type th(thSEXP);
    Rcpp::traits::input_parameter< const int >::type nthreads(nthreadsSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::ArrayXd>& >::type w(wSEXP);
    rcpp_result_gen = Rcpp::wrap(confint_(method, par0, x, cutoff, idx, maxit, maxit_l, tol, tol_l, step, th, nthreads, w));
    return rcpp_result_gen;
END_RCPP
}
// confreg_
Rcpp::NumericVector confreg_(const std::string method, const Eigen::Map<Eigen::VectorXd>& par0, const Eigen::Map<Eigen::MatrixXd>& x, const int npar, const double cv, const Rcpp::IntegerVector& idx, const Eigen::Map<Eigen::MatrixXd>& circ, const int maxit, const int maxit_l, const double tol, const double tol_l, const Rcpp::Nullable<double> step, const Rcpp::Nullable<double> th, const int nthreads, const Eigen::Map<Eigen::ArrayXd>& w);
RcppExport SEXP _melt_confreg_(SEXP methodSEXP, SEXP par0SEXP, SEXP xSEXP, SEXP nparSEXP, SEXP cvSEXP, SEXP idxSEXP, SEXP circSEXP, SEXP maxitSEXP, SEXP maxit_lSEXP, SEXP tolSEXP, SEXP tol_lSEXP, SEXP stepSEXP, SEXP thSEXP, SEXP nthreadsSEXP, SEXP wSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string >::type method(methodSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::VectorXd>& >::type par0(par0SEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd>& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const int >::type npar(nparSEXP);
    Rcpp::traits::input_parameter< const double >::type cv(cvSEXP);
    Rcpp::traits::input_parameter< const Rcpp::IntegerVector& >::type idx(idxSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd>& >::type circ(circSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit(maxitSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit_l(maxit_lSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const double >::type tol_l(tol_lSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type step(stepSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type th(thSEXP);
    Rcpp::traits::input_parameter< const int >::type nthreads(nthreadsSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::ArrayXd>& >::type w(wSEXP);
    rcpp_result_gen = Rcpp::wrap(confreg_(method, par0, x, npar, cv, idx, circ, maxit, maxit_l, tol, tol_l, step, th, nthreads, w));
    return rcpp_result_gen;
END_RCPP
}
// eld_
Rcpp::NumericVector eld_(const std::string method, const Eigen::Map<Eigen::VectorXd>& par0, const Eigen::Map<Eigen::MatrixXd>& x, const int maxit_l, const double tol_l, const Rcpp::Nullable<double> th, const int nthreads, const Eigen::Map<Eigen::ArrayXd>& wt);
RcppExport SEXP _melt_eld_(SEXP methodSEXP, SEXP par0SEXP, SEXP xSEXP, SEXP maxit_lSEXP, SEXP tol_lSEXP, SEXP thSEXP, SEXP nthreadsSEXP, SEXP wtSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string >::type method(methodSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::VectorXd>& >::type par0(par0SEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd>& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit_l(maxit_lSEXP);
    Rcpp::traits::input_parameter< const double >::type tol_l(tol_lSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type th(thSEXP);
    Rcpp::traits::input_parameter< const int >::type nthreads(nthreadsSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::ArrayXd>& >::type wt(wtSEXP);
    rcpp_result_gen = Rcpp::wrap(eld_(method, par0, x, maxit_l, tol_l, th, nthreads, wt));
    return rcpp_result_gen;
END_RCPP
}
// elmt_mvchisq_
Rcpp::NumericVector elmt_mvchisq_(const std::string method, const Eigen::Map<Eigen::VectorXd>& est, const Eigen::Map<Eigen::MatrixXd>& x, const Eigen::Map<Eigen::MatrixXd>& lhs, const Eigen::Map<Eigen::VectorXi>& q, const int m, const int B);
RcppExport SEXP _melt_elmt_mvchisq_(SEXP methodSEXP, SEXP estSEXP, SEXP xSEXP, SEXP lhsSEXP, SEXP qSEXP, SEXP mSEXP, SEXP BSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string >::type method(methodSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::VectorXd>& >::type est(estSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd>& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd>& >::type lhs(lhsSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::VectorXi>& >::type q(qSEXP);
    Rcpp::traits::input_parameter< const int >::type m(mSEXP);
    Rcpp::traits::input_parameter< const int >::type B(BSEXP);
    rcpp_result_gen = Rcpp::wrap(elmt_mvchisq_(method, est, x, lhs, q, m, B));
    return rcpp_result_gen;
END_RCPP
}
// elmt_statistic_
Rcpp::NumericVector elmt_statistic_(const Eigen::Map<Eigen::VectorXi>& q, const int m, const std::string method, const Eigen::Map<Eigen::VectorXd>& est, const Eigen::Map<Eigen::MatrixXd>& x, const Eigen::Map<Eigen::VectorXd>& rhs, const Eigen::Map<Eigen::MatrixXd>& lhs, const int maxit, const int maxit_l, const double tol, const double tol_l, const Rcpp::Nullable<double> step, const Rcpp::Nullable<double> th, const Eigen::Map<Eigen::ArrayXd>& w);
RcppExport SEXP _melt_elmt_statistic_(SEXP qSEXP, SEXP mSEXP, SEXP methodSEXP, SEXP estSEXP, SEXP xSEXP, SEXP rhsSEXP, SEXP lhsSEXP, SEXP maxitSEXP, SEXP maxit_lSEXP, SEXP tolSEXP, SEXP tol_lSEXP, SEXP stepSEXP, SEXP thSEXP, SEXP wSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::VectorXi>& >::type q(qSEXP);
    Rcpp::traits::input_parameter< const int >::type m(mSEXP);
    Rcpp::traits::input_parameter< const std::string >::type method(methodSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::VectorXd>& >::type est(estSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd>& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::VectorXd>& >::type rhs(rhsSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd>& >::type lhs(lhsSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit(maxitSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit_l(maxit_lSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const double >::type tol_l(tol_lSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type step(stepSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type th(thSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::ArrayXd>& >::type w(wSEXP);
    rcpp_result_gen = Rcpp::wrap(elmt_statistic_(q, m, method, est, x, rhs, lhs, maxit, maxit_l, tol, tol_l, step, th, w));
    return rcpp_result_gen;
END_RCPP
}
// elt_
Rcpp::List elt_(const std::string method, const Eigen::Map<Eigen::VectorXd>& par0, const Eigen::Map<Eigen::MatrixXd>& x, const Eigen::Map<Eigen::MatrixXd>& lhs, const Eigen::Map<Eigen::VectorXd>& rhs, const int maxit, const int maxit_l, const double tol, const double tol_l, const Rcpp::Nullable<double> step, const Rcpp::Nullable<double> th, const Eigen::Map<Eigen::ArrayXd>& w);
RcppExport SEXP _melt_elt_(SEXP methodSEXP, SEXP par0SEXP, SEXP xSEXP, SEXP lhsSEXP, SEXP rhsSEXP, SEXP maxitSEXP, SEXP maxit_lSEXP, SEXP tolSEXP, SEXP tol_lSEXP, SEXP stepSEXP, SEXP thSEXP, SEXP wSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string >::type method(methodSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::VectorXd>& >::type par0(par0SEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd>& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd>& >::type lhs(lhsSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::VectorXd>& >::type rhs(rhsSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit(maxitSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit_l(maxit_lSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const double >::type tol_l(tol_lSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type step(stepSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type th(thSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::ArrayXd>& >::type w(wSEXP);
    rcpp_result_gen = Rcpp::wrap(elt_(method, par0, x, lhs, rhs, maxit, maxit_l, tol, tol_l, step, th, w));
    return rcpp_result_gen;
END_RCPP
}
// eval_
Rcpp::List eval_(const std::string method, const Eigen::Map<Eigen::VectorXd>& par0, const Eigen::Map<Eigen::MatrixXd>& x, const int maxit_l, const double tol_l, const Rcpp::Nullable<double> th, const Eigen::Map<Eigen::ArrayXd>& wt);
RcppExport SEXP _melt_eval_(SEXP methodSEXP, SEXP par0SEXP, SEXP xSEXP, SEXP maxit_lSEXP, SEXP tol_lSEXP, SEXP thSEXP, SEXP wtSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string >::type method(methodSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::VectorXd>& >::type par0(par0SEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd>& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit_l(maxit_lSEXP);
    Rcpp::traits::input_parameter< const double >::type tol_l(tol_lSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type th(thSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::ArrayXd>& >::type wt(wtSEXP);
    rcpp_result_gen = Rcpp::wrap(eval_(method, par0, x, maxit_l, tol_l, th, wt));
    return rcpp_result_gen;
END_RCPP
}
// eval_g_
Rcpp::List eval_g_(const Eigen::Map<Eigen::MatrixXd>& g, const int maxit_l, const double tol_l, const Rcpp::Nullable<double> th, const Eigen::Map<Eigen::ArrayXd>& wt);
RcppExport SEXP _melt_eval_g_(SEXP gSEXP, SEXP maxit_lSEXP, SEXP tol_lSEXP, SEXP thSEXP, SEXP wtSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd>& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit_l(maxit_lSEXP);
    Rcpp::traits::input_parameter< const double >::type tol_l(tol_lSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type th(thSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::ArrayXd>& >::type wt(wtSEXP);
    rcpp_result_gen = Rcpp::wrap(eval_g_(g, maxit_l, tol_l, th, wt));
    return rcpp_result_gen;
END_RCPP
}
// glm_
Rcpp::List glm_(const std::string method, const Eigen::Map<Eigen::MatrixXd>& x, const Eigen::Map<Eigen::VectorXd>& par0, const bool intercept, const int maxit, const int maxit_l, const double tol, const double tol_l, const Rcpp::Nullable<double> step, const Rcpp::Nullable<double> th, const int nthreads, const Eigen::Map<Eigen::ArrayXd>& w);
RcppExport SEXP _melt_glm_(SEXP methodSEXP, SEXP xSEXP, SEXP par0SEXP, SEXP interceptSEXP, SEXP maxitSEXP, SEXP maxit_lSEXP, SEXP tolSEXP, SEXP tol_lSEXP, SEXP stepSEXP, SEXP thSEXP, SEXP nthreadsSEXP, SEXP wSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string >::type method(methodSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd>& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::VectorXd>& >::type par0(par0SEXP);
    Rcpp::traits::input_parameter< const bool >::type intercept(interceptSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit(maxitSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit_l(maxit_lSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const double >::type tol_l(tol_lSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type step(stepSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type th(thSEXP);
    Rcpp::traits::input_parameter< const int >::type nthreads(nthreadsSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::ArrayXd>& >::type w(wSEXP);
    rcpp_result_gen = Rcpp::wrap(glm_(method, x, par0, intercept, maxit, maxit_l, tol, tol_l, step, th, nthreads, w));
    return rcpp_result_gen;
END_RCPP
}
// lm_
Rcpp::List lm_(const Eigen::Map<Eigen::MatrixXd>& x, const Eigen::Map<Eigen::VectorXd>& par0, const bool intercept, const int maxit, const int maxit_l, const double tol, const double tol_l, const Rcpp::Nullable<double> step, const Rcpp::Nullable<double> th, const int nthreads, const Eigen::Map<Eigen::ArrayXd>& w);
RcppExport SEXP _melt_lm_(SEXP xSEXP, SEXP par0SEXP, SEXP interceptSEXP, SEXP maxitSEXP, SEXP maxit_lSEXP, SEXP tolSEXP, SEXP tol_lSEXP, SEXP stepSEXP, SEXP thSEXP, SEXP nthreadsSEXP, SEXP wSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd>& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::VectorXd>& >::type par0(par0SEXP);
    Rcpp::traits::input_parameter< const bool >::type intercept(interceptSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit(maxitSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit_l(maxit_lSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const double >::type tol_l(tol_lSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type step(stepSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type th(thSEXP);
    Rcpp::traits::input_parameter< const int >::type nthreads(nthreadsSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::ArrayXd>& >::type w(wSEXP);
    rcpp_result_gen = Rcpp::wrap(lm_(x, par0, intercept, maxit, maxit_l, tol, tol_l, step, th, nthreads, w));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_melt_get_max_threads", (DL_FUNC) &_melt_get_max_threads, 0},
    {"_melt_get_rank", (DL_FUNC) &_melt_get_rank, 1},
    {"_melt_boot_", (DL_FUNC) &_melt_boot_, 10},
    {"_melt_confint_", (DL_FUNC) &_melt_confint_, 13},
    {"_melt_confreg_", (DL_FUNC) &_melt_confreg_, 15},
    {"_melt_eld_", (DL_FUNC) &_melt_eld_, 8},
    {"_melt_elmt_mvchisq_", (DL_FUNC) &_melt_elmt_mvchisq_, 7},
    {"_melt_elmt_statistic_", (DL_FUNC) &_melt_elmt_statistic_, 14},
    {"_melt_elt_", (DL_FUNC) &_melt_elt_, 12},
    {"_melt_eval_", (DL_FUNC) &_melt_eval_, 7},
    {"_melt_eval_g_", (DL_FUNC) &_melt_eval_g_, 5},
    {"_melt_glm_", (DL_FUNC) &_melt_glm_, 12},
    {"_melt_lm_", (DL_FUNC) &_melt_lm_, 11},
    {NULL, NULL, 0}
};

RcppExport void R_init_melt(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
