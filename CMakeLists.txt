cmake_minimum_required(VERSION 3.16)

project(BinaryTreeVisualizer)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

include_directories(include)

add_executable(BinaryTreeVisualizer
    src/main.cpp
    src/BST.cpp
    src/Button.cpp
    src/UI.cpp
)

target_link_libraries(BinaryTreeVisualizer
    PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)