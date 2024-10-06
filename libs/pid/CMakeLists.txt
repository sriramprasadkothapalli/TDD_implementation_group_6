# Create a library called "myLib1" (in Linux, this library is created
# with the name of either libmyLib1.a or myLib1.so).
#find_package(mathlib)
add_library(pid SHARED
        # list of cpp source files:
        src.cpp
)
# Indicate what directories should be added to the include file search
# path when using this library.
target_include_directories(pid PUBLIC
        # list of directories:
        include
)
target_link_libraries(pid PUBLIC
        # list of libraries
        mathlib
)