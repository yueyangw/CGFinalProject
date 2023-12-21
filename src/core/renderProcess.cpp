//
// Created by York Wu on 2023/12/18.
//

#include <glad/glad.h>
#include <core/renderObject.h>
#include <core/renderProcess.h>
//#include <core/exampleTriangle.h>
//#include <core/floor.h>
#include <core/exampleCube.h>

RenderProcess::RenderProcess(int w, int h) : windowWidth(w), windowHeight(h) {
    deltaTime = 0;
//    RenderObject* triangle = new Triangle();
//    RenderObject* floor = new Floor();
//    objectList.push_back(triangle);
//    objectList.push_back(floor);
    glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    Cube* cube = new Cube[10];
    for (int i = 0; i < 10; i++) {
        cube[i].setPosition(cubePositions[i]);
        objectList.push_back(&cube[i]);
    }
}

void RenderProcess::doRenderStep(double d) {
    this->deltaTime = d;

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(auto object : objectList) {
        object->render();
    }
}

RenderProcess::~RenderProcess() {
    for (auto obj : objectList) {
        delete obj;
    }
}