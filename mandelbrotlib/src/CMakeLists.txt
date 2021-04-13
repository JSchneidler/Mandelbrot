cmake_minimum_required(VERSION 3.11...3.20)

add_library(MandelbrotLib
    mandelbrot.cpp
)

# Compiler options
if (MSVC)
    target_compile_options(MandelbrotLib PRIVATE ${MSVC_WARNING_FLAGS})
else()
    target_compile_options(MandelbrotLib PRIVATE ${GCC_WARNING_FLAGS})
endif()

# Use C++ 20
target_compile_features(MandelbrotLib PRIVATE cxx_std_20)
target_include_directories(MandelbrotLib PUBLIC ../include)
