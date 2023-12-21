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
    Shader* shader;
    unsigned int innerVAO, innerVBO;
    float animateRate;
    int animateDir;
    bool isAnimate;

public:
    GroundBlock();
    GroundBlock(float scale, float radius);
    void render() override;

    void setIsAnimate(bool isAnimate);

    Shader* getShader();
};


#endif //PROJECT_GROUNDBLOCK_H
