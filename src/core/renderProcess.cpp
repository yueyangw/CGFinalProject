//
// Created by York Wu on 2023/12/18.
//

#include <glad/glad.h>
#include <core/renderObject.h>
#include <core/renderProcess.h>
//#include <core/exampleTriangle.h>
//#include <core/floor.h>
//#include <core/exampleCube.h>
#include <core/base.h>

RenderProcess::RenderProcess(int w, int h) : windowWidth(w), windowHeight(h) {
    deltaTime = 0;
//    RenderObject* triangle = new Triangle();
//    RenderObject* floor = new Floor();
//    objectList.push_back(triangle);
//    objectList.push_back(floor);
    glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
    };

//    Cube* cube = new Cube[10];
    Base* base = new Base[1];
    base->setPosition(cubePositions[0]);
    objectList.push_back(&base[0]);
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