cmake_minimum_required(VERSION 3.11...3.20)

project(
	Mandelbrot
	VERSION 1.0
	DESCRIPTION "A Mandelbrot set visualizer"
	LANGUAGES CXX
)

# Set Visual Studio default startup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${CMAKE_PROJECT_NAME})

# Dependencies
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

set(GCC_WARNING_FLAGS -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Werror -pedantic)
set(MSVC_WARNING_FLAGS /permissive /W4 /w14640 /WX)

# Main
add_subdirectory(mandelbrotlib)
add_subdirectory(src)

# Tests
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(CTest)

  if (BUILD_TESTING)
    add_subdirectory(test)
  endif()
endif()
