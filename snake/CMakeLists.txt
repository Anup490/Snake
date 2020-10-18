# CMakeList.txt : CMake project for snake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (snake "main.cpp" "painter/Painter.h" "painter/Painter.cpp" "timer/Timer.h" "timer/Timer.cpp" "items/Abstractitem.h" "items/Snakeitem.h" "items/Snakeitem.cpp" "constant/Constants.h" "collision/Collision.h" "collision/Collision.cpp" "items/Fooditem.h" "items/Fooditem.cpp")

# TODO: Add tests and install targets if needed.
