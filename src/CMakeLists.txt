cmake_minimum_required(VERSION 3.11...3.20)

configure_file(
	"${PROJECT_SOURCE_DIR}/Config.hpp.in"
	"${PROJECT_BINARY_DIR}/Config.hpp"
)

add_executable(Mandelbrot
	WIN32
	MACOSX_BUNDLE
	App.cpp
	RootWindow.cpp
	LeftPanel.cpp
	Canvas.cpp
)

# Compiler options
if (MSVC)
    target_compile_options(Mandelbrot PRIVATE ${MSVC_WARNING_FLAGS})
else()
    target_compile_options(Mandelbrot PRIVATE ${GCC_WARNING_FLAGS})
endif()

# Use C++ 17
target_compile_features(Mandelbrot PRIVATE cxx_std_17)
target_include_directories(Mandelbrot
	PUBLIC
		"${PROJECT_BINARY_DIR}"
		"${PROJECT_SOURCE_DIR}/include"
)

set_target_properties(Mandelbrot PROPERTIES
	MACOSX_BUNDLE_INFO_PLIST ${PROJECT_SOURCE_DIR}/cmake/Info.plist
)

# Link to Mandelbrot and wx libraries
target_link_libraries(Mandelbrot PRIVATE MandelbrotLib ${wxWidgets_LIBRARIES})
