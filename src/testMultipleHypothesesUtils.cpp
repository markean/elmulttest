#include "testMultipleHypothesesUtils.h"
#include "utils.h"
#include <RcppEigen.h>
#include <functional>
#include <map>
#include <string>
#include <vector>

Eigen::RowVectorXd rmvn(const Eigen::Ref<const Eigen::MatrixXd> &sqrt) {
  Eigen::RowVectorXd u(sqrt.cols());
  for (int i = 0; i < sqrt.cols(); ++i) {
    u(i) = R::rnorm(0, 1.0);
  }
  return u * sqrt;
}

Eigen::MatrixXd w_mean(const Eigen::Ref<const Eigen::MatrixXd> &x,
                       const Eigen::Ref<const Eigen::VectorXd> &est) {
  return Eigen::MatrixXd::Identity(x.cols(), x.cols());
}
Eigen::MatrixXd w_lm(const Eigen::Ref<const Eigen::MatrixXd> &x,
                     const Eigen::Ref<const Eigen::VectorXd> &est) {
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  return static_cast<double>(x.rows()) * (xmat.transpose() * xmat).inverse();
}
Eigen::MatrixXd w_gaussian_log(const Eigen::Ref<const Eigen::MatrixXd> &x,
                               const Eigen::Ref<const Eigen::VectorXd> &est) {
  const Eigen::ArrayXd y = x.col(0);
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  Eigen::ArrayXd c = y * log_linkinv(xmat * est) -
    2.0 * log_linkinv(2.0 * xmat * est);
  return static_cast<double>(x.rows()) *
    (xmat.transpose() * (xmat.array().colwise() * c).matrix()).inverse();
}


Eigen::MatrixXd dg0_inv(const std::string method,
                        const Eigen::Ref<const Eigen::MatrixXd> &x,
                        const Eigen::Ref<const Eigen::VectorXd> &est) {
  std::map<std::string, std::function<Eigen::MatrixXd(
                            const Eigen::Ref<const Eigen::MatrixXd> &,
                            const Eigen::Ref<const Eigen::VectorXd> &)>>
      w_map{{{"mean", w_mean},
             {"lm", w_lm},
             {"gaussian_identity", w_lm},
             {"gaussian_log", w_gaussian_log},
             {"gaussian_inverse", w_mean},
             {"binomial_logit", w_mean},
             {"binomial_probit", w_mean},
             {"binomial_log", w_mean},
             {"poisson_log", w_mean},
             {"poisson_identity", w_mean},
             {"poisson_sqrt", w_mean},
             {"quasibinomial_logit", w_mean}}};
  return w_map[method](x, est);
}

Eigen::MatrixXd smat(const std::string method,
                     const Eigen::Ref<const Eigen::VectorXd> &est,
                     const Eigen::Ref<const Eigen::MatrixXd> &x) {
  const std::function<Eigen::MatrixXd(
      const Eigen::Ref<const Eigen::MatrixXd> &,
      const Eigen::Ref<const Eigen::VectorXd> &)>
  g_fn = g_fn2(method);
  return (1.0 / x.rows()) * ((g_fn(x, est)).transpose() * g_fn(x, est));
  // std::map<std::string, std::function<Eigen::MatrixXd(
  //                           const Eigen::Ref<const Eigen::MatrixXd> &,
  //                           const Eigen::Ref<const Eigen::VectorXd> &)>>
  //     g_map{{{"mean", g_mean},
  //            {"lm", g_lm},
  //            {"gaussian_identity", g_lm},
  //            {"gaussian_log", g_gauss_log},
  //            {"gaussian_inverse", g_gauss_inverse},
  //            {"binomial_logit", g_bin_logit},
  //            {"binomial_probit", g_bin_probit},
  //            {"binomial_log", g_bin_log},
  //            {"poisson_log", g_poi_log},
  //            {"poisson_identity", g_poi_identity},
  //            {"poisson_sqrt", g_poi_sqrt},
  //            {"quasibinomial_logit", g_bin_logit}}};
  // return (1.0 / x.rows()) *
  //        ((g_map[method](x, est)).transpose() * g_map[method](x, est));
}

Eigen::MatrixXd ahat(const Eigen::Ref<const Eigen::MatrixXd> &j,
                     const Eigen::Ref<const Eigen::MatrixXd> &w,
                     const Eigen::Ref<const Eigen::MatrixXd> &s) {
  return (j * w).transpose() * (((j * w) * s * (j * w).transpose()).inverse()) *
         (j * w);
}
