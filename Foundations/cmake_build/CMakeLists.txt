# define minimum version of CMAKE to use
cmake_minimum_required(VERSION 3.5.1)

# define the version of C++ to use
set(CMAKE_CXX_STANDARD 17)

# define the project name
project("compute_vector_sum")

# add an executable to project
add_executable("a.out" "src/main.cpp" "src/vect_add_one.cpp" "src/increment_and_sum.cpp")