project(lamp VERSION 0.0.1 LANGUAGES CXX)

add_library(${PROJECT_NAME} window.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC .)

target_compile_features(${PROJECT_NAME}
    PUBLIC cxx_std_17)

target_link_libraries(${PROJECT_NAME}
    PUBLIC glfw)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE -DGLFW_INCLUDE_NONE)
