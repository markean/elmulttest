// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppEigen.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// max_threads_
int max_threads_();
RcppExport SEXP _melt_max_threads_() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(max_threads_());
    return rcpp_result_gen;
END_RCPP
}
// get_rank_
int get_rank_(const Eigen::Map<Eigen::MatrixXd>& x);
RcppExport SEXP _melt_get_rank_(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd>& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(get_rank_(x));
    return rcpp_result_gen;
END_RCPP
}
// confint_
Eigen::MatrixXd confint_(const std::string method, const Eigen::Map<Eigen::VectorXd>& par0, const Eigen::Map<Eigen::MatrixXd>& x, const double cutoff, const Rcpp::IntegerVector& idx, const int maxit, const int maxit_l, const double tol, const double tol_l, const Rcpp::Nullable<double> th, const int nthreads, const Rcpp::Nullable<const Eigen::Map<const Eigen::ArrayXd>&> wt);
RcppExport SEXP _melt_confint_(SEXP methodSEXP, SEXP par0SEXP, SEXP xSEXP, SEXP cutoffSEXP, SEXP idxSEXP, SEXP maxitSEXP, SEXP maxit_lSEXP, SEXP tolSEXP, SEXP tol_lSEXP, SEXP thSEXP, SEXP nthreadsSEXP, SEXP wtSEXP) {
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
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type th(thSEXP);
    Rcpp::traits::input_parameter< const int >::type nthreads(nthreadsSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<const Eigen::Map<const Eigen::ArrayXd>&> >::type wt(wtSEXP);
    rcpp_result_gen = Rcpp::wrap(confint_(method, par0, x, cutoff, idx, maxit, maxit_l, tol, tol_l, th, nthreads, wt));
    return rcpp_result_gen;
END_RCPP
}
// eld_
Rcpp::NumericVector eld_(const std::string method, const Eigen::Map<Eigen::VectorXd>& par0, const Eigen::Map<Eigen::MatrixXd>& x, const int maxit_l, const double tol_l, const Rcpp::Nullable<double> th, const int nthreads, const Rcpp::Nullable<const Eigen::Map<const Eigen::ArrayXd>&> wt);
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
    Rcpp::traits::input_parameter< const Rcpp::Nullable<const Eigen::Map<const Eigen::ArrayXd>&> >::type wt(wtSEXP);
    rcpp_result_gen = Rcpp::wrap(eld_(method, par0, x, maxit_l, tol_l, th, nthreads, wt));
    return rcpp_result_gen;
END_RCPP
}
// eval_
Rcpp::List eval_(const std::string method, const Eigen::Map<Eigen::VectorXd>& par0, const Eigen::Map<Eigen::MatrixXd>& x, const int maxit_l, const double tol_l, const Rcpp::Nullable<double> th, const Rcpp::Nullable<const Eigen::Map<const Eigen::ArrayXd>&> wt);
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
    Rcpp::traits::input_parameter< const Rcpp::Nullable<const Eigen::Map<const Eigen::ArrayXd>&> >::type wt(wtSEXP);
    rcpp_result_gen = Rcpp::wrap(eval_(method, par0, x, maxit_l, tol_l, th, wt));
    return rcpp_result_gen;
END_RCPP
}
// eval_g_
Rcpp::List eval_g_(const Eigen::Map<Eigen::MatrixXd>& g, const int maxit_l, const double tol_l, const Rcpp::Nullable<double> th, const Rcpp::Nullable<const Eigen::Map<const Eigen::ArrayXd>&> wt);
RcppExport SEXP _melt_eval_g_(SEXP gSEXP, SEXP maxit_lSEXP, SEXP tol_lSEXP, SEXP thSEXP, SEXP wtSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd>& >::type g(gSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit_l(maxit_lSEXP);
    Rcpp::traits::input_parameter< const double >::type tol_l(tol_lSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type th(thSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<const Eigen::Map<const Eigen::ArrayXd>&> >::type wt(wtSEXP);
    rcpp_result_gen = Rcpp::wrap(eval_g_(g, maxit_l, tol_l, th, wt));
    return rcpp_result_gen;
END_RCPP
}
// ELtest
Rcpp::List ELtest(const Eigen::MatrixXd& x, const Eigen::MatrixXd& c, const Eigen::MatrixXd& lhs, const Eigen::VectorXd& rhs, const double threshold, const int maxit, const double abstol);
RcppExport SEXP _melt_ELtest(SEXP xSEXP, SEXP cSEXP, SEXP lhsSEXP, SEXP rhsSEXP, SEXP thresholdSEXP, SEXP maxitSEXP, SEXP abstolSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type c(cSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type lhs(lhsSEXP);
    Rcpp::traits::input_parameter< const Eigen::VectorXd& >::type rhs(rhsSEXP);
    Rcpp::traits::input_parameter< const double >::type threshold(thresholdSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit(maxitSEXP);
    Rcpp::traits::input_parameter< const double >::type abstol(abstolSEXP);
    rcpp_result_gen = Rcpp::wrap(ELtest(x, c, lhs, rhs, threshold, maxit, abstol));
    return rcpp_result_gen;
END_RCPP
}
// glm_
Rcpp::List glm_(const std::string family, const std::string link, const Eigen::Map<Eigen::MatrixXd>& x, const Eigen::Map<Eigen::VectorXd>& par0, const bool intercept, const int maxit, const int maxit_l, const double tol, const double tol_l, const Rcpp::Nullable<double> th, const int nthreads, const Rcpp::Nullable<const Eigen::Map<const Eigen::ArrayXd>&> wt);
RcppExport SEXP _melt_glm_(SEXP familySEXP, SEXP linkSEXP, SEXP xSEXP, SEXP par0SEXP, SEXP interceptSEXP, SEXP maxitSEXP, SEXP maxit_lSEXP, SEXP tolSEXP, SEXP tol_lSEXP, SEXP thSEXP, SEXP nthreadsSEXP, SEXP wtSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string >::type family(familySEXP);
    Rcpp::traits::input_parameter< const std::string >::type link(linkSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::MatrixXd>& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::VectorXd>& >::type par0(par0SEXP);
    Rcpp::traits::input_parameter< const bool >::type intercept(interceptSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit(maxitSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit_l(maxit_lSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const double >::type tol_l(tol_lSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type th(thSEXP);
    Rcpp::traits::input_parameter< const int >::type nthreads(nthreadsSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<const Eigen::Map<const Eigen::ArrayXd>&> >::type wt(wtSEXP);
    rcpp_result_gen = Rcpp::wrap(glm_(family, link, x, par0, intercept, maxit, maxit_l, tol, tol_l, th, nthreads, wt));
    return rcpp_result_gen;
END_RCPP
}
// lht_
Rcpp::List lht_(const std::string method, const Eigen::Map<Eigen::VectorXd>& par0, const Eigen::Map<Eigen::MatrixXd>& x, const Eigen::Map<Eigen::MatrixXd>& lhs, const Eigen::Map<Eigen::VectorXd>& rhs, const int maxit, const int maxit_l, const double tol, const double tol_l, const Rcpp::Nullable<double> th, const Eigen::Map<Eigen::ArrayXd>& wt);
RcppExport SEXP _melt_lht_(SEXP methodSEXP, SEXP par0SEXP, SEXP xSEXP, SEXP lhsSEXP, SEXP rhsSEXP, SEXP maxitSEXP, SEXP maxit_lSEXP, SEXP tolSEXP, SEXP tol_lSEXP, SEXP thSEXP, SEXP wtSEXP) {
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
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type th(thSEXP);
    Rcpp::traits::input_parameter< const Eigen::Map<Eigen::ArrayXd>& >::type wt(wtSEXP);
    rcpp_result_gen = Rcpp::wrap(lht_(method, par0, x, lhs, rhs, maxit, maxit_l, tol, tol_l, th, wt));
    return rcpp_result_gen;
END_RCPP
}
// lm_
Rcpp::List lm_(const Eigen::Map<Eigen::MatrixXd>& x, const Eigen::Map<Eigen::VectorXd>& par0, const bool intercept, const int maxit, const int maxit_l, const double tol, const double tol_l, const Rcpp::Nullable<double> th, const int nthreads, const Rcpp::Nullable<const Eigen::Map<const Eigen::ArrayXd>&> wt);
RcppExport SEXP _melt_lm_(SEXP xSEXP, SEXP par0SEXP, SEXP interceptSEXP, SEXP maxitSEXP, SEXP maxit_lSEXP, SEXP tolSEXP, SEXP tol_lSEXP, SEXP thSEXP, SEXP nthreadsSEXP, SEXP wtSEXP) {
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
    Rcpp::traits::input_parameter< const Rcpp::Nullable<double> >::type th(thSEXP);
    Rcpp::traits::input_parameter< const int >::type nthreads(nthreadsSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Nullable<const Eigen::Map<const Eigen::ArrayXd>&> >::type wt(wtSEXP);
    rcpp_result_gen = Rcpp::wrap(lm_(x, par0, intercept, maxit, maxit_l, tol, tol_l, th, nthreads, wt));
    return rcpp_result_gen;
END_RCPP
}
// pairwise
Rcpp::List pairwise(const Eigen::MatrixXd& x, const Eigen::MatrixXd& c, const int control, const int k, const double level, const bool interval, const std::string method, const int B, const int nthread, const bool progress, const double threshold, const int maxit, const double abstol);
RcppExport SEXP _melt_pairwise(SEXP xSEXP, SEXP cSEXP, SEXP controlSEXP, SEXP kSEXP, SEXP levelSEXP, SEXP intervalSEXP, SEXP methodSEXP, SEXP BSEXP, SEXP nthreadSEXP, SEXP progressSEXP, SEXP thresholdSEXP, SEXP maxitSEXP, SEXP abstolSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type c(cSEXP);
    Rcpp::traits::input_parameter< const int >::type control(controlSEXP);
    Rcpp::traits::input_parameter< const int >::type k(kSEXP);
    Rcpp::traits::input_parameter< const double >::type level(levelSEXP);
    Rcpp::traits::input_parameter< const bool >::type interval(intervalSEXP);
    Rcpp::traits::input_parameter< const std::string >::type method(methodSEXP);
    Rcpp::traits::input_parameter< const int >::type B(BSEXP);
    Rcpp::traits::input_parameter< const int >::type nthread(nthreadSEXP);
    Rcpp::traits::input_parameter< const bool >::type progress(progressSEXP);
    Rcpp::traits::input_parameter< const double >::type threshold(thresholdSEXP);
    Rcpp::traits::input_parameter< const int >::type maxit(maxitSEXP);
    Rcpp::traits::input_parameter< const double >::type abstol(abstolSEXP);
    rcpp_result_gen = Rcpp::wrap(pairwise(x, c, control, k, level, interval, method, B, nthread, progress, threshold, maxit, abstol));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_melt_max_threads_", (DL_FUNC) &_melt_max_threads_, 0},
    {"_melt_get_rank_", (DL_FUNC) &_melt_get_rank_, 1},
    {"_melt_confint_", (DL_FUNC) &_melt_confint_, 12},
    {"_melt_eld_", (DL_FUNC) &_melt_eld_, 8},
    {"_melt_eval_", (DL_FUNC) &_melt_eval_, 7},
    {"_melt_eval_g_", (DL_FUNC) &_melt_eval_g_, 5},
    {"_melt_ELtest", (DL_FUNC) &_melt_ELtest, 7},
    {"_melt_glm_", (DL_FUNC) &_melt_glm_, 12},
    {"_melt_lht_", (DL_FUNC) &_melt_lht_, 11},
    {"_melt_lm_", (DL_FUNC) &_melt_lm_, 10},
    {"_melt_pairwise", (DL_FUNC) &_melt_pairwise, 13},
    {NULL, NULL, 0}
};

RcppExport void R_init_melt(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
