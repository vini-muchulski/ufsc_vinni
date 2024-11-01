cmake_minimum_required(VERSION 3.10)

project(SD2)

set(OpenCV_DIR C:/Users/vinic/Downloads/opencv/build)
find_package(OpenCV REQUIRED)

add_executable(SD2 src/main.cpp)
target_link_libraries(SD2 ${OpenCV_LIBS})