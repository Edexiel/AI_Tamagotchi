cmake_minimum_required(VERSION 3.17)
project(Kintama LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(external/raylib)

set(IMGUI_SRC
        external/imgui/imgui.cpp
        external/imgui/imgui_demo.cpp
        external/imgui/imgui_draw.cpp
        external/imgui/imgui_tables.cpp
        external/imgui/imgui_widgets.cpp
        )

set(TRY_HARD_WINGS_SRC
        src/App.cpp
        src/DevMenu.cpp
        src/main.cpp
        src/UtilitySystem/UtilitySystem.cpp
        src/UtilitySystem/Blackboard.cpp
        src/UtilitySystem/UtilityBase.cpp
        src/Pet.cpp
        src/PetStats.cpp
        src/UtilitySystem/ActionBase.cpp
        src/UtilitySystem/Actions/ActionEat.cpp
        src/UtilitySystem/Actions/ActionSleep.cpp
        src/UtilitySystem/Actions/ActionClean.cpp
        src/UtilitySystem/Actions/ActionPlay.cpp
        src/Curves.cpp
        src/UtilitySystem/Utilities/UtilityFeeding.cpp
        src/UtilitySystem/Utilities/UtilityCleaning.cpp
        src/UtilitySystem/Utilities/UtilityPlaying.cpp
        src/UtilitySystem/Utilities/UtilitySleeping.cpp
        )



#file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
add_executable(Kintama ${TRY_HARD_WINGS_SRC} ${IMGUI_SRC} external/rlImGui/rlImGui.cpp)
target_include_directories(Kintama PUBLIC include external/rlImGui external/imgui)
target_link_libraries(Kintama raylib)

message(STATUS "FLAGS: ${CMAKE_CXX_FLAGS}")