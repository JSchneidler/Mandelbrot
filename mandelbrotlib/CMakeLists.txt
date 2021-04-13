cmake_minimum_required(VERSION 3.11...3.20)

# Main
add_subdirectory(src)

# Tests
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(CTest)

  if (BUILD_TESTING)
    add_subdirectory(test)
  endif()
endif()

