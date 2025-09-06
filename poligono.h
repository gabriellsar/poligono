#ifndef POLIGONO_POLIGONO_H
#define POLIGONO_POLIGONO_H
#pragma once

#include <memory>
#include <vector>
#include "shape.h"
#include "Vertex.h"

#ifdef _WIN32
#include <glad/glad.h>
#else
#include <OpenGL/gl3.h>
#endif

class Poligono;
using PoligonoPtr = std::shared_ptr<Poligono>;

class Poligono final : public Shape {
    GLuint m_vao = 0;
    GLuint m_vbo = 0;
    GLuint m_ebo = 0;
    GLsizei m_index_count = 0;

    explicit Poligono(const std::vector<Vertex> &vertices, const std::vector<uint32_t>& indices);

public:
    static PoligonoPtr Make(const std::vector<Vertex> &vertices, const std::vector<uint32_t>& indices);

    ~Poligono() override;

    void Draw() override;
};

#endif //POLIGONO_POLIGONO_H
