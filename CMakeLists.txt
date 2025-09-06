cmake_minimum_required(VERSION 4.0)
project(poligono)

set(CMAKE_CXX_STANDARD 20)

set(GLFW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw/include)
set(GLAD_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/glad/include)
set(GLM_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/glm)
set(GLFW_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw/lib-mingw-w64)

set(APP_SOURCES
        main.cpp
        error.cpp
        shader.cpp
        triangle.cpp
        lib/glad/src/glad.c
        poligono.cpp
        poligono.h
        Vertex.h
)

add_subdirectory(lib/glm)

add_executable(poligono ${APP_SOURCES})

target_include_directories(poligono PUBLIC
        ${GLFW_INCLUDE_DIR}
        ${GLAD_INCLUDE_DIR}
        ${GLM_INCLUDE_DIR}
)

target_link_directories(poligono PUBLIC
        ${GLFW_LIBRARY_DIR}
)

target_link_libraries(poligono PUBLIC
        glfw3
        opengl32
        gdi32
)

