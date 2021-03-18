# rpv: Random Probability Vectors

[![CRAN Status Badge](http://www.r-pkg.org/badges/version/rpv)](http://cran.r-project.org/web/packages/rpv)
[![CRAN Downloads](http://cranlogs.r-pkg.org/badges/rpv)](http://cran.rstudio.com/web/packages/rpv/index.html)
[![CRAN Downloads](http://cranlogs.r-pkg.org/badges/grand-total/rpv?color=orange)](http://cran.rstudio.com/web/packages/rpv/index.html)
[![Build Status](https://travis-ci.org/jakobbossek/rpv.svg?branch=master)](https://travis-ci.org/jakobbossek/rpv)
[![Build status](https://ci.appveyor.com/api/projects/status/eu0nns2dsgocwntw/branch/master?svg=true)](https://ci.appveyor.com/project/jakobbossek/rpv/branch/master)
[![Coverage Status](https://coveralls.io/repos/github/jakobbossek/rpv/badge.svg?branch=master)](https://coveralls.io/github/jakobbossek/rpv?branch=master)

## What is this all about?

Offers a single method to generate random probability distributions. Several methods are available. The implementation of most methods is based on Rcpp for performance reasons.

## Installation Instructions

The package will be available at [CRAN](http://cran.r-project.org) when it is done. Install the developer version using [devtools](https://github.com/hadley/ddevtools) package and type the following command in R:

```r
devtools::install_github("jakobbossek/rpv")
```

## Example

Assume we aim to generate `n=250` vectors in `d=3` dimensions where the components of each vector follow the same distribution. This can be achieved, e.g., by the following command:

```{r}
library(rpv)
library(scatterplot3d)
x = rpv(n = 250, d = 3, method = "exponential")
scatterplot3d(x[,1:3], angle = 120, pch = 4, color = "blue", cex.symbols = 0.7,
, xlab = expression(x[1]), ylab = expression(x[2]), zlab = expression(x[3]))
```

## Contact

Please address questions and missing features about the **re** to the author Jakob Bossek <j.bossek@gmail.com>. Found some nasty bugs? Please use the [issue tracker](https://github.com/jakobbossek/rpv/issues) for this. Pay attention to explain the problem as good as possible. At its best you provide an example, so I can reproduce your problem quickly.



