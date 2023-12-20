//
// Created by York Wu on 2023/12/18.
//

#include <glad/glad.h>
#include <core/renderObject.h>
#include <core/renderProcess.h>
//#include <core/exampleTriangle.h>
#include <core/floor.h>

RenderProcess::RenderProcess(int w, int h) : windowWidth(w), windowHeight(h) {
    deltaTime = 0;
//    RenderObject* triangle = new Triangle();
    RenderObject* floor = new Floor();
//    objectList.push_back(triangle);
    objectList.push_back(floor);
}

void RenderProcess::doRenderStep(double d) {
    this->deltaTime = d;

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for(auto object : objectList) {
        object->render();
    }
}