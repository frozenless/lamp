option(GLM_TEST_ENABLE OFF)

option(BUILD_EXTRAS OFF)
option(BUILD_CPU_DEMOS OFF)
option(BUILD_UNIT_TESTS OFF)
option(BUILD_BULLET2_DEMOS OFF)
option(BUILD_OPENGL3_DEMOS OFF)
option(USE_GRAPHICAL_BENCHMARK OFF)
option(INSTALL_LIBS OFF)

option(ozz_build_fbx OFF)
option(ozz_build_tools OFF)
option(ozz_build_samples OFF)
option(ozz_build_howtos OFF)

option(RECASTNAVIGATION_DEMO OFF)
option(RECASTNAVIGATION_TESTS OFF)
option(RECASTNAVIGATION_EXAMPLES OFF)

option(ENTITYX_BUILD_TESTING OFF)

option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
option(GLFW_BUILD_DOCS OFF)
option(GLFW_INSTALL OFF)

option(GLAD_NO_LOADER ON)

option(ASSIMP_BUILD_ALL_IMPORTERS_BY_DEFAULT OFF)
option(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
option(ASSIMP_BUILD_SAMPLES OFF)
option(ASSIMP_BUILD_TESTS OFF)
option(ASSIMP_INSTALL OFF)

set(ASSIMP_BUILD_OBJ_IMPORTER ON)
set(ASSIMP_NO_EXPORT ON)

set(ENTITYX_MAX_COMPONENTS 12)
set(ENTITYX_BUILD_TESTING false)
set(ENTITYX_DT_TYPE float)
set(ENTITYX_BUILD_SHARED false)

set(GL_MAJOR_VERSION 4 CACHE STRING "gl major version")
set(GL_MINOR_VERSION 5 CACHE STRING "gl minor version")

set(GLAD_API "gl=${GL_MAJOR_VERSION}.${GL_MINOR_VERSION}")
set(GLAD_PROFILE "core")

if (MSVC)
    set(USE_MSVC_RUNTIME_LIBRARY_DLL ON)
endif()

configure_file(config.hpp ${CMAKE_CURRENT_SOURCE_DIR}/../internal/common/config.hpp)

set(ASSIMP_BUILD_OBJ_IMPORTER ON)
set(ASSIMP_NO_EXPORT ON)

add_subdirectory(vulkan-headers)
add_subdirectory(vulkan-loader)

add_subdirectory(ozz-animation)
add_subdirectory(recastnavigation)

add_subdirectory(entityx)
add_subdirectory(bullet3)
add_subdirectory(assimp)
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(glm)
