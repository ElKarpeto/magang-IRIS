project(modulopencv)
cmake_minimum_required(VERSION 3.0)

add_compile_options(-std=c++17)

find_package(OpenCV REQUIRED)

include_directories(
    include
    ${OpenCV_INCLUDE_DIRS}
)

# ini untuk coba-coba syntax
set(SOURCES src/main.cpp)
add_executable(coba src/main.cpp)
target_link_libraries(coba ${OpenCV_LIBS})

# tugas 1
set(SOURCES src/tugas-1.cpp)
add_executable(tugas1 src/tugas-1.cpp)
target_link_libraries(tugas1 ${OpenCV_LIBS})

# tugas 2
set(SOURCES src/tugas-2.cpp)
add_executable(tugas2 src/tugas-2.cpp)
target_link_libraries(tugas2 ${OpenCV_LIBS})

# tugas 3
set(SOURCES src/tugas-3.cpp)
add_executable(tugas3 src/tugas-3.cpp)
target_link_libraries(tugas3 ${OpenCV_LIBS})