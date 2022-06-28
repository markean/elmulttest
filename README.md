
<!-- README.md is generated from README.Rmd. Please edit that file -->

# melt - Multiple Empirical Likelihood Tests

<!-- badges: start -->

[![Project Status: Active - The project has reached a stable, usable
state and is being actively
developed.](https://www.repostatus.org/badges/latest/active.svg)](https://www.repostatus.org/#active)
[![CRAN
status](https://www.r-pkg.org/badges/version/melt)](https://CRAN.R-project.org/package=melt)
[![R-CMD-check](https://github.com/markean/melt/actions/workflows/check-standard.yaml/badge.svg)](https://github.com/markean/melt/actions/workflows/check-standard.yaml)
[![Codecov test
coverage](https://codecov.io/gh/markean/melt/branch/master/graph/badge.svg)](https://app.codecov.io/gh/markean/melt?branch=master)
<!-- badges: end -->

## Overview

The R package **melt** provides a unified framework for data analysis
with empirical likelihood methods. A collection of functions are
available for regression analysis and hypothesis testing. Much of its
functionality and syntax mimics the corresponding base R functions. The
core computational routines are implemented with the ‘Eigen’ C++ library
and ‘RcppEigen’ interface, with OpenMP for parallel computation.
Additional functions are available for multiple testing for the analysis
of experimental designs. Details of the testing procedures are given in
[Kim, MacEachern, and Peruggia
(2021)](https://arxiv.org/abs/2112.09206).

## Installation

You can install the latest stable release from
[CRAN](https://cran.r-project.org/package=melt).

``` r
install.packages("melt")
```

You can install the latest development version from
[Github](https://github.com/markean/melt).

``` r
# install.packages("devtools")
devtools::install_github("markean/melt")
```

## Usage

``` r
library(melt)
# one sample test for mean
fit1 <- el_mean(rnorm(n = 100), par = 0)
confint(fit1)
#>        lower     upper
#> 1 -0.2748642 0.0867665


# linear regression
fit2 <- el_lm(mpg ~ wt, data = mtcars)
summary(fit2)
#> 
#> Call:
#> el_lm(formula = mpg ~ wt, data = mtcars)
#> 
#> Coefficients:
#>             Estimate Chisq Pr(>Chisq)    
#> (Intercept)   37.285 443.3     <2e-16 ***
#> wt            -5.344 439.1     <2e-16 ***
#> ---
#> Signif. codes:  0 '***' 0.001 '**' 0.01 '*' 0.05 '.' 0.1 ' ' 1
#> 
#> Chisq: 439.1, df: 1, Pr(>Chisq): < 2.2e-16 
#> 
#> Constrained EL: not converged
confint(fit2)
#>                 lower     upper
#> (Intercept) 33.175865 41.865426
#> wt          -6.746902 -4.149511


# analysis of variance 
data("clothianidin")
fit3 <- el_lm(clo ~ -1 + trt, data = clothianidin)
summary(fit3)
#> 
#> Call:
#> el_lm(formula = clo ~ -1 + trt, data = clothianidin)
#> 
#> Coefficients:
#>              Estimate   Chisq Pr(>Chisq)    
#> trtNaked       -4.479 411.072    < 2e-16 ***
#> trtFungicide   -3.427  59.486   1.23e-14 ***
#> trtLow         -2.800  62.955   2.11e-15 ***
#> trtHigh        -1.307   4.653      0.031 *  
#> ---
#> Signif. codes:  0 '***' 0.001 '**' 0.01 '*' 0.05 '.' 0.1 ' ' 1
#> 
#> Chisq: 894.4, df: 4, Pr(>Chisq): < 2.2e-16 
#> 
#> Constrained EL: not converged
confint(fit3)
#>                  lower      upper
#> trtNaked     -5.002118 -3.9198229
#> trtFungicide -4.109816 -2.6069870
#> trtLow       -3.681837 -1.9031795
#> trtHigh      -2.499165 -0.1157222


# test of no treatment effect
lhs <- matrix(c(1, -1, 0, 0,
                0, 1, -1, 0,
                0, 0, 1, -1), byrow = TRUE, nrow = 3)
elt(fit3, lhs = lhs)
#> 
#> Empirical Likelihood Test
#> 
#> Significance level: 0.05, Calibration: Chi-square 
#> 
#> Statistic: 26.59804, Critical value: 7.814728 
#> 
#> p-value: 7.147731e-06


# logistic regression
fit4 <- el_glm(vs ~ mpg, data = mtcars, family = binomial)
summary(fit4)
#> 
#> Call:
#> el_glm(formula = vs ~ mpg, family = binomial, data = mtcars)
#> 
#> Coefficients:
#>             Estimate Chisq Pr(>Chisq)    
#> (Intercept)  -8.8331 24.79   6.39e-07 ***
#> mpg           0.4304 24.42   7.75e-07 ***
#> ---
#> Signif. codes:  0 '***' 0.001 '**' 0.01 '*' 0.05 '.' 0.1 ' ' 1
#> 
#> Chisq: 24.42, df: 1, Pr(>Chisq): 7.751e-07 
#> 
#> Constrained EL: converged
```
