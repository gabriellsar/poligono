#include "poligono.h"
#include <iostream>

PoligonoPtr Poligono::Make(const std::vector<Vertex> &vertices, const std::vector<uint32_t> &indices) {
    return PoligonoPtr(new Poligono(vertices, indices));
}

Poligono::Poligono(const std::vector<Vertex> &vertices, const std::vector<uint32_t> &indices) {
    if (vertices.size() < 3 || indices.empty()) return;

    m_index_count = static_cast<GLsizei>(indices.size());

    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);
    glGenBuffers(1, &m_ebo);

    glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint32_t), indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(
        0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void *>(offsetof(Vertex, position))
    );
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(
        1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void *>(offsetof(Vertex, color))
    );
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
    std::cout << "Poligono robusto criado (VAO ID: " << m_vao << ")" << std::endl;
}

Poligono::~Poligono() {
    std::cout << "Deletando Poligono robusto (VAO ID: " << m_vao << ")" << std::endl;

    // Libera todos os recursos da GPU
    glDeleteBuffers(1, &m_vbo);
    glDeleteBuffers(1, &m_ebo);
    glDeleteVertexArrays(1, &m_vao);
}

void Poligono::Draw() {
    if (m_vao == 0 || m_index_count == 0) return;

    glBindVertexArray(m_vao);
    glDrawElements(GL_TRIANGLES, m_index_count, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
