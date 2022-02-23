cmake_minimum_required(VERSION 3.17)
project(Tamagotchi LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(external/raylib)

set(TRY_HARD_WINGS_SRC
        src/app.cpp
        src/devMenu.cpp
        src/main.cpp
        src/curves.cpp
        )

set(IMGUI_SRC
        external/imgui/imgui.cpp
        external/imgui/imgui_demo.cpp
        external/imgui/imgui_draw.cpp
        external/imgui/imgui_tables.cpp
        external/imgui/imgui_widgets.cpp
        )


add_executable(Tamagotchi ${TRY_HARD_WINGS_SRC} ${IMGUI_SRC} external/rlImGui/rlImGui.cpp)
target_include_directories(Tamagotchi PUBLIC include external/rlImGui external/imgui)
target_link_libraries(Tamagotchi raylib)

message(STATUS "FLAGS: ${CMAKE_CXX_FLAGS}")