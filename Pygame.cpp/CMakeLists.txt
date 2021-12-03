# CMakeList.txt : CMake project for Pygame.cpp, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.8)

# Create assets target.
add_custom_target(
    "copy_assets"
    COMMAND "${CMAKE_COMMAND}" -E copy_directory "${PROJECT_SOURCE_DIR}/assets"
            "${CMAKE_CURRENT_BINARY_DIR}/assets"
)

# Add source to this project's executable.
add_executable(
    Pygame.cpp WIN32
    "GraphicsContext.cpp"
    "GraphicsContext.hpp"
    "MySDL.cpp"
    "MySDL.hpp"
    "Pygame.cpp"
    "SmartRenderer.cpp"
    "SmartRenderer.hpp"
    "SmartSurface.cpp"
    "SmartSurface.hpp"
    "SmartTexture.cpp"
    "SmartTexture.hpp"
    "SmartWindow.cpp"
    "SmartWindow.hpp"
    "Sprite.cpp"
    "Sprite.hpp"
)

# Depend on assets being copied.
add_dependencies("Pygame.cpp" "copy_assets")

# Link required libraries.
target_link_libraries(
    "Pygame.cpp"
    PRIVATE "SDL2::SDL2-static"
            "SDL2::SDL2_image"
            "SDL2::SDL2_mixer"
            "SDL2::SDL2_ttf"
)
if(WIN32)
    target_link_libraries("Pygame.cpp" PRIVATE "SDL2::SDL2main")
endif()

# TODO: Add tests and install targets if needed.
