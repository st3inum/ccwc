cmake_minimum_required(VERSION 3.10)
project(ccwc)

set(CMAKE_CXX_STANDARD 20)

# Find Boost
find_package(Boost REQUIRED COMPONENTS program_options)

# Add source files
set(SOURCES src/main.cpp src/helper.cpp)

# Include directories
include_directories(include)

# Create executable
add_executable(ccwc ${SOURCES})

# Link Boost libraries
target_link_libraries(ccwc Boost::program_options)

# Add tests
enable_testing()
add_executable(ccwc_tests tests/test_add.cpp src/helper.cpp)
add_test(NAME ccwcTests COMMAND ccwc_tests)

# Add a custom target to format all files
add_custom_target(format ALL
    COMMAND ${CMAKE_COMMAND} -E echo "Formatting source and header files..."
    COMMAND astyle --suffix=none -A2 -T -p --recursive "*.cpp,*.hpp"
    COMMAND ${CMAKE_COMMAND} -E echo "Formatting complete."
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# Ensure the format target is run before building the project
add_dependencies(ccwc format)
add_dependencies(ccwc_tests format)
