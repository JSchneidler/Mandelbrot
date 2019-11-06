add_library(MandelbrotLib
    include/complex_number.hpp
    src/complex_number.cpp
    include/mandelbrot.hpp
    src/mandelbrot.cpp
)

target_include_directories(MandelbrotLib PUBLIC include)