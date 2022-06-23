#include "elmt_utils.h"
#include "utils.h"
#include "EL.h"
#include <RcppEigen.h>
#include <map>
#include <functional>
#include <string>
#include <vector>

Eigen::RowVectorXd rmvn(const Eigen::Ref<const Eigen::MatrixXd>& sqrt) {
  Eigen::RowVectorXd u(sqrt.cols());
  for (int i = 0; i < sqrt.cols(); ++i) {
    u(i) = R::rnorm(0, 1.0);
  }
  return u * sqrt;
}

Eigen::MatrixXd w_mean(const Eigen::Ref<const Eigen::MatrixXd>& x) {
  return Eigen::MatrixXd::Identity(x.cols(), x.cols());
}
Eigen::MatrixXd w_lm(const Eigen::Ref<const Eigen::MatrixXd>& x) {
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  return static_cast<double>(x.rows()) * (xmat.transpose() * xmat).inverse();
}

Eigen::MatrixXd dg0_inv(const std::string method,
                        const Eigen::Ref<const Eigen::MatrixXd>& x) {
  std::map<std::string, std::function<Eigen::MatrixXd(
      const Eigen::Ref<const Eigen::MatrixXd>&)>>
        w_map{{{"mean", w_mean},
               {"lm", w_lm},
               {"gaussian_identity", w_lm},
               {"gaussian_log", w_mean},
               {"gaussian_inverse", w_mean},
               {"binomial_logit", w_mean},
               {"binomial_probit", w_mean},
               {"binomial_log", w_mean},
               {"poisson_log", w_mean},
               {"poisson_identity", w_mean},
               {"poisson_sqrt", w_mean},
               {"quasibinomial_logit", w_mean}}};
  return w_map[method](x);
}

Eigen::MatrixXd cov(const std::string method,
                    const Eigen::Ref<const Eigen::VectorXd>& est,
                    const Eigen::Ref<const Eigen::MatrixXd>& x) {
  //       {"binomial_logit", g_bin_logit},
  //       {"binomial_probit", g_bin_probit},
  //       {"binomial_log", g_bin_log},
  //       {"poisson_log", g_poi_log},
  //       {"poisson_identity", g_poi_identity},
  //       {"poisson_sqrt", g_poi_sqrt},
  //       {"quasibinomial_logit", g_qbin_logit}}};
  std::map<std::string, std::function<Eigen::MatrixXd(
      const Eigen::Ref<const Eigen::MatrixXd>&,
      const Eigen::Ref<const Eigen::VectorXd>&)>>
        g_map{{{"mean", g_mean},
               {"lm", g_lm},
               {"gaussian_identity", g_lm},
               {"gaussian_log", g_gauss_log},
               {"gaussian_inverse", g_gauss_inverse},
               {"binomial_logit", g_lm},
               {"binomial_probit", g_lm},
               {"binomial_log", g_lm},
               {"poisson_log", g_lm},
               {"poisson_identity", g_lm},
               {"poisson_sqrt", g_lm},
               {"quasibinomial_logit", g_lm}}};
  return (1.0 / x.rows()) *
    ((g_map[method](x, est)).transpose() * g_map[method](x, est));
}

Eigen::MatrixXd ahat(const Eigen::Ref<const Eigen::MatrixXd>& j,
                     const Eigen::Ref<const Eigen::MatrixXd>& w,
                     const Eigen::Ref<const Eigen::MatrixXd>& s) {
  return (j * w).transpose() * (((j * w) * s * (j * w).transpose()).inverse()) *
    (j * w);
}

// Rcpp::NumericVector cv_mvchisq(const std::string method,
//                   const Eigen::Ref<const Eigen::VectorXd>& est,
//                   const Eigen::Ref<const Eigen::MatrixXd>& x,
//                   const Eigen::Ref<const Eigen::MatrixXd>& lhs,
//                   const Eigen::Ref<const Eigen::VectorXi>& q,
//                   const int m,
//                   const int B,
//                   const int nthreads)
// {
//   const int p = est.size();
//   const Eigen::MatrixXd w = dg0_inv(method, x);
//   // sample covariance
//   const Eigen::MatrixXd s = cov(method, est, x);
//   // sqrt of sample covariance
//   const Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> es(s);
//   const Eigen::MatrixXd sqrt_s = es.operatorSqrt();
//
//   Eigen::MatrixXd amat(p, p * m);
//   for (int j = 0; j < m; ++j) {
//     const Eigen::MatrixXd l = lhs.middleRows(q(j), q(j + 1) - q(j));
//     amat.middleCols(j * p, p) = ahat(l, w, s);
//   }
//
//   std::vector<double> max_statistic(B);
//   // #pragma omp parallel for num_threads(nthreads)
//   for (int b = 0; b < B; ++b) {
//     const Eigen::RowVectorXd u = rmvn(sqrt_s);
//     Eigen::MatrixXd tmp = u * amat;
//     tmp.resize(p, m);
//     max_statistic[b] = (u * tmp).maxCoeff();
//   }
//   const Rcpp::NumericVector out = Rcpp::wrap(max_statistic);
//   return out;
// }