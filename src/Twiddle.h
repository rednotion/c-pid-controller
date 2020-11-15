#ifndef TWIDDLE_H
#define TWIDDLE_H

#include <vector>

class Twiddle {
 public:
  /**
   * Constructor
   */
  Twiddle();

  /**
   * Destructor.
   */
  virtual ~Twiddle();


  void Init(std::vector<double> p, std::vector<double> dp, double tol, int period);
  
  std::vector<double> Update(double steer_value, double cte);
  
 private:
  
  std::vector<double> p;
  std::vector<double> dp;
  double tol;
  int period;
  
  // for counting periods
  int n_iters;
  
  // for error initialisartion
  double total_error;
  double best_error;
  bool is_initialized;
  
  // for index tracking
  int idx;
  bool idx_pos;

};

#endif  // TWIDDLE_H