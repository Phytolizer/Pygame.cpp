# CMakeList.txt : Top-level CMake project file, do global configuration and
# include sub-projects here.
#
cmake_minimum_required(VERSION 3.8)

project("Pygame.cpp")

find_package(
    "SDL2"
    CONFIG
    REQUIRED
)
find_package(
    "sdl2-image"
    CONFIG
    REQUIRED
)
find_package(
    "sdl2-mixer"
    CONFIG
    REQUIRED
)
find_package(
    "sdl2-ttf"
    CONFIG
    REQUIRED
)

# Include sub-projects.
add_subdirectory("Pygame.cpp")
