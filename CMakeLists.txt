cmake_minimum_required(VERSION 3.17)
project(Tamagotchi LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(raylib)

file(GLOB_RECURSE TRY_HARD_WINGS_SRC
        src/*.cpp)

file(GLOB_RECURSE IMGUI_SRC
        imgui/*.cpp)


add_executable(Tamagotchi ${TRY_HARD_WINGS_SRC} ${IMGUI_SRC} rlImGui/rlImGui.cpp)
target_include_directories(Tamagotchi PUBLIC include rlImGui imgui)
target_link_libraries(Tamagotchi raylib)

message(STATUS "FLAGS: ${CMAKE_CXX_FLAGS}")