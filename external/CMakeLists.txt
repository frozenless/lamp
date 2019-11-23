option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
option(GLFW_BUILD_DOCS OFF)
option(GLFW_INSTALL OFF)

option(GLAD_NO_LOADER ON)

set(GLAD_API "gl=${GL_MAJOR_VERSION}.${GL_MINOR_VERSION}")
set(GLAD_PROFILE "core")

add_subdirectory(glfw)
add_subdirectory(glad)
