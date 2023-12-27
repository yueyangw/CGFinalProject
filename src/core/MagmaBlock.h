//
// Created by York Wu on 2023/12/26.
//

#ifndef PROJECT_MAGMABLOCK_H
#define PROJECT_MAGMABLOCK_H

#include <core/renderObject.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <utils/shader.h>

class MagmaBlock : public RenderObject {
private:
    unsigned int texture, noiseTexture;

public:
    MagmaBlock(Camera *, glm::mat4 *);
    void render() override;
};


#endif //PROJECT_MAGMABLOCK_H
