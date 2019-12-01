set(GL_MAJOR_VERSION 4 CACHE STRING "gl major version" FORCE)
set(GL_MINOR_VERSION 3 CACHE STRING "gl major version" FORCE)

set(GLSL_VERSION "#version ${GL_MAJOR_VERSION}${GL_MINOR_VERSION}0 core" CACHE STRING "glsl version" FORCE)

configure_file("config.hpp" "${CMAKE_SOURCE_DIR}/internal/config.hpp")
