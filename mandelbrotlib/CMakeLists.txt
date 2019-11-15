add_library(MandelbrotLib
    include/mandelbrot.hpp
    src/mandelbrot.cpp
)

target_include_directories(MandelbrotLib PUBLIC include)