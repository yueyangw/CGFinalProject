//
// Created by York Wu on 2023/12/18.
//

#ifndef PROJECT_EXAMPLETRIANGLE_H
#define PROJECT_EXAMPLETRIANGLE_H

#include <core/renderObject.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <utils/shader.h>

class Triangle : public RenderObject {
private:
    Shader* shader;

public:
    Triangle();
    void render() override;
    void calc();
};

#endif  // PROJECT_EXAMPLETRIANGLE_H
