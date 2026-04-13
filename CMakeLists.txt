cmake_minimum_required(VERSION 3.16)

project(flappy_bird_cslt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(flappy_bird_week3
    main.cpp
    src/core/Game.cpp
    src/entities/Bird.cpp
    src/entities/Pipe.cpp
    src/managers/PipeManager.cpp
    src/ui/UI.cpp
    src/systems/Score.cpp
)

target_include_directories(flappy_bird_week3 PRIVATE src)

if (TARGET SFML::Graphics)
    target_link_libraries(flappy_bird_week3 PRIVATE SFML::Graphics SFML::Window SFML::System)
else()
    target_link_libraries(flappy_bird_week3 PRIVATE sfml-graphics sfml-window sfml-system)
endif()
