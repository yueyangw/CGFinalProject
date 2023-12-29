//
// Created by York Wu on 2023/12/18.
//

#include <glad/glad.h>
#include <core/renderObject.h>

RenderObject::RenderObject(Camera* c, glm::mat4 *p) {
    camera = c;
    projection = p;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    position = glm::vec3(0.0f, 0.0f, 0.0f);
    scale = glm::vec3(1.0f, 1.0f, 1.0f);
}

RenderObject::~RenderObject() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    if (shader != nullptr) {
        delete shader;
    }
}

void RenderObject::setVPMatrix() {
    shader->setMat4("projection", *projection);
    glm::mat4 view = camera->GetViewMatrix();
    shader->setMat4("view", view);
}

void RenderObject::genBuffer(unsigned int &VAO, unsigned int &VBO) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
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

void RenderObject::setDeltaTime(double deltaTime) {
    RenderObject::deltaTime = deltaTime;
}

double RenderObject::getDeltaTime() const {
    return deltaTime;
}

double RenderObject::getCurrentTime() const {
    return currentTime;
}

void RenderObject::setCurrentTime(double currentTime) {
    RenderObject::currentTime = currentTime;
}
