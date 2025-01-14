#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
   this->Kp = Kp_;
   this->Ki = Ki_;
   this->Kd = Kd_;
   this->p_error = 0;
   this->i_error = 0;
   this->d_error = 0;
	
}
void PID::SetParam(double Kp_, double Ki_, double Kd_)
{
   this->Kp = Kp_;
   this->Ki = Ki_;
   this->Kd = Kd_;
}
void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */  
  d_error = cte-p_error;
  p_error = cte;
  i_error = i_error+cte;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  
  double steer = -1*p_error*Kp-d_error*Kd-i_error*Ki;
  if (steer < -1) {
    steer = -1;
  }
  if (steer > 1) {
    steer = 1;
  }
  return steer;  // TODO: Add your total error calc here!
}