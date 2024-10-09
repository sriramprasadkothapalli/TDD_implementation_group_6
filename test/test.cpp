#include <gtest/gtest.h>

#include "pid.hpp"

// Test Case 1: Verifying computed function of the PID controller
TEST(PIDTest, TestPIDComputeFunction) {
  PID pidController(0.1, 0.5, 0.01, 0.01, 0,
                    255.0);  // kp, ki, kd, Ts, f_c, maxOutput

  // Set a setpoint and provide an input
  pidController.setSetpoint(0);
  uint16_t input = 20;

  // Compute the control command
  float controlOutput = pidController.update(input);

  // Expected value is calculated based on the PID equation manually here

  float expectedOutput =
      pidController.getKp() * (pidController.getSetpoint() - input) +
      pidController.getKi() * 0.01 * (pidController.getSetpoint() - input) +
      (input)*pidController.getKd() * 0.01;
  // Manually calculate this value

  // Check if the computed output matches the expected value
  EXPECT_NEAR(controlOutput, expectedOutput, 1);
}

// Test Case 2: Verify the setKp() and getKp() functions
TEST(PIDTest, TestSetterGetterFunctions) {
  // Create a PID object with some initial parameters
  PID pidController(1.0, 0.5, 0.1, 1);

  // Set a new Kp value
  pidController.setKp(2.0);
  pidController.setKi(1.0);
  pidController.setKd(3.0);
  pidController.setSetpoint(0);
  pidController.setMaxOutput(100.0);

  // Check if the updated value is correct
  EXPECT_FLOAT_EQ(pidController.getKi(), 1.0);
  EXPECT_FLOAT_EQ(pidController.getKp(), 2.0);
  EXPECT_NE(pidController.getKd(), 2.0);
  EXPECT_FLOAT_EQ(pidController.getSetpoint(), 0);
  EXPECT_FLOAT_EQ(pidController.getMaxOutput(), 100.0);
}

/**
 *@brief Test cases for clamp function
 */
TEST(MathLibClampTest, TestClampFunction) {
  EXPECT_EQ(mathlib::clamp(5, 1, 10), 5);    // Within bounds
  EXPECT_EQ(mathlib::clamp(0, 1, 10), 1);    // Below lower bound
  EXPECT_EQ(mathlib::clamp(15, 1, 10), 10);  // Above upper bound
}

/**
 * @brief Test cases for finding sign of a value
 */
TEST(MathLibSignTest, TestSignFunction) {
  EXPECT_EQ(mathlib::sign(0), 0);
  EXPECT_EQ(mathlib::sign(1), 1);
  EXPECT_NE(mathlib::sign(2), -1);
}

/**
 *@brief Test cases for calcAlphaEMA function
 */
TEST(MathLibcalcAlphaEMATest, TestcalcAlphaEMAFuntion) {
  EXPECT_FLOAT_EQ(mathlib::calcAlphaEMA(1), -26.6211433);
  EXPECT_NEAR(mathlib::calcAlphaEMA(0.325), 0.787, 1);
}
