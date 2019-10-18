SET (wxWidgets_CONFIGURATION mswud)
FIND_PACKAGE (wxWidgets COMPONENTS core base REQUIRED)
INCLUDE (${wxWidgets_USE_FILE})

SET (HEADERS
  include/Mandelbrot.h
  include/ComplexNumber.h
  include/RootWindow.h
  include/LeftPanel.h
  include/Canvas.h
)
SET (SRC
  Mandelbrot.cpp
  ComplexNumber.cpp
  RootWindow.cpp
  LeftPanel.cpp
  Canvas.cpp
)

IF (WIN32)
  SET (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
ENDIF()

INCLUDE_DIRECTORIES (${PROJECT_NAME} PRIVATE ${Mandelbrot_SOURCE_DIR})
INCLUDE_DIRECTORIES (${PROJECT_NAME} PRIVATE include)

ADD_LIBRARY (MandelbrotLib ${HEADERS} ${SRC})
ADD_EXECUTABLE (${PROJECT_NAME} include/App.h App.cpp)
TARGET_LINK_LIBRARIES (${PROJECT_NAME} MandelbrotLib)
TARGET_LINK_LIBRARIES (${PROJECT_NAME} ${wxWidgets_LIBRARIES})
