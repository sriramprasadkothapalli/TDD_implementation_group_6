#ifndef PID_H
#define PID_H
#include "mathlib.hpp"
#include <cstdint>
#include <memory>


class PIDImpl;
/**
* @brief Standard PID (proportional, integral, derivative) controller. Derivative component is filtered using an exponential moving average filter.
* @cite https://github.com/tttapa/Control-Surface-Motor-Fader/blob/7fda1169f57cdb3e7887d1cc1c9ae9a797ea0afa/Motor-Controller/Controller.hpp
* @authors Pieter P, Sriram, Anirudh Swarankar
*/
class PID {
public:
    PID() = default;

    ~PID() = default;

    /**
     * @brief Constructor to initiate PID controller
     * @param kp Proportional gain
     * @param ki Integral gain
     * @param kd Derivative gain
     * @param Ts Sampling time (seconds)
     * @param f_c Cutoff frequency of derivative EMA filter (Hertz), zero to disable the filter entirely
     * @param maxOutput Max output of the controller default 255
     */
    PID(float kp, float ki, float kd, float Ts, float f_c = 0, float maxOutput = 255);

    /**
     *@brief Function to compute control command
     * Update the controller: given the current position, compute the control action.
     *@param input
     */
    float update(uint16_t input) const;

    /**
     * @brief Utility to set kp
     * @param kp Proportional gain
     */
    void setKp(float kp) const;

    /**
    * @brief Utility to set ki
    * @param ki Integral gain
    */
    void setKi(float ki) const;

    /**
     * @brief Utility to set kd
     * @param kd Derivative gain
     */
    void setKd(float kd) const;

    /**
     *@brief Utility function to fetch proportional gain
     */
    [[nodiscard]] float getKp() const;

    /**
    *@brief Utility function to fetch Integral gain
    */
    [[nodiscard]] float getKi() const;

    /**
   *@brief Utility function to fetch Derivative gain
   */
    [[nodiscard]] float getKd() const;

    /**
     *@brief Set the reference/target/setpoint of the controller
     */
    void setSetpoint(uint16_t setpoint) const;

    /**
     *@brief Get the reference/target/setpoint of the controller
     */
    [[nodiscard]] uint16_t getSetpoint() const;

    /**
     *@brief Set the maximum control output magnitude. Default is 255, which clamps the control output in [-255, +255]
     */
    void setMaxOutput(float maxOutput) const;

    /**
     *@brief Get the max output of controller
     */
    [[nodiscard]] float getMaxOutput() const;

private:
    /**
    * @brief pointer to PID implementation
   */
    std::shared_ptr<PIDImpl> impl;
};


#endif
