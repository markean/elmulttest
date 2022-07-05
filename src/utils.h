#ifndef EL_UTILS_H_
#define EL_UTILS_H_

#include <RcppEigen.h>
#include <functional>

std::function<Eigen::MatrixXd(const Eigen::Ref<const Eigen::MatrixXd> &,
                              const Eigen::Ref<const Eigen::VectorXd> &)>
g_fn2(const std::string method);

Eigen::VectorXd mele_mean(const Eigen::Ref<const Eigen::MatrixXd> &x,
                          const Eigen::Ref<const Eigen::ArrayXd> &w);
Eigen::VectorXd mele_lm(const Eigen::Ref<const Eigen::MatrixXd> &x,
                        const Eigen::Ref<const Eigen::ArrayXd> &w);

Eigen::ArrayXd inverse_linkinv(const Eigen::Ref<const Eigen::VectorXd> &x);

Eigen::ArrayXd log_linkinv(const Eigen::Ref<const Eigen::VectorXd> &x);

Eigen::ArrayXd logit_linkinv(const Eigen::Ref<const Eigen::VectorXd> &x);

Eigen::ArrayXd probit_linkinv(const Eigen::Ref<const Eigen::VectorXd> &x);

Eigen::MatrixXd g_mean(const Eigen::Ref<const Eigen::MatrixXd> &x,
                       const Eigen::Ref<const Eigen::VectorXd> &par);

Eigen::VectorXd gr_nloglr_mean(const Eigen::Ref<const Eigen::VectorXd> &l,
                               const Eigen::Ref<const Eigen::MatrixXd> &g,
                               const Eigen::Ref<const Eigen::MatrixXd> &x,
                               const Eigen::Ref<const Eigen::VectorXd> &par,
                               const Eigen::Ref<const Eigen::ArrayXd> &w,
                               const bool weighted);

Eigen::MatrixXd g_lm(const Eigen::Ref<const Eigen::MatrixXd> &x,
                     const Eigen::Ref<const Eigen::VectorXd> &par);

Eigen::VectorXd gr_nloglr_lm(const Eigen::Ref<const Eigen::VectorXd> &l,
                             const Eigen::Ref<const Eigen::MatrixXd> &g,
                             const Eigen::Ref<const Eigen::MatrixXd> &x,
                             const Eigen::Ref<const Eigen::VectorXd> &par,
                             const Eigen::Ref<const Eigen::ArrayXd> &w,
                             const bool weighted);

// gaussian family
Eigen::MatrixXd g_gauss_log(const Eigen::Ref<const Eigen::MatrixXd> &x,
                            const Eigen::Ref<const Eigen::VectorXd> &par);

Eigen::VectorXd gr_nloglr_gauss_log(
    const Eigen::Ref<const Eigen::VectorXd> &l,
    const Eigen::Ref<const Eigen::MatrixXd> &g,
    const Eigen::Ref<const Eigen::MatrixXd> &x,
    const Eigen::Ref<const Eigen::VectorXd> &par,
    const Eigen::Ref<const Eigen::ArrayXd> &w,
    const bool weighted);

Eigen::MatrixXd g_gauss_inverse(const Eigen::Ref<const Eigen::MatrixXd> &x,
                                const Eigen::Ref<const Eigen::VectorXd> &par);

Eigen::VectorXd gr_nloglr_gauss_inverse(
    const Eigen::Ref<const Eigen::VectorXd> &l,
    const Eigen::Ref<const Eigen::MatrixXd> &g,
    const Eigen::Ref<const Eigen::MatrixXd> &x,
    const Eigen::Ref<const Eigen::VectorXd> &par,
    const Eigen::Ref<const Eigen::ArrayXd> &w,
    const bool weighted);

// binomial family
Eigen::MatrixXd g_bin_logit(const Eigen::Ref<const Eigen::MatrixXd> &x,
                            const Eigen::Ref<const Eigen::VectorXd> &par);

Eigen::VectorXd gr_nloglr_bin_logit(
    const Eigen::Ref<const Eigen::VectorXd> &l,
    const Eigen::Ref<const Eigen::MatrixXd> &g,
    const Eigen::Ref<const Eigen::MatrixXd> &x,
    const Eigen::Ref<const Eigen::VectorXd> &par,
    const Eigen::Ref<const Eigen::ArrayXd> &w,
    const bool weighted);

Eigen::MatrixXd g_bin_probit(const Eigen::Ref<const Eigen::MatrixXd> &x,
                             const Eigen::Ref<const Eigen::VectorXd> &par);

Eigen::VectorXd gr_nloglr_bin_probit(
    const Eigen::Ref<const Eigen::VectorXd> &l,
    const Eigen::Ref<const Eigen::MatrixXd> &g,
    const Eigen::Ref<const Eigen::MatrixXd> &x,
    const Eigen::Ref<const Eigen::VectorXd> &par,
    const Eigen::Ref<const Eigen::ArrayXd> &w,
    const bool weighted);

Eigen::MatrixXd g_bin_log(const Eigen::Ref<const Eigen::MatrixXd> &x,
                          const Eigen::Ref<const Eigen::VectorXd> &par);

Eigen::VectorXd gr_nloglr_bin_log(
    const Eigen::Ref<const Eigen::VectorXd> &l,
    const Eigen::Ref<const Eigen::MatrixXd> &g,
    const Eigen::Ref<const Eigen::MatrixXd> &x,
    const Eigen::Ref<const Eigen::VectorXd> &par,
    const Eigen::Ref<const Eigen::ArrayXd> &w,
    const bool weighted);

// poisson family
Eigen::MatrixXd g_poi_log(const Eigen::Ref<const Eigen::MatrixXd> &x,
                          const Eigen::Ref<const Eigen::VectorXd> &par);

Eigen::VectorXd gr_nloglr_poi_log(const Eigen::Ref<const Eigen::VectorXd> &l,
                                  const Eigen::Ref<const Eigen::MatrixXd> &g,
                                  const Eigen::Ref<const Eigen::MatrixXd> &x,
                                  const Eigen::Ref<const Eigen::VectorXd> &par,
                                  const Eigen::Ref<const Eigen::ArrayXd> &w,
                                  const bool weighted);

Eigen::MatrixXd g_poi_identity(const Eigen::Ref<const Eigen::MatrixXd> &x,
                               const Eigen::Ref<const Eigen::VectorXd> &par);

Eigen::VectorXd gr_nloglr_poi_identity(
    const Eigen::Ref<const Eigen::VectorXd> &l,
    const Eigen::Ref<const Eigen::MatrixXd> &g,
    const Eigen::Ref<const Eigen::MatrixXd> &x,
    const Eigen::Ref<const Eigen::VectorXd> &par,
    const Eigen::Ref<const Eigen::ArrayXd> &w,
    const bool weighted);

Eigen::MatrixXd g_poi_sqrt(const Eigen::Ref<const Eigen::MatrixXd> &x,
                           const Eigen::Ref<const Eigen::VectorXd> &par);

Eigen::VectorXd gr_nloglr_poi_sqrt(const Eigen::Ref<const Eigen::VectorXd> &l,
                                   const Eigen::Ref<const Eigen::MatrixXd> &g,
                                   const Eigen::Ref<const Eigen::MatrixXd> &x,
                                   const Eigen::Ref<const Eigen::VectorXd> &par,
                                   const Eigen::Ref<const Eigen::ArrayXd> &w,
                                   const bool weighted);

// quasibinomial family
// Eigen::MatrixXd g_qbin_logit(const Eigen::Ref<const Eigen::MatrixXd>& x,
//                              const Eigen::Ref<const Eigen::VectorXd>& par);
//
// Eigen::VectorXd gr_nloglr_qbin_logit(
//         const Eigen::Ref<const Eigen::VectorXd>& l,
//         const Eigen::Ref<const Eigen::MatrixXd>& g,
//         const Eigen::Ref<const Eigen::MatrixXd>& x,
//         const Eigen::Ref<const Eigen::VectorXd>& par,
//         const Eigen::Ref<const Eigen::ArrayXd>& w,
//         const bool weighted);
#endif
