cmake_minimum_required(VERSION 3.8)
project(cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

add_executable(cpp_executable src/cpp_template.cpp)       # It is created the executable
ament_target_dependencies(cpp_executable rclcpp)          # Add the dependencies

add_executable(cpp_publisher src/cpp_publisher.cpp)
ament_target_dependencies(cpp_publisher rclcpp example_interfaces)

add_executable(cpp_subscriber src/cpp_subscriber.cpp)
ament_target_dependencies(cpp_subscriber rclcpp example_interfaces)

install(TARGETS                                           # Install the execuatble in lib folder
  cpp_executable
  cpp_publisher
  cpp_subscriber
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
