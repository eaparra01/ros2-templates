cmake_minimum_required(VERSION 3.8)
project(cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(cpp_executable src/cpp_template.cpp)       # It is created the executable
ament_target_dependencies(cpp_executable rclcpp)           # Add the dependencies

install(TARGETS                                           # Install the execuatble in lib folder
  cpp_executable
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
