cmake_minimum_required(VERSION 2.8)
project(stream_server)

# App
add_executable(${PROJECT_NAME} "main.cpp")

# Qt
find_package(Qt5Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

# Vlc-Qt
