#include "utils.h"
#include <RcppEigen.h>
#include <cfloat>
#include <cmath>
#include <functional>
#include <map>
#include <string>

std::function<Eigen::MatrixXd(const Eigen::Ref<const Eigen::MatrixXd> &,
                              const Eigen::Ref<const Eigen::VectorXd> &)>
g_fn2(const std::string method)
{
  std::map<std::string, std::function<Eigen::MatrixXd(
                            const Eigen::Ref<const Eigen::MatrixXd> &,
                            const Eigen::Ref<const Eigen::VectorXd> &)>>
      g_map{{{"mean", g_mean},
             {"lm", g_lm},
             {"gaussian_identity", g_lm},
             {"gaussian_log", g_gauss_log},
             {"gaussian_inverse", g_gauss_inverse},
             {"binomial_logit", g_bin_logit},
             {"binomial_probit", g_bin_probit},
             {"binomial_log", g_bin_log},
             {"poisson_log", g_poi_log},
             {"poisson_identity", g_poi_identity},
             {"poisson_sqrt", g_poi_sqrt}}};
  return g_map[method];
}

Eigen::ArrayXd inverse_linkinv(const Eigen::Ref<const Eigen::VectorXd> &x)
{
  return x.array().inverse();
}

Eigen::ArrayXd log_linkinv(const Eigen::Ref<const Eigen::VectorXd> &x)
{
  return exp(x.array());
}

Eigen::ArrayXd logit_linkinv(const Eigen::Ref<const Eigen::VectorXd> &x)
{
  return inverse(1.0 + exp(-x.array()));
}

Eigen::ArrayXd probit_linkinv(const Eigen::Ref<const Eigen::VectorXd> &x)
{
  Eigen::ArrayXd out(x.size());
  for (int i = 0; i < x.size(); ++i)
  {
    out[i] = 0.5 * std::erfc(-x[i] * M_SQRT1_2);
  }
  return out;
}

Eigen::VectorXd mele_mean(const Eigen::Ref<const Eigen::MatrixXd> &x,
                          const Eigen::Ref<const Eigen::ArrayXd> &w)
{
  if (w.size() == 0)
  {
    return x.colwise().mean();
  }
  else
  {
    return (w.matrix().transpose() * x) / x.rows();
  }
}

Eigen::VectorXd mele_sd(const Eigen::Ref<const Eigen::MatrixXd> &x,
                        const Eigen::Ref<const Eigen::ArrayXd> &w)
{
  if (w.size() == 0)
  {
    return (x.colwise().mean()).array().sqrt();
  }
  else
  {
    return ((w.matrix().transpose() * x) / x.rows()).array().sqrt();
  }
}

Eigen::VectorXd mele_lm(const Eigen::Ref<const Eigen::MatrixXd> &x,
                        const Eigen::Ref<const Eigen::ArrayXd> &w)
{
  const Eigen::VectorXd y = x.col(0);
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  if (w.size() == 0)
  {
    return xmat.colPivHouseholderQr().solve(y);
  }
  else
  {
    const Eigen::MatrixXd wsqrt =
        Eigen::MatrixXd(w.sqrt().matrix().asDiagonal());
    return (wsqrt * xmat).colPivHouseholderQr().solve(wsqrt * y);
  }
}

Eigen::MatrixXd g_mean(const Eigen::Ref<const Eigen::MatrixXd> &x,
                       const Eigen::Ref<const Eigen::VectorXd> &par)
{
  return x.rowwise() - par.transpose();
}

Eigen::VectorXd gr_nloglr_mean(const Eigen::Ref<const Eigen::VectorXd> &l,
                               const Eigen::Ref<const Eigen::MatrixXd> &g,
                               const Eigen::Ref<const Eigen::MatrixXd> &x,
                               const Eigen::Ref<const Eigen::VectorXd> &par,
                               const Eigen::Ref<const Eigen::ArrayXd> &w,
                               const bool weighted)
{
  Eigen::ArrayXd c(x.rows());
  if (weighted)
  {
    c = w * inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array());
  }
  else
  {
    c = inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array());
  }
  return -c.sum() * l;
}

Eigen::MatrixXd g_sd(const Eigen::Ref<const Eigen::MatrixXd> &x,
                     const Eigen::Ref<const Eigen::VectorXd> &par)
{
  return x.rowwise() - par.array().square().matrix().transpose();
}

Eigen::VectorXd gr_nloglr_sd(const Eigen::Ref<const Eigen::VectorXd> &l,
                             const Eigen::Ref<const Eigen::MatrixXd> &g,
                             const Eigen::Ref<const Eigen::MatrixXd> &x,
                             const Eigen::Ref<const Eigen::VectorXd> &par,
                             const Eigen::Ref<const Eigen::ArrayXd> &w,
                             const bool weighted)
{
  Eigen::ArrayXd c(x.rows());
  if (weighted)
  {
    c = w * inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array());
  }
  else
  {
    c = inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array());
  }
  return -2 * c.sum() * (par.array() * l.array());
}

Eigen::MatrixXd g_lm(const Eigen::Ref<const Eigen::MatrixXd> &x,
                     const Eigen::Ref<const Eigen::VectorXd> &par)
{
  return x.rightCols(x.cols() - 1).array().colwise() *
         (x.col(0) - x.rightCols(x.cols() - 1) * par).array();
}

Eigen::VectorXd gr_nloglr_lm(const Eigen::Ref<const Eigen::VectorXd> &l,
                             const Eigen::Ref<const Eigen::MatrixXd> &g,
                             const Eigen::Ref<const Eigen::MatrixXd> &x,
                             const Eigen::Ref<const Eigen::VectorXd> &par,
                             const Eigen::Ref<const Eigen::ArrayXd> &w,
                             const bool weighted)
{
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  Eigen::ArrayXd c(x.rows());
  if (weighted)
  {
    c = w * inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array());
  }
  else
  {
    c = inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array());
  }
  return -(xmat.transpose() * (xmat.array().colwise() * c).matrix()) * l;
}

Eigen::MatrixXd g_gauss_log(const Eigen::Ref<const Eigen::MatrixXd> &x,
                            const Eigen::Ref<const Eigen::VectorXd> &par)
{
  const Eigen::ArrayXd y = x.col(0);
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  return xmat.array().colwise() *
         ((y - log_linkinv(xmat * par)) * log_linkinv(xmat * par));
}

Eigen::VectorXd gr_nloglr_gauss_log(
    const Eigen::Ref<const Eigen::VectorXd> &l,
    const Eigen::Ref<const Eigen::MatrixXd> &g,
    const Eigen::Ref<const Eigen::MatrixXd> &x,
    const Eigen::Ref<const Eigen::VectorXd> &par,
    const Eigen::Ref<const Eigen::ArrayXd> &w,
    const bool weighted)
{
  const Eigen::ArrayXd y = x.col(0);
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  Eigen::ArrayXd c = y * log_linkinv(xmat * par) -
                     2.0 * log_linkinv(2.0 * xmat * par);
  if (weighted)
  {
    c = w * inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array()) * c;
  }
  else
  {
    c = inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array()) * c;
  }
  return (xmat.transpose() * (xmat.array().colwise() * c).matrix()) * l;
}

Eigen::MatrixXd g_gauss_inverse(const Eigen::Ref<const Eigen::MatrixXd> &x,
                                const Eigen::Ref<const Eigen::VectorXd> &par)
{
  const Eigen::ArrayXd y = x.col(0);
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  return xmat.array().colwise() *
         (-(y - inverse_linkinv(xmat * par)) *
          square(inverse_linkinv(xmat * par)));
}

Eigen::VectorXd gr_nloglr_gauss_inverse(
    const Eigen::Ref<const Eigen::VectorXd> &l,
    const Eigen::Ref<const Eigen::MatrixXd> &g,
    const Eigen::Ref<const Eigen::MatrixXd> &x,
    const Eigen::Ref<const Eigen::VectorXd> &par,
    const Eigen::Ref<const Eigen::ArrayXd> &w,
    const bool weighted)
{
  const Eigen::ArrayXd y = x.col(0);
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  Eigen::ArrayXd c = cube(inverse_linkinv(xmat * par)) *
                     (2.0 * y - 3.0 * inverse_linkinv(xmat * par));
  if (weighted)
  {
    c = w * inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array()) * c;
  }
  else
  {
    c = inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array()) * c;
  }
  return (xmat.transpose() * (xmat.array().colwise() * c).matrix()) * l;
}

Eigen::MatrixXd g_bin_logit(const Eigen::Ref<const Eigen::MatrixXd> &x,
                            const Eigen::Ref<const Eigen::VectorXd> &par)
{
  const Eigen::ArrayXd y = x.col(0);
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  return xmat.array().colwise() * (y - logit_linkinv(xmat * par));
}

Eigen::VectorXd gr_nloglr_bin_logit(
    const Eigen::Ref<const Eigen::VectorXd> &l,
    const Eigen::Ref<const Eigen::MatrixXd> &g,
    const Eigen::Ref<const Eigen::MatrixXd> &x,
    const Eigen::Ref<const Eigen::VectorXd> &par,
    const Eigen::Ref<const Eigen::ArrayXd> &w,
    const bool weighted)
{
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  Eigen::ArrayXd c = -logit_linkinv(xmat * par) *
                     (1.0 - logit_linkinv(xmat * par));
  if (weighted)
  {
    c = w * inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array()) * c;
  }
  else
  {
    c = inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array()) * c;
  }
  return (xmat.transpose() * (xmat.array().colwise() * c).matrix()) * l;
}

Eigen::MatrixXd g_bin_probit(const Eigen::Ref<const Eigen::MatrixXd> &x,
                             const Eigen::Ref<const Eigen::VectorXd> &par)
{
  const Eigen::ArrayXd y = x.col(0);
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  const Eigen::ArrayXd phi = 0.5 * M_SQRT1_2 * M_2_SQRTPI *
                             exp(-0.5 * (xmat * par).array().square());
  return xmat.array().colwise() *
         ((y * inverse(probit_linkinv(xmat * par)) - 1.0) * phi);
}

Eigen::VectorXd gr_nloglr_bin_probit(
    const Eigen::Ref<const Eigen::VectorXd> &l,
    const Eigen::Ref<const Eigen::MatrixXd> &g,
    const Eigen::Ref<const Eigen::MatrixXd> &x,
    const Eigen::Ref<const Eigen::VectorXd> &par,
    const Eigen::Ref<const Eigen::ArrayXd> &w,
    const bool weighted)
{
  const Eigen::ArrayXd y = x.col(0);
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  const Eigen::ArrayXd phi = 0.5 * M_SQRT1_2 * M_2_SQRTPI *
                             exp(-0.5 * (xmat * par).array().square());
  const Eigen::ArrayXd dphi = -0.5 * M_SQRT1_2 * M_2_SQRTPI *
                              exp(-0.5 * (xmat * par).array().square()) *
                              (xmat * par).array();
  Eigen::ArrayXd c = y * (dphi * inverse(probit_linkinv(xmat * par)) -
                          square(inverse(probit_linkinv(xmat * par)) * phi)) -
                     dphi;
  if (weighted)
  {
    c = w * inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array()) * c;
  }
  else
  {
    c = inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array()) * c;
  }
  return (xmat.transpose() * (xmat.array().colwise() * c).matrix()) * l;
}

Eigen::MatrixXd g_bin_log(const Eigen::Ref<const Eigen::MatrixXd> &x,
                          const Eigen::Ref<const Eigen::VectorXd> &par)
{
  const Eigen::ArrayXd y = x.col(0);
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  return xmat.array().colwise() *
         ((inverse(DBL_EPSILON + 1.0 - log_linkinv(xmat * par))) *
          (y - log_linkinv(xmat * par)));
}

Eigen::VectorXd gr_nloglr_bin_log(
    const Eigen::Ref<const Eigen::VectorXd> &l,
    const Eigen::Ref<const Eigen::MatrixXd> &g,
    const Eigen::Ref<const Eigen::MatrixXd> &x,
    const Eigen::Ref<const Eigen::VectorXd> &par,
    const Eigen::Ref<const Eigen::ArrayXd> &w,
    const bool weighted)
{
  const Eigen::ArrayXd y = x.col(0);
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  Eigen::ArrayXd c =
      square((DBL_EPSILON + 1.0 - log_linkinv(xmat * par)).inverse()) *
      log_linkinv(xmat * par) * (y - 1.0);
  if (weighted)
  {
    c = w * inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array()) * c;
  }
  else
  {
    c = inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array()) * c;
  }
  return (xmat.transpose() * (xmat.array().colwise() * c).matrix()) * l;
}

Eigen::MatrixXd g_poi_log(const Eigen::Ref<const Eigen::MatrixXd> &x,
                          const Eigen::Ref<const Eigen::VectorXd> &par)
{
  const Eigen::ArrayXd y = x.col(0);
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  return xmat.array().colwise() * (y - log_linkinv(xmat * par));
}

Eigen::VectorXd gr_nloglr_poi_log(const Eigen::Ref<const Eigen::VectorXd> &l,
                                  const Eigen::Ref<const Eigen::MatrixXd> &g,
                                  const Eigen::Ref<const Eigen::MatrixXd> &x,
                                  const Eigen::Ref<const Eigen::VectorXd> &par,
                                  const Eigen::Ref<const Eigen::ArrayXd> &w,
                                  const bool weighted)
{
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  Eigen::ArrayXd c = -log_linkinv(xmat * par);
  if (weighted)
  {
    c = w * inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array()) * c;
  }
  else
  {
    c = inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array()) * c;
  }
  return (xmat.transpose() * (xmat.array().colwise() * c).matrix()) * l;
}

Eigen::MatrixXd g_poi_identity(const Eigen::Ref<const Eigen::MatrixXd> &x,
                               const Eigen::Ref<const Eigen::VectorXd> &par)
{
  const Eigen::ArrayXd y = x.col(0);
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  return xmat.array().colwise() * (y * inverse((xmat * par).array()) - 1.0);
}

Eigen::VectorXd gr_nloglr_poi_identity(
    const Eigen::Ref<const Eigen::VectorXd> &l,
    const Eigen::Ref<const Eigen::MatrixXd> &g,
    const Eigen::Ref<const Eigen::MatrixXd> &x,
    const Eigen::Ref<const Eigen::VectorXd> &par,
    const Eigen::Ref<const Eigen::ArrayXd> &w,
    const bool weighted)
{
  const Eigen::ArrayXd y = x.col(0);
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  Eigen::ArrayXd c = -y * square(inverse((xmat * par).array()));
  if (weighted)
  {
    c = w * inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array()) * c;
  }
  else
  {
    c = inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array()) * c;
  }
  return (xmat.transpose() * (xmat.array().colwise() * c).matrix()) * l;
}

Eigen::MatrixXd g_poi_sqrt(const Eigen::Ref<const Eigen::MatrixXd> &x,
                           const Eigen::Ref<const Eigen::VectorXd> &par)
{
  const Eigen::ArrayXd y = x.col(0);
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  return xmat.array().colwise() *
         (2.0 * y * inverse((xmat * par).array()) - 2.0 * (xmat * par).array());
}

Eigen::VectorXd gr_nloglr_poi_sqrt(const Eigen::Ref<const Eigen::VectorXd> &l,
                                   const Eigen::Ref<const Eigen::MatrixXd> &g,
                                   const Eigen::Ref<const Eigen::MatrixXd> &x,
                                   const Eigen::Ref<const Eigen::VectorXd> &par,
                                   const Eigen::Ref<const Eigen::ArrayXd> &w,
                                   const bool weighted)
{
  const Eigen::ArrayXd y = x.col(0);
  const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
  Eigen::ArrayXd c =
      -2.0 * (y * square(((xmat * par).array().inverse()))) - 2.0;
  if (weighted)
  {
    c = w * inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array()) * c;
  }
  else
  {
    c = inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array()) * c;
  }
  return (xmat.transpose() * (xmat.array().colwise() * c).matrix()) * l;
}

// // quasibinomial family
// Eigen::MatrixXd g_qbin_logit(const Eigen::Ref<const Eigen::MatrixXd>& x,
//                              const Eigen::Ref<const Eigen::VectorXd>& par) {
//   const double n = static_cast<double>(x.rows());
//   const int p = x.cols() - 1;
//   const Eigen::VectorXd beta = par.head(p);
//   const double phi = par(p);
//   const Eigen::ArrayXd y = x.col(0);
//   const Eigen::MatrixXd xmat = x.rightCols(p);
//
//   Eigen::MatrixXd out(x.rows(), p + 1);
//   out.leftCols(p) = xmat.array().colwise() *
//     (y - logit_linkinv(xmat * beta));
//   // out.leftCols(p) =std::pow(n, -8) *(xmat.array().colwise() *
//   //   (y - logit_linkinv(xmat * beta)));
//   // out.leftCols(p) = xmat.array().colwise() *
//   //   (1.0 / phi * (y - logit_linkinv(xmat * beta)));
//   // out.rightCols(1) = square(y - logit_linkinv(xmat * beta)) *
//   //   inverse(phi * phi * logit_linkinv(xmat * beta) *
//   //   (1.0 - logit_linkinv(xmat * beta))) - 1.0 / phi;
//
//   out.col(p) = inverse(phi * phi * logit_linkinv(xmat * beta) *
//     (1.0 - logit_linkinv(xmat * beta))) *
//     square(y - logit_linkinv(xmat * beta)) - 1.0 / phi;
//   // out.col(p) = out.col(p) / 20.0;
//   // out.col(p) = inverse(logit_linkinv(xmat * beta) *
//   //   (1.0 - logit_linkinv(xmat * beta))) *
//   //   square(y - logit_linkinv(xmat * beta)) - phi;
//   return out;
// }
// Eigen::VectorXd gr_nloglr_qbin_logit(
//     const Eigen::Ref<const Eigen::VectorXd>& l,
//     const Eigen::Ref<const Eigen::MatrixXd>& g,
//     const Eigen::Ref<const Eigen::MatrixXd>& x,
//     const Eigen::Ref<const Eigen::VectorXd>& par,
//     const Eigen::Ref<const Eigen::ArrayXd>& w,
//     const bool weighted) {
//   const int p = x.cols() - 1;
//   const Eigen::VectorXd beta = par.head(p);
//   const double phi = par(p);
//   const Eigen::ArrayXd y = x.col(0);
//   const Eigen::MatrixXd xmat = x.rightCols(x.cols() - 1);
//   Eigen::ArrayXd c(x.rows());
//   if (weighted) {
//     c = w * inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array());
//   } else {
//     c = inverse((Eigen::VectorXd::Ones(g.rows()) + g * l).array());
//   }
//
//   Eigen::ArrayXd c2 = inverse(phi * phi * logit_linkinv(xmat * beta) *
//     (1.0 - logit_linkinv(xmat * beta))) *
//     (square(logit_linkinv(xmat * beta)) * (1.0 - 2.0 * y) +
//     square(y) * (2.0 * logit_linkinv(xmat * beta) - 1.0));
//
//   Eigen::MatrixXd out = Eigen::MatrixXd::Zero(p + 1, p + 1);
//   out.topLeftCorner(p, p) = xmat.transpose() *
//     (xmat.array().colwise() * c).matrix();
//   out.bottomLeftCorner(1, p) = (xmat.array().colwise() * c2).colwise().sum();
//   out.topRightCorner(p, 1) =
//     (xmat.array().colwise() * c2).colwise().sum().transpose();
//   out(p, p) = (c * (-2.0 * logit_linkinv(xmat * beta) *
//     (1.0 - logit_linkinv(xmat * beta)) *
//     square(y - logit_linkinv(xmat * beta)) * std::pow(phi, -3) +
//     std::pow(phi, -2))).sum();
//   return out * l;
// }
