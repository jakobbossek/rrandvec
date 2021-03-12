#' @title Generate pseudo-random discrete probability distributions.
#'
#' @description Generate an \eqn{n \times d} matrix. Each row vector is a
#' probability vector \eqn{(p_1, \ldots, p_d)} with \eqn{\sum_{i=1}^{d} p_i = 1}.
#' The function offers several methods to generate the rows in a way that the
#' components are unbiased which means that they are required to have similar
#' probability distributions.
#'
#' @param n [\code{integer(1)}]\cr
#'   Number of vectors to generate.
#' @param d [\code{integer(1)}]\cr
#'   Number of components of each vector (at least 2).
#' @param method [\code{character(1)}]\cr
#'   One of \dQuote{norm} (normalization method), \dQuote{trigonometric},
#'   \dQuote{simplex} (sample from a unit simplex) or \dQuote{iterative}.
#'   Default is \code{simplex}.
#' @param shuffle [\code{logical(1)}]\cr
#'   Should the values of each vector be permutatet randomly?
#'   Background: methods \dQuote{iterative} and \dQuote{trigonometric} introduce
#'   unwanted bias (see desciption). This issue can be alliviated by random
#'   shuffling.
#'   Default is \code{FALSE}.
#' @param as.df [\code{logical(1)}]\cr
#'   Should the return value be a data frame with column names X1 to Xd?
#'   Default is \code{FALSE}.
#' @return [\code{matrix(n, d)}] \eqn{(n \times d)} matrix even if \eqn{n=1}.
#' @examples
#' R = rrpv(10, 2)
#' R = rrpv(10, 5, method ="iterative")
#' R = rrpv(10, 3, method = "trigonometric", shuffle = TRUE, as.df = TRUE)
#' \dontrun{
#' opar = par(mfrow = c(1, 3))
#' plot.ecdf(R$X1)
#' plot.ecdf(R$X2)
#' plot.ecdf(R$X3)
#' par(opar)
#' }
#' @export
rrpv = function(n, d, method = "normalization", shuffle = FALSE, as.df = FALSE) {
  n = checkmate::asInt(n, lower = 1L)
  d = checkmate::asInt(d, lower = 2L)
  checkmate::assert_choice(method, choices = c("normalization", "trigonometric", "simplex", "iterative"))
  checkmate::assert_flag(shuffle)
  checkmate::assert_flag(as.df)

  # construct name of C-method: rrpv_<method>_C
  fun = match.fun(paste0("rrpv_", method, "_C"))
  rpvs = fun(n, d)

  #FIXME: this is ugly. Could we modify the C generation code?
  if (shuffle) {
    rpvs = do.call(rbind, lapply(1:nrow(rpvs), function(i) {
      sample(rpvs[i, ])
    }))
  }

  if (as.df) {
    rpvs = as.data.frame(rpvs, stringsAsFactors = FALSE)
    colnames(rpvs) = paste0("X", 1:ncol(rpvs))
  }

  return(rpvs)
}
