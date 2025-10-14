cmake_minimum_required(VERSION 3.8)
project(my_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
include_directories(include)

add_executable(person_node src/person_node.cpp)
add_executable(my_cpp_node src/my_cpp_node.cpp)
add_executable(learn_thread src/learn_thread.cpp)
ament_target_dependencies(my_cpp_node rclcpp)#编译了ros2的库，同时完成了链接
ament_target_dependencies(person_node rclcpp)
ament_target_dependencies(learn_thread rclcpp)

install(TARGETS my_cpp_node person_node learn_thread
  DESTINATION lib/${PROJECT_NAME}
)#将生成的可执行文件安装在目标地址

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
