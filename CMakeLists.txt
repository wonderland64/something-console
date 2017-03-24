cmake_minimum_required (VERSION 3.7)
project (ncursesThings)
set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++14")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
include_directories( ${CURSES_INCLUDE_DIRS} )

set(SOURCES main.cpp Actor.cpp GameController.cpp InputController.cpp InputMode.cpp LevelController.cpp Level.cpp Player.cpp Room.cpp Tile.cpp )

set(NCURSES_EXTRAS panel)
add_executable(main ${SOURCES})
target_link_libraries(main ${CURSES_LIBRARIES} ${NCURSES_EXTRAS})
