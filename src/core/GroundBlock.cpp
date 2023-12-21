//
// Created by York Wu on 2023/12/21.
//

#include <GroundBlock.h>

void GroundBlock::init(float s, float r) {
    genBuffer(innerVAO, innerVBO);
    this->shader = new Shader("shaders/ground.vert", "shaders/ground.frag");
    animateRate = 0.95f;
    animateDir = -1;
    isAnimate = false;
    scale = s, radius = r;

    float x = s * (0.5f - r), y = s * 0.5f;
    float outerPolygon[] = {
            x, y, 0.0f, 1.0f, 1.0f, 1.0f,
            -x, y, 0.0f, 1.0f, 1.0f, 1.0f,
            -y, x, 0.0f, 1.0f, 1.0f, 1.0f,
            -y, -x, 0.0f, 1.0f, 1.0f, 1.0f,
            -x, -y, 0.0f, 1.0f, 1.0f, 1.0f,
            x, -y, 0.0f, 1.0f, 1.0f, 1.0f,
            y, -x, 0.0f, 1.0f, 1.0f, 1.0f,
            y, x, 0.0f, 1.0f, 1.0f, 1.0f,
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
            x, y, 0.0f, 1.0f, 1.0f, 1.0f,
            -x, y, 0.0f, 1.0f, 1.0f, 1.0f,
            -y, x, 0.0f, 1.0f, 1.0f, 1.0f,
            -y, -x, 0.0f, 1.0f, 1.0f, 1.0f,
            -x, -y, 0.0f, 1.0f, 1.0f, 1.0f,
            x, -y, 0.0f, 1.0f, 1.0f, 1.0f,
            y, -x, 0.0f, 1.0f, 1.0f, 1.0f,
            y, x, 0.0f, 1.0f, 1.0f, 1.0f,
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

void GroundBlock::setIsAnimate(bool isAnimate) {
    GroundBlock::isAnimate = isAnimate;
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
        if (animateRate >= 0.95f) {
            animateDir = -1;
            animateRate = 0.95f;
        } else if (animateRate <= 0.2f) {
            animateDir = 1;
            animateRate = 0.2f;
        }
        animateRate += animateDir * getDeltaTime() * 0.2f;
        float innerPolygon[] = {
                x, y, 0.0f, 1.0f, 1.0f, 1.0f,
                -x, y, 0.0f, 1.0f, 1.0f, 1.0f,
                -y, x, 0.0f, 1.0f, 1.0f, 1.0f,
                -y, -x, 0.0f, 1.0f, 1.0f, 1.0f,
                -x, -y, 0.0f, 1.0f, 1.0f, 1.0f,
                x, -y, 0.0f, 1.0f, 1.0f, 1.0f,
                y, -x, 0.0f, 1.0f, 1.0f, 1.0f,
                y, x, 0.0f, 1.0f, 1.0f, 1.0f,
        };

        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(innerPolygon), innerPolygon);
        shader->use();
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, this->getPosition());
        shader->setMat4("model", model);
        setVPMatrix();
        glDrawArrays(GL_LINE_LOOP, 0, 8);
    }
}
