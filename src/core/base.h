//
// Created by Joyce on 2023/12/18.
//

#ifndef PROJECT_EXAMPLECUBE_H
#define PROJECT_EXAMPLECUBE_H

#include <core/renderObject.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <utils/shader.h>

class Base : public RenderObject {
private:
    unsigned int texture1, texture2;

public:
    Base(Camera*, glm::mat4 *p);
    void render() override;
};

#endif  // PROJECT_EXAMPLECUBE_H
