#include "Twiddle.h"
#include <iostream>
#include <vector>

using std::vector;

Twiddle::Twiddle() {}

Twiddle::~Twiddle() {}

void Twiddle::Init(vector<double> p, vector<double> dp, double tol, int period) {
  /**
   * TODO: Initialize Twiddle coefficients (and errors, if needed)
   */
  p = p;
  dp = dp;
  tol = tol;
  period = period;
  
  // for counting periods
  n_iters = 0;
  
  // for error initialisartion
  total_error = 0.0;
  best_error = 0.0;
  is_initialized = false;
  
  // for index tracking
  idx = 0;
  idx_pos = true;
}

vector<double> Twiddle::Update(double steer_value, double cte) {
  
  double sum_dp = dp[0] + dp[1] + dp[2];

  if (n_iters < period) {
    total_error += cte*cte;
    n_iters += 1
  } else if (sum_dp > tol) {
    if (!is_initialized) {
      best_error = total_error / period;
      is_initialized = true;
    } else {
      if (steer_value < best_error) {
        // best case: update error & delta, switch index
        best_error = steer_value;
        dp[idx] *= 1.1;
        idx = (idx + 1)%3;
        idx_pos = true;
      } else {
        if (idx_pos == true) {
          // stay on the same index but switch directions & try again
          p[idx] -= 2*dp[idx];
          idx_pos = false;
        } else {
          // reset p, lower delta and switch index
          p[idx] += dp[idx];
          dp[idx] *= 0.9;
          idx = (idx+1)%3;
          idx_pos = true;
        }
      }
    } else {
      std::cout<<"We have reached below tol.. ending twiddle"<<std::endl;
    }
    // reset
    n_iters = 0;
    if (sum_dp > tol) {
      std::cout<<"Setting params as "<<p[0]<<","<<p[1]<<","<<p[2]<<std::endl;
    }
  }
  return p;
}