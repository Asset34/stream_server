cmake_minimum_required(VERSION 2.8)
project(stream_server)

# Variables
set(SOURCES_DIR src)
set(HEADERS_DIR src)
set(LIBS_DIR libs)

set (SOURCES
    ${SOURCES_DIR}/main.cpp
    ${SOURCES_DIR}/ui/windows/mainwindow.cpp
    )

set (HEADERS
    ${HEADERS_DIR}/ui/windows/mainwindow.hpp
    )

# App
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    )
include_directories(${HEADERS_DIR})

# Qt
find_package(Qt5Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

# Vlc-qt
set(VLCQt_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(VLCQt_BUILD_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory(${LIBS_DIR}/vlc-qt)
target_link_libraries(${PROJECT_NAME} Core)
include_directories(${CMAKE_BINARY_DIR}/${LIBS_DIR}/vlc-qt/include)
