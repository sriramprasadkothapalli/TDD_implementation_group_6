#include <cstdio>
#include <memory>
#include <pid.hpp>

int main() {
  std::shared_ptr<PID> pid =
      std::make_shared<PID>(0.1, 0.5, 0.01, 0.01, 1.5, 255);
  pid->setKd(0.01);
  pid->setKp(0.1);
  pid->setKi(0.5);
  pid->setMaxOutput(255);
  pid->setSetpoint(0);
  double val = 20;
  for (int i = 0; i < 100; i++) {
    double inc = pid->update(static_cast<uint16_t>(val));
    printf("val:% 7.3f inc:% 7.3f\n", val, inc);
    val += inc;
  }
  return 0;
}
