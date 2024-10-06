# cpp-boilerplate-v2

# C++ Boilerplate v2 Badges
![CICD Workflow status](https://github.com/TommyChangUMD/cpp-boilerplate-v2/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg) [![codecov](https://codecov.io/gh/TommyChangUMD/cpp-boilerplate-v2/branch/main/graph/badge.svg)](https://codecov.io/gh/TommyChangUMD/cpp-boilerplate-v2) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)


## Overview

PID Controller implementation for ACME Robotics. This is part of Test Driven Development Assignment.
<br>TDD group number 6 Pair A <br>
Pair A member names and roles 

| Role / Part | Part 1            | Part 2            |
|-------------|-------------------|-------------------|
| Navigator   | Sri ram Prasad Kothapalli    | Anirudh Swarankar |
| Driver      | Anirudh Swarankar | Sri ram Prasad Kothapalli    |

## Design overview 

insert UML here and basic explanation


## Installation instructions 
```bash
# Download the code:
  git clone <url>
  cd PID_controller_A
# Configure the project and generate a native build system:
  # Must re-run this command whenever any CMakeLists.txt file has been changed.
  cmake -S ./ -B build/
# Compile and build the project:
  cmake --build build/ --clean-first --verbose
# Run program:
  ./build/app/<name>
# Run tests:
  ctest --test-dir build/
# Build docs:
  cmake --build build/ --target docs
  # open a web browser to browse the doc
  open docs/html/index.html
# Clean
  cmake --build build/ --target clean
# Clean and start over:
  rm -rf build/
```

## code credit
https://github.com/tttapa/Control-Surface-Motor-Fader/blob/7fda1169f57cdb3e7887d1cc1c9ae9a797ea0afa/Motor-Controller/Controller.hpp