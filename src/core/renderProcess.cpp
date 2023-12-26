//
// Created by York Wu on 2023/12/18.
//

#include <glad/glad.h>
#include <core/renderObject.h>
#include <core/renderProcess.h>
#include <core/base.h>
#include <core/Ground.h>
//#include <core/exampleCube.h>
#include <core/CubeGroup.h>
#include <core/MagmaBlock.h>

#include <core/skybox.h>
#include <core/bricks.h>

RenderProcess::RenderProcess(int w, int h, Camera *c) : windowWidth(w), windowHeight(h) {
    init(c, w, h);
    initObjects();
}

void RenderProcess::doRenderStep(double deltaTime, double currentTime) {
    this->deltaTime = deltaTime;
    this->currentTime = currentTime;

//    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    skybox->render();

    for (auto object: objectList) {
        object->setDeltaTime(deltaTime);
        object->setCurrentTime(currentTime);
        object->render();
    }
}

RenderProcess::~RenderProcess() {
    for (auto obj: objectList) {
        delete obj;
    }
}

void RenderProcess::updatePerspective(int w, int h) {
    this->windowWidth = w, this->windowHeight = h;
    *projection = glm::perspective(glm::radians(camera->Zoom), (float) w / (float) h, 0.1f, 100.0f);
}

void RenderProcess::init(Camera *c, int w, int h) {
    deltaTime = 0;
    camera = c;
    projection = new glm::mat4(glm::perspective(glm::radians(camera->Zoom), (float) w / (float) h, 0.1f, 100.0f));
    skybox = new Skybox(camera, projection);
}

void RenderProcess::initObjects() {
//    RenderObject* triangle = new Triangle();
//    GroundBlock* floor = new GroundBlock(camera, projection);
//    floor->setIsAnimate(true);
////    objectList.push_back(triangle);
//    objectList.push_back(floor);
    Ground *ground = new Ground(camera, projection);
    objectList.push_back(ground);
//    glm::vec3 cubePositions[] = {
//        glm::vec3( 0.0f,  0.0f,  0.0f),
//        glm::vec3( 2.0f,  5.0f, -15.0f),
//        glm::vec3(-1.5f, -2.2f, -2.5f),
//        glm::vec3(-3.8f, -2.0f, -12.3f),
//        glm::vec3( 2.4f, -0.4f, -3.5f),
//        glm::vec3(-1.7f,  3.0f, -7.5f),
//        glm::vec3( 1.3f, -2.0f, -2.5f),
//        glm::vec3( 1.5f,  2.0f, -2.5f),
//        glm::vec3( 1.5f,  0.2f, -1.5f),
//        glm::vec3(-1.3f,  1.0f, -1.5f)
//    };
//
//    CubeGroup* cube = new CubeGroup[10];
//    for (int i = 0; i < 10; i++) {
//        cube[i].setPosition(cubePositions[i]);
//        objectList.push_back(&cube[i]);
//    }
//    objectList.push_back(floor);
//    glm::vec3 cubePositions[] = {
//        glm::vec3( 0.0f,  0.0f,  0.0f),
//    };
//
////    CubeGroup* cube = new CubeGroup[10];
//    Base* base = new Base(camera, projection);
//    base->setPosition(cubePositions[0]);
//
//    CubeGroup* cube = new CubeGroup(camera, projection);
//    objectList.push_back(cube);

    Bricks* bricks = new Bricks(camera,projection);
    objectList.push_back(bricks);
//    MagmaBlock* magmaBlock = new MagmaBlock(camera, projection);
//    objectList.push_back(magmaBlock);
}
