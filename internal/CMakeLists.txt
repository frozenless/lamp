add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)
target_compile_definitions(${PROJECT_NAME} PRIVATE -DGLFW_INCLUDE_NONE)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_link_libraries(${PROJECT_NAME}   PUBLIC glfw)

target_sources(${PROJECT_NAME}
    PRIVATE window.cpp)
