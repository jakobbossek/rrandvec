#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix rrandvec_normalization(int n, int d) {
  NumericMatrix R(n, d);

  for (int i = 0; i < n; ++i) {
    R(i, _) = runif(d);
  }

  NumericVector row_sums = rowSums(R);
  for (int i = 0; i < n; ++i) {
    R(i, _) = R(i, _) / row_sums[i];
  }

  return R;
}

// [[Rcpp::export]]
NumericMatrix rrandvec_iterative(int n, int d) {
  NumericMatrix R(n, d);

  for (int i = 0; i < n; ++i) {
    double sum = 0.0;
    for (int j = 0; j < d - 1; ++j) {
      R(i, j) = runif(1, 0, 1 - sum)[0];
      sum = sum + R(i, j);
    }
    R(i, d - 1) = 1 - sum;
  }

  return R;
}

// Sample a d-vector from the unit vector (see CGs technical report)
NumericVector rrandvec_sample_vector_from_unit_simplex(int d) {
  NumericVector unifs = runif(d - 1);
  std::sort(unifs.begin(), unifs.end());

  NumericVector unifs2(d + 1);
  unifs2[0] = 0;
  for (int i = 0; i < d - 1; ++i) {
    unifs2[i + 1] = unifs[i];
  }
  unifs2[d] = 1;

  NumericVector out(d);
  for (int i = 1; i <= d; ++i) {
    out[i - 1] = unifs2[i] - unifs2[i - 1];
  }
  return out;
}

// [[Rcpp::export]]
NumericMatrix rrandvec_simplex(int n, int d) {
  NumericMatrix R(n, d);

  for (int i = 0; i < n; ++i) {
    R(i, _) = rrandvec_sample_vector_from_unit_simplex(d);
  }

  return R;
}

// [[Rcpp::export]]
NumericMatrix rrandvec_trigonometric(int n, int d) {
  NumericMatrix R(n, d);

  for (int i = 0; i < n; ++i) {
    NumericVector ts = runif(d - 1);
    NumericVector thetas(d);
    thetas[0] = 3.1415 / 2; // pi/2
    for (int j = d - 1; j > 0; --j) {
      thetas[j] = acos(sqrt(ts[j - 1]));
    }

    for (int j = d - 1; j >= 0; --j) {
      double r = 0.0;
      r = sin(thetas[j]) * sin(thetas[j]);
      for (int k = j + 1; k < d; ++k) {
        r = r * cos(thetas[k]) * cos(thetas[k]);
      }
      R(i, j) = r;
    }
  }

  return R;
}

// [[Rcpp::export]]
NumericMatrix rrandvec_exponential(int n, int d) {
  NumericMatrix R(n, d);

  double u, s;
  for (int i = 0; i < n; ++i) {
    s = 0;
    for (int j = 0; j < d; ++j) {
      u = as<double>(runif(1)); // ((double) rand() / (RAND_MAX));
      R(i, j) = (-1) * log(1 - u);
      s += R(i, j);
    }
    for (int j = 0; j < d; ++j) {
      R(i, j) = R(i, j) / s;
    }
  }

  return R;
}
