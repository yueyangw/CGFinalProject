//
// Created by York Wu on 2023/12/21.
//

#ifndef PROJECT_GROUNDBLOCK_H
#define PROJECT_GROUNDBLOCK_H

#include <core/renderObject.h>
#include <utils/shader.h>

class GroundBlock : public RenderObject{
private:
    float scale, radius;
    unsigned int innerVAO, innerVBO;
    float animateRate;
    int animateDir;
    bool isAnimate;

public:
    GroundBlock(Camera*, glm::mat4 *projection);
    GroundBlock(Camera*, glm::mat4 *projection, float scale, float radius);
    void init(float, float);
    void render() override;

    void setIsAnimate(bool isAnimate);
};


#endif //PROJECT_GROUNDBLOCK_H
