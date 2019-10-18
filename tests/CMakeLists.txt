SET (INCLUDE ${Mandelbrot_SOURCE_DIR}/tests/include)
SET (HEADERS
  ${INCLUDE}/MandelbrotTest.h
  ${INCLUDE}/ComplexNumberTest.h
)
SET (SRC
  main.cpp
  MandelbrotTest.cpp
  ComplexNumberTest.cpp
)

INCLUDE_DIRECTORIES (${INCLUDE})
ADD_EXECUTABLE (Test ${HEADERS} ${SRC})
