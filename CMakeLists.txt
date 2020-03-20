cmake_minimum_required(VERSION 3.14)

project(Lamp VERSION 0.0.4 LANGUAGES CXX)

add_subdirectory(external)
add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
PRIVATE external/imgui/examples/imgui_impl_opengl3.cpp
        external/imgui/examples/imgui_impl_glfw.cpp
        external/imgui/imgui_widgets.cpp
        external/imgui/imgui_draw.cpp
        external/imgui/imgui.cpp

        internal/engine/systems/renderer.cpp
        internal/engine/systems/physics.cpp
        internal/engine/systems/transform.cpp
        internal/engine/material.cpp
        internal/engine/camera.cpp

        internal/physics/renderer.cpp
        internal/physics/utils.cpp
        internal/physics/ray.cpp

        internal/common/random.cpp
        internal/common/file.cpp
        internal/common/timer.cpp

        internal/gl/object.cpp
        internal/gl/mesh.cpp
        internal/gl/buffer.cpp
        internal/gl/shader.cpp
        internal/gl/program.cpp
        internal/gl/attribute.cpp
        internal/gl/texture.cpp
        internal/gl/renderer.cpp

        internal/profiler.cpp
        internal/engine.cpp
        internal/editor.cpp
        internal/physics.cpp
        internal/importer.cpp
        internal/window.cpp
        internal/assets.cpp
        internal/layout.cpp
        internal/game.cpp)

target_compile_definitions(${PROJECT_NAME}
PUBLIC  IMGUI_IMPL_OPENGL_LOADER_GLAD
        GLFW_INCLUDE_NONE
PRIVATE STB_IMAGE_IMPLEMENTATION
        B3_NO_PROFILE)

target_link_libraries(${PROJECT_NAME}
PUBLIC  entityx BulletDynamics BulletCollision LinearMath glfw glad glm
PRIVATE assimp)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_include_directories(${PROJECT_NAME}
PRIVATE external/stb
PUBLIC  external/bullet3/src
        external/imgui/examples
        external/imgui
        internal)
