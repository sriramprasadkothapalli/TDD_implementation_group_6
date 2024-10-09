#include "pid.hpp"

class PIDImpl {
 public:
  PIDImpl(float kp, float ki, float kd, float Ts, float f_c, float maxOutput);

  float update(uint16_t input);

  void setKp(float kp);

  [[nodiscard]] float getKp() const;

  void setKi(float ki);

  [[nodiscard]] float getKi() const;

  void setKd(float kd);

  [[nodiscard]] float getKd() const;

  // Set the cutoff frequency (-3 dB point) of the exponential moving average
  // filter that is applied to the input before taking the difference for
  // computing the derivative term.
  void setEMACutoff(float f_c);

  void setSetpoint(uint16_t setpoint);

  [[nodiscard]] uint16_t getSetpoint() const;

  void setMaxOutput(float maxOutput);

  [[nodiscard]] float getMaxOutput() const;

  void setActivityTimeout(float s);

  void resetIntegral();

  ~PIDImpl() = default;

 private:
  float Ts = 1;                 ///< Sampling time (seconds)
  float _maxOutput = 255;       ///< Maximum control output magnitude
  float _kp = 1;                ///< Proportional gain
  float _ki_Ts = 0;             ///< Integral gain times Ts
  float _kd_Ts = 0;             ///< Derivative gain divided by Ts
  float _emaAlpha = 1;          ///< Weight factor of derivative EMA filter.
  float _prevInput = 0;         ///< (Filtered) previous input for derivative.
  uint16_t _activityCount = 0;  ///< How many ticks since last setpoint change.
  uint16_t _activityThres = 0;  ///< Threshold for turning off the output.
  uint8_t _errThres = 1;        ///< Threshold with hysteresis.
  int32_t _integral = 0;        ///< Sum of previous errors for integral.
  uint16_t _setpoint = 0;       ///< Position reference.
};

void PIDImpl::setKp(float kp) { this->_kp = kp; }

float PIDImpl::getKp() const { return this->_kp; }

void PIDImpl::setKi(float ki) { this->_ki_Ts = ki * this->Ts; }

float PIDImpl::getKi() const { return (this->_ki_Ts / this->Ts); }

void PIDImpl::setKd(float kd) { this->_kd_Ts = kd * this->Ts; }

float PIDImpl::getKd() const { return (this->_kd_Ts / this->Ts); }

PIDImpl::PIDImpl(float kp, float ki, float kd, float Ts, float f_c,
                 float maxOutput)
    : Ts(Ts) {
  this->setMaxOutput(maxOutput);
  this->setKp(kp);
  this->setKi(ki);
  this->setKd(kd);
  this->setEMACutoff(f_c);
}

float PIDImpl::update(uint16_t input) {
  // The error is the difference between the reference (setpoint) and the
  // actual position (input)
  int16_t error = _setpoint - input;
  // The integral or sum of current and previous errors
  int32_t newIntegral = _integral + error;
  // Compute the difference between the current and the previous input,
  // but compute a weighted average using a factor α ∊ (0,1]
  float diff = _emaAlpha * (_prevInput - static_cast<float>(input));
  // Update the average
  _prevInput -= diff;

  // Standard PID rule
  float output = _kp * static_cast<float>(error) +
                 _ki_Ts * static_cast<float>(_integral) + _kd_Ts * diff;

  // Clamp and anti-windup
  if (output > _maxOutput)
    output = _maxOutput;
  else if (output < -_maxOutput)
    output = -_maxOutput;
  else
    _integral = newIntegral;

  return output;
}

void PIDImpl::setEMACutoff(float f_c) {
  float f_n = f_c * this->Ts;  // normalized sampling frequency
  this->_emaAlpha = f_c == 0 ? 1 : mathlib::calcAlphaEMA(f_n);
}

void PIDImpl::setSetpoint(uint16_t setpoint) {
  if (this->_setpoint != setpoint) this->_activityCount = 0;
  this->_setpoint = setpoint;
}

uint16_t PIDImpl::getSetpoint() const { return _setpoint; }

void PIDImpl::setMaxOutput(float maxOutput) {
  this->_maxOutput =
      mathlib::clamp(static_cast<double>(maxOutput), -255.0, 255.0);
}

float PIDImpl::getMaxOutput() const { return this->_maxOutput; }

void PIDImpl::resetIntegral() { this->_integral = 0; }

PID::PID(float kp, float ki, float kd, float Ts, float f_c, float maxOutput) {
  impl = std::make_shared<PIDImpl>(kp, ki, kd, Ts, f_c, maxOutput);
}

float PID::update(uint16_t input) const { return impl->update(input); }

void PID::setKp(float kp) const { impl->setKp(kp); }

void PID::setKi(float ki) const { impl->setKi(ki); }

void PID::setKd(float kd) const { impl->setKd(kd); }

float PID::getKp() const { return impl->getKp(); }

float PID::getKi() const { return impl->getKi(); }

float PID::getKd() const { return impl->getKd(); }

void PID::setSetpoint(uint16_t setpoint) const { impl->setSetpoint(setpoint); }

uint16_t PID::getSetpoint() const { return impl->getSetpoint(); }

void PID::setMaxOutput(float maxOutput) const { impl->setMaxOutput(maxOutput); }

float PID::getMaxOutput() const { return impl->getMaxOutput(); }
