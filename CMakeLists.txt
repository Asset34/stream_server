cmake_minimum_required(VERSION 2.8)
project(stream_server)

# Variables
set(SOURCES_DIR src)
set(HEADERS_DIR src)
set(LIBS_DIR libs)

# Qt flags
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set (SOURCES
    ${SOURCES_DIR}/main.cpp
    ${SOURCES_DIR}/ui/windows/mainwindow.cpp
    ${SOURCES_DIR}/ui/panels/mediapanel.cpp
    ${SOURCES_DIR}/ui/panels/streampanel.cpp
    ${SOURCES_DIR}/ui/subpanels/mediasetsubpanel.cpp
    ${SOURCES_DIR}/ui/subpanels/mediainfosubpanel.cpp
    ${SOURCES_DIR}/ui/subpanels/videosubpanel.cpp
    ${SOURCES_DIR}/ui/subpanels/audiosubpanel.cpp
    ${SOURCES_DIR}/ui/subpanels/transcodesubpanel.cpp
    ${SOURCES_DIR}/ui/subpanels/addresssubpanel.cpp
    ${SOURCES_DIR}/ui/widgets/openfilebox.cpp
    ${SOURCES_DIR}/ui/widgets/inputbox.cpp
    ${SOURCES_DIR}/ui/widgets/outputbox.cpp
    ${SOURCES_DIR}/ui/widgets/selectbox.cpp
    ${SOURCES_DIR}/ui/widgets/inputvaluebox.cpp
    ${SOURCES_DIR}/ui/widgets/videocodeccombobox.cpp
    ${SOURCES_DIR}/ui/widgets/qualitycombobox.cpp
    ${SOURCES_DIR}/ui/widgets/aspectratiocombobox.cpp
    ${SOURCES_DIR}/ui/widgets/audiocodeccombobox.cpp
    ${SOURCES_DIR}/ui/widgets/sampleratecombobox.cpp
    ${SOURCES_DIR}/ui/widgets/ipinputbox.cpp
    ${SOURCES_DIR}/soutbuilder.cpp
    ${SOURCES_DIR}/vlcmanager.cpp
    )

set (HEADERS
    ${HEADERS_DIR}/ui/windows/mainwindow.hpp
    ${HEADERS_DIR}/ui/panels/mediapanel.hpp
    ${HEADERS_DIR}/ui/panels/streampanel.hpp
    ${HEADERS_DIR}/ui/subpanels/mediasetsubpanel.hpp
    ${HEADERS_DIR}/ui/subpanels/mediainfosubpanel.hpp
    ${HEADERS_DIR}/ui/subpanels/videosubpanel.hpp
    ${HEADERS_DIR}/ui/subpanels/audiosubpanel.hpp
    ${HEADERS_DIR}/ui/subpanels/transcodesubpanel.hpp
    ${HEADERS_DIR}/ui/subpanels/addresssubpanel.hpp
    ${HEADERS_DIR}/ui/widgets/openfilebox.hpp
    ${HEADERS_DIR}/ui/widgets/inputbox.hpp
    ${HEADERS_DIR}/ui/widgets/outputbox.hpp
    ${HEADERS_DIR}/ui/widgets/selectbox.hpp
    ${HEADERS_DIR}/ui/widgets/inputvaluebox.hpp
    ${HEADERS_DIR}/ui/widgets/videocodeccombobox.hpp
    ${HEADERS_DIR}/ui/widgets/qualitycombobox.hpp
    ${HEADERS_DIR}/ui/widgets/aspectratiocombobox.hpp
    ${HEADERS_DIR}/ui/widgets/audiocodeccombobox.hpp
    ${HEADERS_DIR}/ui/widgets/sampleratecombobox.hpp
    ${HEADERS_DIR}/ui/widgets/ipinputbox.hpp
    ${HEADERS_DIR}/soutbuilder.hpp
    ${HEADERS_DIR}/vlcmanager.hpp
    )

# App
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    )
include_directories(${HEADERS_DIR})

# Qt
find_package(Qt5Widgets REQUIRED)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

# Vlc-qt
set(VLCQT_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(VLCQT_BUILD_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory(${LIBS_DIR}/vlc-qt)
target_link_libraries(${PROJECT_NAME} Core)
include_directories(${CMAKE_BINARY_DIR}/${LIBS_DIR}/vlc-qt/include)
