cmake_minimum_required(VERSION 2.8)
project(stream_server)

# Variables
set(SOURCES src)
set(LIBS libs)

# App
add_executable(${PROJECT_NAME}
    ${SOURCES}/main.cpp
    )

# Qt
find_package(Qt5Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

# Vlc-qt
set(VLCQt_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(VLCQt_BUILD_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory(${LIBS}/vlc-qt)
target_link_libraries(${PROJECT_NAME} Core)
include_directories(${CMAKE_BINARY_DIR}/${LIBS}/vlc-qt/include)
