#include "PID.h"
#include <vector>
#include <iostream>

using std::vector;

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_,
              vector<double> p, vector<double> dp, double tol, int period) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  prev_cte = 0.0;
  
  // for twiddle
  p = p;
  dp = dp;
  tol = tol;
  period = period;
  total_error = 0.0;
  best_error = 0.0;
  is_initialized = false;
  
  n_iters = 0;
  idx = 0;
  idx_pos = true;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  p_error = cte;
  i_error += cte;
  d_error = cte - prev_cte;
  
  // keep cte for next calculation
  prev_cte = cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  double steer = -Kp*p_error - Ki*i_error - Kd*d_error;
  return steer;
}

void PID::TwiddleUpdate(double steer_value, double cte) {
  //double sum_dp = dp[0] + dp[1] + dp[2];

  if (n_iters < period) {
    total_error += cte*cte;
    n_iters += 1;
    std::cout<<"At iter "<<n_iters<<" adding to CTE"<<std::endl;
  }
//   } else if (sum_dp > tol) {
//     if (!is_initialized) {
//       best_error = total_error / period;
//       is_initialized = true;
//     } else {
//       if (steer_value < best_error) {
//         // best case: update error & delta, switch index
//         best_error = steer_value;
//         dp[idx] *= 1.1;
//         idx = (idx + 1)%3;
//         idx_pos = true;
//       } else {
//         if (idx_pos == true) {
//           // stay on the same index but switch directions & try again
//           p[idx] -= 2*dp[idx];
//           idx_pos = false;
//         } else {
//           // reset p, lower delta and switch index
//           p[idx] += dp[idx];
//           dp[idx] *= 0.9;
//           idx = (idx+1)%3;
//           idx_pos = true;
//         }
//       }
//     }
//   } else {
//      std::cout<<"We have reached below tol.. ending twiddle"<<std::endl;
//   }
//   // reset
//   n_iters = 0;
//   if (sum_dp > tol) {
//     std::cout<<"Setting params as "<<p[0]<<","<<p[1]<<","<<p[2]<<std::endl;
//   }
  
  Kp = p[0];
  Ki = p[1];
  Kd = p[2];
}