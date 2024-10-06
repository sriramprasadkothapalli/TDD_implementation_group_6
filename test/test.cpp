#include <gtest/gtest.h>
#include "pid.hpp"  

// Test Case 1: Verifying computed function of the PID controller
TEST(PIDTest, TestPIDComputeFunction) {
    PID pidController(1.0, 0.5, 0.1, 0.01, 0.5, 100.0); // kp, ki, kd, Ts, f_c, maxOutput

    // Set a setpoint and provide an input
    pidController.setSetpoint(100);  
    uint16_t input = 90; 

    // Compute the control command
    float controlOutput = pidController.update(input);

    // Expected value is calculated based on the PID equation manually here

    float expectedOutput = 1.0 * (100 - 90) + 0.5 * (100 - 90) * 0.01 - 0.1 * 0.5;  // Manually calculate this value

    // Check if the computed output matches the expected value
    EXPECT_NEAR(controlOutput, expectedOutput, 1e-5);
}

// Test Case 2: Verify the setKp() and getKp() functions
TEST(PIDTest, TestSetKpFunction) {
    // Create a PID object with some initial parameters
    PID pidController(1.0, 0.5, 0.1, 0.01);

    // Set a new Kp value
    pidController.setKp(2.0);

    // Check if the updated value is correct
    EXPECT_FLOAT_EQ(pidController.getKp(), 2.0);
}
// Testing clamping function from mathlib
TEST(MathLibTest, TestClampFunction) {
    EXPECT_EQ(mathlib::clamp(5, 1, 10), 5);   // Within bounds
    EXPECT_EQ(mathlib::clamp(0, 1, 10), 1);   // Below lower bound
    EXPECT_EQ(mathlib::clamp(15, 1, 10), 10); // Above upper bound
}