cmake_minimum_required(VERSION 3.1...3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(
	Mandelbrot
	VERSION 1.0
	DESCRIPTION "A Mandelbrot set visualizer"
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${CMAKE_PROJECT_NAME})

# Dependencies
set(wxWidgets_CONFIGURATION mswud)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

# Main
configure_file(
	"${PROJECT_SOURCE_DIR}/Config.hpp.in"
	"${PROJECT_BINARY_DIR}/Config.hpp"
)

add_executable(Mandelbrot
	${PROJECT_SOURCE_DIR}/include/App.hpp
	${PROJECT_SOURCE_DIR}/include/RootWindow.hpp
	${PROJECT_SOURCE_DIR}/include/LeftPanel.hpp
	${PROJECT_SOURCE_DIR}/include/Canvas.hpp
	${PROJECT_SOURCE_DIR}/src/App.cpp
	${PROJECT_SOURCE_DIR}/src/RootWindow.cpp
	${PROJECT_SOURCE_DIR}/src/LeftPanel.cpp
	${PROJECT_SOURCE_DIR}/src/Canvas.cpp
)

if(WIN32)
	target_link_options(Mandelbrot PRIVATE "/SUBSYSTEM:WINDOWS")
endif()

target_include_directories(Mandelbrot
	PUBLIC
		"${PROJECT_BINARY_DIR}"
		"${PROJECT_SOURCE_DIR}/include"
)

# Math lib
add_subdirectory(mandelbrotlib)

# Link libraries
target_link_libraries(Mandelbrot PRIVATE MandelbrotLib ${wxWidgets_LIBRARIES})

# Tests
add_subdirectory(tests)