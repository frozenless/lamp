cmake_minimum_required(VERSION 3.14)

project(lamp VERSION 0.0.1 LANGUAGES CXX)

add_library(${PROJECT_NAME})

add_subdirectory(config)
add_subdirectory(external)
add_subdirectory(internal)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE STB_IMAGE_IMPLEMENTATION B3_NO_PROFILE
    PUBLIC  GLFW_INCLUDE_NONE)

target_compile_features(${PROJECT_NAME}
    PUBLIC cxx_std_17)

target_link_libraries(${PROJECT_NAME}
    PUBLIC glfw glad glm assimp BulletDynamics BulletCollision LinearMath)

target_include_directories(${PROJECT_NAME}
    PRIVATE external/stb
    PUBLIC  external/bullet3/src
            internal)
