# CMakeList.txt : CMake project for snake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (snake "main.cpp" "painter/painter.h" "painter/painter.cpp" "timer/timer.h" "timer/timer.cpp" "items/abstractitem.h" "items/snakeitem.h" "items/snakeitem.cpp")

# TODO: Add tests and install targets if needed.
