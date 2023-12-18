//
// Created by York Wu on 2023/12/18.
//

#include <glad/glad.h>
#include <core/renderObject.h>

RenderObject::RenderObject() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
}

RenderObject::~RenderObject() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}