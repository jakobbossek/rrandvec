
# rrandvec: Random Vectors that sum up to one

**Visit the [package website](https://jakobbossek.github.io/rrandvec/).**

<!-- badges: start -->

[![R-CMD-check](https://github.com/jakobbossek/rrandvec/workflows/R-CMD-check/badge.svg)](https://github.com/jakobbossek/rrandvec/actions)
[![CRAN Status
Badge](http://www.r-pkg.org/badges/version/rrandvec)](https://CRAN.R-project.org/package=rrandvec)
[![CRAN
Downloads](http://cranlogs.r-pkg.org/badges/rrandvec)](https://CRAN.R-project.org/package=rrandvec)
[![CRAN
Downloads](http://cranlogs.r-pkg.org/badges/grand-total/rrandvec?color=orange)](https://CRAN.R-project.org/package=rrandvec)
[![Codecov test
coverage](https://codecov.io/gh/jakobbossek/rrandvec/branch/main/graph/badge.svg)](https://app.codecov.io/gh/jakobbossek/rrandvec?branch=main)
<!-- badges: end -->

## What is this all about?

Offers a single method to generate random vectors whose components sum
of to one. Several methods are available. The implementation is done in
C++ (via [Rcpp](https://www.rcpp.org)) for performance reasons.

## Installation Instructions

The package can be installed from [CRAN](https://cran.r-project.org). To
install the dev-version ufrom github use the
[devtools](https://github.com/r-lib/devtools) package and type the
following command in R:

``` r
devtools::install_github("jakobbossek/rrandvec")
```

## Example

Assume we aim to generate `n=250` vectors in `d=3` dimensions where the
components of each vector follow the same distribution. This can be
achieved, e.g., by the following command:

``` r
library(rrandvec)
library(scatterplot3d)
x = rrandvec(n = 250, d = 3, method = "exponential")
scatterplot3d(x[, 1:3], angle = 120, pch = 4, color = "blue", cex.symbols = 0.7, xlab = expression(x[1]), ylab = expression(x[2]), zlab = expression(x[3]))
```

## Contact

To report bugs or ask questions please use the [issue
tracker](https://github.com/jakobbossek/rrandvec/issues). Pay attention
to explain the problem as good as possible. At its best you provide an
example, so I can reproduce your problem quickly.
