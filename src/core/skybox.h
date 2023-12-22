//
// Created by York Wu on 2023/12/22.
//

#ifndef PROJECT_SKYBOX_H
#define PROJECT_SKYBOX_H

#include <core/renderObject.h>

class Skybox : public RenderObject {
private:
    Camera *camera;
    unsigned int cubeMapTexture;
    unsigned int loadCubeMap(std::vector<std::string> faces);

public:
    Skybox(Camera *c, glm::mat4 *p);
    void render();
};


#endif //PROJECT_SKYBOX_H
