#include "methods.h"

// [[Rcpp::export]]
Eigen::MatrixXd EL_confint(const Eigen::Map<Eigen::MatrixXd>& x,
                           const std::string type,
                           const Eigen::Map<Eigen::VectorXd>& init,
                           const double cutoff,
                           const std::vector<int>& idx,
                           const int maxit,
                           const double abstol) {
  const int p = idx.size();
  std::vector<double> ci_vec;
  ci_vec.reserve(2 * p);
  // for (int j = 0; j < p; ++j) {
  for (int j : idx) {
    // lower endpoint
    double lower_ub = init[j - 1];
    double lower_size = 1.0;
    double lower_lb = init[j - 1] - lower_size;
    // lower bound for lower endpoint
    while (2.0 * EL2(Eigen::Matrix<double, 1, 1>(lower_lb), x, type,
                     20.0, maxit, abstol).nlogLR <= cutoff) {
      lower_ub = lower_lb;
      lower_lb -= lower_size;
    }
    // approximate lower bound by numerical search
    while (lower_ub - lower_lb > 1e-04) {
      if (2.0 * EL2(Eigen::Matrix<double, 1, 1>((lower_lb + lower_ub) / 2), x,
                    type, 20.0, maxit, abstol).nlogLR > cutoff) {
        lower_lb = (lower_lb + lower_ub) / 2;
      } else {
        lower_ub = (lower_lb + lower_ub) / 2;
      }
    }
    ci_vec.push_back(lower_lb);

    // upper endpoint
    double upper_lb = init[j - 1];
    double upper_size = 1.0;
    double upper_ub = init[j - 1] + upper_size;
    // upper bound for upper endpoint
    while (2.0 * EL2(Eigen::Matrix<double, 1, 1>(upper_ub), x, type,
                     20.0, maxit, abstol).nlogLR <= cutoff) {
      upper_lb = upper_ub;
      upper_ub += upper_size;
    }
    // approximate upper bound by numerical search
    while (upper_ub - upper_lb > 1e-04) {
      if (2.0 * EL2(Eigen::Matrix<double, 1, 1>((upper_lb + upper_ub) / 2), x,
                  type, 20.0, maxit, abstol).nlogLR > cutoff) {
        upper_ub = (upper_lb + upper_ub) / 2;
      } else {
        upper_lb = (upper_lb + upper_ub) / 2;
      }
    }
    ci_vec.push_back(upper_ub);
  }
  Eigen::MatrixXd ci =
    Eigen::Map<Eigen::MatrixXd>(ci_vec.data(), 2, p);
  return ci.transpose();
}

