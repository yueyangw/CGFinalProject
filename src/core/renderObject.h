//
// Created by York Wu on 2023/12/18.
//

#ifndef PROJECT_RENDEROBJECT_H
#define PROJECT_RENDEROBJECT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <utils/camera.h>
#include <utils/shader.h>

class RenderObject {
private:
    int typeId;
    double deltaTime;
    glm::vec3 position, scale;

public:
    unsigned int VAO, VBO;

    glm::mat4 *projection;

    Shader *shader;

    Camera *camera;

protected:
    void setVPMatrix();

public:
    RenderObject(Camera *, glm::mat4 *p);

    virtual void render() = 0;

    virtual ~RenderObject();

    const glm::vec3 &getPosition() const;

    void setPosition(const glm::vec3 &position);

    const glm::vec3 &getScale() const;

    void setScale(const glm::vec3 &scale);

    void genBuffer(unsigned int &VAO, unsigned int &VBO);

    double getDeltaTime() const;

    void setDeltaTime(double deltaTime);

};


#endif //PROJECT_RENDEROBJECT_H
