cmake_minimum_required(VERSION 3.20)

project(BBSnake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SRC_LIST main.cpp point.cpp display.cpp figure.cpp active_figure.cpp non_active_figure.cpp ancontainer.cpp hwall.cpp vwall.cpp snake.cpp eat.cpp traceline.cpp enemy.cpp initalizer.cpp hline.cpp vline.cpp)
set(HEAD_LIST point.h display.h figure.h active_figure.h non_active_figure.h ancontainer.h hwall.h vwall.h snake.h direction.h eat.h traceline.h color.h enemy.h initalizer.h hline.h vline.h)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(${PROJECT_NAME} ${SRC_LIST} ${HEAD_LIST})
target_link_libraries(BBSnake ${CURSES_LIBRARIES})
