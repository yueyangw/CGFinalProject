//
// Created by York Wu on 2023/12/27.
//

#include <core/Booth.h>

Booth::Booth(Camera *c, glm::mat4 *p, RenderObject *renderObject1) : RenderObject(c, p){
    glm::vec3 position(0.0f, 0.0f, 0.0f), scale(1.0f, 1.0f, 1.0f);
    base = new Base(c, p);
    base->setPosition(position);
    base->setScale(scale);
    setRenderObject(renderObject1);
    setPosition(position);
    setScale(scale);
    floatSpeed = 1.0;
    floatRange = 0.1;
}

void Booth::render() {
    base->render();
    glm::vec3 pos = objPosition;
    pos.y += glm::sin(getCurrentTime() * floatSpeed) * floatRange;
    renderObject->setPosition(pos);
    renderObject->setDeltaTime(getDeltaTime());
    renderObject->setCurrentTime(getCurrentTime());
    renderObject->render();
}

double Booth::getFloatSpeed() const {
    return floatSpeed;
}

void Booth::setObjPosition(const glm::vec3 &objPosition) {
    Booth::objPosition = objPosition;
}

void Booth::setRenderObject(RenderObject *renderObject) {
    Booth::renderObject = renderObject;
    if (renderObject->getPosition() == glm::vec3(0.0f, 0.0f, 0.0f)) {
        objPosition = getPosition();
        objPosition.y += 1.0f;
    } else {
        objPosition = renderObject->getPosition();
    }
}

void Booth::setPosition(const glm::vec3 &position) {
    base->setPosition(position);
    RenderObject::setPosition(position);
}

void Booth::setScale(const glm::vec3 &scale) {
    base->setScale(scale);
    RenderObject::setScale(scale);
}

void Booth::setFloatSpeed(double floatSpeed) {
    Booth::floatSpeed = floatSpeed;
}

double Booth::getFloatRange() const {
    return floatRange;
}

void Booth::setFloatRange(double floatRange) {
    Booth::floatRange = floatRange;
}
