cmake_minimum_required(VERSION 3.0)
project(GlHash)

find_package(OpenGL REQUIRED)

# Compile external dependencies
add_subdirectory(external)


include_directories(
        external/glfw-3.1.2/include/GLFW/
        external/glew-1.13.0/include/
        external/glm-0.9.7.1/
        .
)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
        GLEW_1130
        )

add_definitions(
        -DTW_STATIC
        -DTW_NO_LIB_PRAGMA
        -DTW_NO_DIRECT3D
        -DGLEW_STATIC
        -D_CRT_SECURE_NO_WARNINGS
)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp common/sha256.cpp common/sha256.h common/glhash.cpp common/glhash.h common/ReadBuffer.cpp common/ReadBuffer.h common/readBMP.cpp common/readBMP.h)

# add_executable(GlHash ${SOURCE_FILES})

add_executable(GlHash
        ${SOURCE_FILES}

        common/shader.cpp

        shaders/TransformVertexShader.vertexshader
        shaders/ColorFragmentShader.fragmentshader)

configure_file(shaders/TransformVertexShader.vertexshader shaders/TransformVertexShader.vertexshader COPYONLY)
configure_file(shaders/ColorFragmentShader.fragmentshader shaders/ColorFragmentShader.fragmentshader COPYONLY)

target_link_libraries(GlHash
        ${ALL_LIBS})
# Xcode and Visual working directories
set_target_properties(GlHash PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tutorial04_colored_cube/")
