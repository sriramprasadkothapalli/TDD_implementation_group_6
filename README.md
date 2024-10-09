# TDD_implementation_group_6

# TDD implementation group 6 Badges

![CICD Workflow status](https://github.com/sriramprasadkothapalli/TDD_implementation_group_6/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg) [![codecov](https://codecov.io/gh/sriramprasadkothapalli/TDD_implementation_group_6/branch/main/graph/badge.svg)](https://codecov.io/gh/sriramprasadkothapalli/TDD_implementation_group_6) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

## Overview

PID Controller implementation for ACME Robotics. This is part of Test Driven Development Assignment.
<br>TDD group number 6 Pair A <br>
Pair A member names and roles

| Role / Part | Part 1                    | Part 2                  |
|-------------|---------------------------|-------------------------|
| Navigator   | Sri ram Prasad Kothapalli | Apoorv Thapliyal        |
| Driver      | Anirudh Swarankar         | Amogha Thalihalla Sunil |

## Design overview

![UML diagram](https://github.com/sriramprasadkothapalli/TDD_implementation_group_6/blob/main/UML/version_2.png)

The project consists of two key libraries: Mathlib and PID Library.

1. **Mathlib**:
    - **Purpose**: Mathlib provides essential mathematical functions required by the project, packaged within the
      mathlib namespace.
    - **Design**: It is structured as a shared library, ensuring reusability and modularity. By employing a shared
      library, multiple executables or other projects can leverage the mathlib namespace without duplicating code,
      fostering efficiency and maintainability.
    - **Advantages**:
        - **Modularity**: Clearly separated mathematical operations promote clean code and ease of future extension.
        - **Reusability**: Sharing across different executables without redundancy.
2. **PID**:
    - **Purpose**: This library handles the implementation of a PID (Proportional-Integral-Derivative) controller.
    - **Design**: The actual PID implementation is encapsulated within PIDImpl, and only a pointer to this
      implementation is exposed to the user. This abstraction ensures that the underlying complexity is hidden, enabling
      users to interact with a simplified API while maintaining flexibility in internal changes without affecting
      external users.
    - **Advantages**:
        - **Encapsulation**: Hides internal complexities, simplifying interface usage.
        - **Flexibility**: Allows changes to the implementation without impacting the external API.

## Installation instructions

```bash
#Download the code:
  git clone https://github.com/sriramprasadkothapalli/TDD_implementation_group_6.git
  cd TDD_implementation_group_6
#Configure the project and generate a native build system:
#Must re - run this command whenever any CMakeLists.txt file has been changed.
  cmake -S ./ -B build/
#Compile and build the project:
  cmake --build build/ --clean-first --verbose
#Run program:
  ./build/app/pid_controller
#Run tests:
  ctest --test-dir build/
#Build docs:
  cmake --build build/ --target docs
#open a web browser to browse the doc
  open docs/html/index.html
#Clean
  cmake --build build/ --target clean
#Clean and start over:
  rm -rf build/
```

## code credit

https://github.com/tttapa/Control-Surface-Motor-Fader/blob/7fda1169f57cdb3e7887d1cc1c9ae9a797ea0afa/Motor-Controller/Controller.hpp
