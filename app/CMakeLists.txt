#Any C++ source files needed to build this target(shell - app).
add_executable(pid_controller
#list of source cpp files:
                   main.cpp)

#Any include directories needed to build this target.
#Note : we do not need to specify the include directories for the
#dependent libraries, they are automatically included.
    target_include_directories(pid_controller PUBLIC
#list include directories:
                                   ${CMAKE_SOURCE_DIR} /
                               include)

#Any dependent libraires needed to build this target.
        target_link_libraries(pid_controller PUBLIC
#list of libraries
                                  pid)

#target_link_options(pid_controller PUBLIC
#-- static
#)
