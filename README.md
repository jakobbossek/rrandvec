
# randvec: Random Vectors that sum up to one

**Visit the [package website](https://jakobbossek.github.io/randvec/).**

<!-- badges: start -->

[![R-CMD-check](https://github.com/jakobbossek/randvec/workflows/R-CMD-check/badge.svg)](https://github.com/jakobbossek/randvec/actions)
[![CRAN Status
Badge](http://www.r-pkg.org/badges/version/randvec)](https://CRAN.R-project.org/package=randvec)
[![CRAN
Downloads](http://cranlogs.r-pkg.org/badges/randvec)](https://CRAN.R-project.org/package=randvec)
[![CRAN
Downloads](http://cranlogs.r-pkg.org/badges/grand-total/randvec?color=orange)](https://CRAN.R-project.org/package=randvec)
[![Codecov test
coverage](https://codecov.io/gh/jakobbossek/randvec/branch/main/graph/badge.svg)](https://app.codecov.io/gh/jakobbossek/randvec?branch=main)
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
devtools::install_github("jakobbossek/randvec")
```

## Example

Assume we aim to generate `n=250` vectors in `d=3` dimensions where the
components of each vector follow the same distribution. This can be
achieved, e.g., by the following command:

``` r
library(randvec)
library(scatterplot3d)
x = randvec(n = 250, d = 3, method = "exponential")
scatterplot3d(x[, 1:3], angle = 120, pch = 4, color = "blue", cex.symbols = 0.7, xlab = expression(x[1]), ylab = expression(x[2]), zlab = expression(x[3]))
```

## Contact

To report bugs or ask questions please use the [issue
tracker](https://github.com/jakobbossek/randvec/issues). Pay attention
to explain the problem as good as possible. At its best you provide an
example, so I can reproduce your problem quickly.
