//
// Created by York Wu on 2023/12/27.
//

#ifndef PROJECT_BOOTH_H
#define PROJECT_BOOTH_H

#include <core/renderObject.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <utils/shader.h>
#include <core/base.h>

class Booth : public RenderObject{
private:
    RenderObject *renderObject;
    Base *base;
    glm::vec3 objPosition;
    double floatSpeed, floatRange;

public:
    Booth(Camera *c, glm::mat4 *p, RenderObject *renderObject1);
    ~Booth();
    void render() override;

    void setPosition(const glm::vec3 &position) override;
    void setScale(const glm::vec3 &scale) override;

    void setRenderObject(RenderObject *renderObject);

    double getFloatSpeed() const;

    void setFloatSpeed(double floatSpeed);

    double getFloatRange() const;

    void setFloatRange(double floatRange);

    void setObjPosition(const glm::vec3 &objPosition);
};


#endif //PROJECT_BOOTH_H
