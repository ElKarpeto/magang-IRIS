project(coba)
cmake_minimum_required(VERSION 3.0)

add_compile_options(-std=c++17)

find_package(OpenCV REQUIRED)

include_directories(
    include
    ${OpenCV_INCLUDE_DIRS}
)

# ini sat project
set(SOURCES src/main.cpp)
add_executable(coba src/main.cpp)
target_link_libraries(coba ${OpenCV_LIBS})