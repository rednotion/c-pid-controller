#ifndef PID_H
#define PID_H
#include <vector>

class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_,
            std::vector<double> p, std::vector<double> dp, double tol, int period);
  
  // void SetParams(double Kp_, double Ki_, double Kd_);
  void TwiddleUpdate(double steer_value, double cte);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();
  
 private:
  /**
   * PID Errors
   */
  double p_error;
  double i_error;
  double d_error;
  
  double prev_cte;
  /**
   * PID Coefficients
   */ 
  double Kp;
  double Ki;
  double Kd;
  
  // for twiddle
  std::vector<double> p;
  std::vector<double> dp;
  double tol;
  int period;
  double total_error;
  double best_error;
  bool is_initialized;
  int n_iters;
  int idx;
  bool idx_pos;
};

#endif  // PID_H