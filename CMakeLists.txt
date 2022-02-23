cmake_minimum_required(VERSION 3.17)
project(Tamagotchi LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(external/raylib)

file(GLOB_RECURSE TRY_HARD_WINGS_SRC
        src/*.cpp)

file(GLOB_RECURSE IMGUI_SRC
        external/imgui/*.cpp)


add_executable(Tamagotchi ${TRY_HARD_WINGS_SRC} ${IMGUI_SRC} external/rlImGui/rlImGui.cpp)
target_include_directories(Tamagotchi PUBLIC include external/rlImGui external/imgui)
target_link_libraries(Tamagotchi raylib)

message(STATUS "FLAGS: ${CMAKE_CXX_FLAGS}")