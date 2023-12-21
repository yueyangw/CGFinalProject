//
// Created by York Wu on 2023/12/18.
//

#ifndef PROJECT_RENDEROBJECT_H
#define PROJECT_RENDEROBJECT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class RenderObject {
private:
    int typeId;
    glm::vec3 position, scale;

public:
    const glm::vec3 &getPosition() const;

    void setPosition(const glm::vec3 &position);

    const glm::vec3 &getScale() const;

    void setScale(const glm::vec3 &scale);

public:
    unsigned int VAO, VBO;

    RenderObject();
    virtual void render() = 0;
    virtual ~RenderObject();

};


#endif //PROJECT_RENDEROBJECT_H
