add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)
target_compile_definitions(${PROJECT_NAME} PUBLIC GLFW_INCLUDE_NONE)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_link_libraries(${PROJECT_NAME}   PUBLIC glfw glad glm)

target_sources(${PROJECT_NAME}
    PRIVATE gl/mesh.cpp
            gl/shader.cpp
            gl/program.cpp
            gl/attribute.cpp
            window.cpp
            common.cpp
            assets.cpp)
