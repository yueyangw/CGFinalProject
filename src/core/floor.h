

#ifndef PROJECT_FLOOR_H
#define PROJECT_FLOOR_H

#include "renderObject.h"
#include "utils/shader.h"
#include "3rd-party/glm/glm.hpp"
#include "3rd-party/glm/gtc/matrix_transform.hpp"
#include "3rd-party/glm/gtc/type_ptr.hpp"

class Floor : public RenderObject {
private:
    Shader* shader;

public:
    Floor();
    void render() override;
};


#endif //PROJECT_EXAMPLETRIANGLE_H
