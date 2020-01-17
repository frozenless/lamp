set(GL_MAJOR_VERSION 4 CACHE STRING "gl major version")
set(GL_MINOR_VERSION 3 CACHE STRING "gl minor version")

set(GLSL_VERSION "#version ${GL_MAJOR_VERSION}${GL_MINOR_VERSION}0 core" CACHE STRING "glsl version")

configure_file(config.hpp ${CMAKE_CURRENT_SOURCE_DIR}/../internal/utils/config.hpp)
