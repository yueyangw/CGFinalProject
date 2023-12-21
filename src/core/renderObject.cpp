//
// Created by York Wu on 2023/12/18.
//

#include <glad/glad.h>
#include <core/renderObject.h>

RenderObject::RenderObject() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    position = glm::vec3(0.0f, 0.0f, 0.0f);
}

RenderObject::~RenderObject() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

const glm::vec3 &RenderObject::getPosition() const {
    return position;
}

void RenderObject::setPosition(const glm::vec3 &position) {
    RenderObject::position = position;
}

const glm::vec3 &RenderObject::getScale() const {
    return scale;
}

void RenderObject::setScale(const glm::vec3 &scale) {
    RenderObject::scale = scale;
}
