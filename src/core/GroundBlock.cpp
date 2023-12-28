//
// Created by York Wu on 2023/12/21.
//

#include <GroundBlock.h>
#include <cmath>

void GroundBlock::init(float s, float r) {
    genBuffer(innerVAO, innerVBO);
    this->shader = new Shader("shaders/ground.vert", "shaders/ground.frag");
    animateRate = 0.01f;
    animateSpeed = 0.5f;
    isAnimate = false;
    scale = s, radius = r;

    float red = 0.8f, green = 0.8f, blue = 0.8f;
    float x = s * (0.5f - r), y = s * 0.5f;
    float outerPolygon[] = {
            x, y, 0.0f, red, green, blue,
            -x, y, 0.0f, red, green, blue,
            -y, x, 0.0f, red, green, blue,
            -y, -x, 0.0f, red, green, blue,
            -x, -y, 0.0f, red, green, blue,
            x, -y, 0.0f, red, green, blue,
            y, -x, 0.0f, red, green, blue,
            y, x, 0.0f, red, green, blue,
    };
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(outerPolygon), outerPolygon, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    x *= 0.8f, y *= 0.8f;
    float innerPolygon[] = {
            x, y, 0.0f, red, green, blue,
            -x, y, 0.0f, red, green, blue,
            -y, x, 0.0f, red, green, blue,
            -y, -x, 0.0f, red, green, blue,
            -x, -y, 0.0f, red, green, blue,
            x, -y, 0.0f, red, green, blue,
            y, -x, 0.0f, red, green, blue,
            y, x, 0.0f, red, green, blue,
    };

    glBindVertexArray(innerVAO);

    glBindBuffer(GL_ARRAY_BUFFER, innerVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(innerPolygon), innerPolygon, GL_DYNAMIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

GroundBlock::GroundBlock(Camera* c, glm::mat4 *p) : RenderObject(c, p) {
    init(1.0f, 0.1f);
}

GroundBlock::GroundBlock(Camera* c, glm::mat4 *p, float scale, float radius) : RenderObject(c, p) {
    init(scale, radius);
}

void GroundBlock::render() {
    // draw outer border
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    shader->use();
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, this->getPosition());
    model = glm::rotate(model, (float)M_PI/2, glm::vec3(1.0f, 0.0f, 0.0f));
    shader->setMat4("model", model);
    setVPMatrix();

    glDrawArrays(GL_LINE_LOOP, 0, 8);
    glBindVertexArray(0);

    // draw inner animate border
    if (isAnimate) {
        glBindVertexArray(innerVAO);
        glBindBuffer(GL_ARRAY_BUFFER, innerVBO);

        float x = scale * (0.5f - radius), y = scale * 0.5f;
        x *= animateRate, y *= animateRate;
        if (animateRate >= 1.0f) {
            isAnimate = false;
        }
        animateRate += getDeltaTime() * animateSpeed;
        float red = 0.8f, green = 0.8f, blue = 0.8f;
        float innerPolygon[] = {
                x, y, 0.0f, red, green, blue,
                -x, y, 0.0f, red, green, blue,
                -y, x, 0.0f, red, green, blue,
                -y, -x, 0.0f, red, green, blue,
                -x, -y, 0.0f, red, green, blue,
                x, -y, 0.0f, red, green, blue,
                y, -x, 0.0f, red, green, blue,
                y, x, 0.0f, red, green, blue,
        };

        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(innerPolygon), innerPolygon);
        shader->use();
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, this->getPosition());
        model = glm::rotate(model, (float)M_PI/2, glm::vec3(1.0f, 0.0f, 0.0f));
        shader->setMat4("model", model);
        setVPMatrix();
        glDrawArrays(GL_LINE_LOOP, 0, 8);
    }
}

void GroundBlock::emitAnimate() {
    isAnimate = true;
    animateRate = 0.0001f;
}

void GroundBlock::setInBlock(bool inBlock) {
    if (this->inBlock == false && inBlock == true) {
        emitAnimate();
    }
    this->inBlock = inBlock;
}

void GroundBlock::setAnimateSpeed(float animateSpeed) {
    GroundBlock::animateSpeed = animateSpeed;
}
