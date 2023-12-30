//
// Created by Joyce on 2023/12/30.
//

#include "LightingCubeYellow.h"
const int numCubes1 = 18;
const float cubeSpacing1 = 2.0f;

float cubePositions1[numCubes1 * 3];
float vertices1[] = {
        -0.5f, -0.5f, -0.5f, 1, 0.647, 0,
        0.5f, -0.5f, -0.5f, 1, 0.647, 0,
        0.5f, 0.5f, -0.5f, 1, 0.647, 0,
        0.5f, 0.5f, -0.5f, 1, 0.647, 0,
        -0.5f, 0.5f, -0.5f, 1, 0.647, 0,
        -0.5f, -0.5f, -0.5f, 1, 0.647, 0,

        -0.5f, -0.5f, 0.5f, 1, 0.647, 0,
        0.5f, -0.5f, 0.5f, 1, 0.647, 0,
        0.5f, 0.5f, 0.5f, 1, 0.647, 0,
        0.5f, 0.5f, 0.5f, 1, 0.647, 0,
        -0.5f, 0.5f, 0.5f, 1, 0.647, 0,
        -0.5f, -0.5f, 0.5f, 1, 0.647, 0,

        -0.5f, 0.5f, 0.5f, 1, 0.647, 0,
        -0.5f, 0.5f, -0.5f, 1, 0.647, 0,
        -0.5f, -0.5f, -0.5f, 1, 0.647, 0,
        -0.5f, -0.5f, -0.5f, 1, 0.647, 0,
        -0.5f, -0.5f, 0.5f, 1, 0.647, 0,
        -0.5f, 0.5f, 0.5f, 1, 0.647, 0,

        0.5f, 0.5f, 0.5f, 1, 0.647, 0,
        0.5f, 0.5f, -0.5f, 1, 0.647, 0,
        0.5f, -0.5f, -0.5f, 1, 0.647, 0,
        0.5f, -0.5f, -0.5f, 1, 0.647, 0,
        0.5f, -0.5f, 0.5f, 1, 0.647, 0,
        0.5f, 0.5f, 0.5f, 1, 0.647, 0,

        -0.5f, -0.5f, -0.5f, 1, 0.647, 0,
        0.5f, -0.5f, -0.5f, 1, 0.647, 0,
        0.5f, -0.5f, 0.5f, 1, 0.647, 0,
        0.5f, -0.5f, 0.5f, 1, 0.647, 0,
        -0.5f, -0.5f, 0.5f, 1, 0.647, 0,
        -0.5f, -0.5f, -0.5f, 1, 0.647, 0,

        -0.5f, 0.5f, -0.5f, 1, 0.647, 0,
        0.5f, 0.5f, -0.5f, 1, 0.647, 0,
        0.5f, 0.5f, 0.5f, 1, 0.647, 0,
        0.5f, 0.5f, 0.5f, 1, 0.647, 0,
        -0.5f, 0.5f, 0.5f, 1, 0.647, 0,
        -0.5f, 0.5f, -0.5f, 1, 0.647, 0
};
void calculateCubePositions1() {
    for (int i = 0; i < numCubes1; ++i) {
        float phi = acos(1 - 2.0f * i / (numCubes1 - 1));
        float theta = M_PI * (1 + sqrt(5.0f)) * i;

        float x = cubeSpacing1 * sin(phi) * cos(theta);
        float y = cubeSpacing1 * sin(phi) * sin(theta);
        float z = cubeSpacing1 * cos(phi);

        cubePositions1[i * 3] = x;
        cubePositions1[i * 3 + 1] = y;
        cubePositions1[i * 3 + 2] = z;
    }
}

const int numVertices1 = 36;  // 顶点数量
float verticesAll1[36* 18 * 6];  // 原始顶点数组
float transformedVertices1[36* 18 * 6];  // 存储变换后的顶点数组



LightingCubeYellow::LightingCubeYellow(Camera* c, glm::mat4 *p) : RenderObject(c, p) {
    shader = new Shader("shaders/ground.vert", "shaders/ground.frag");

    for (int copyIndex = 0; copyIndex < numCubes1; ++copyIndex) {
        for (int i = 0; i < numVertices1; ++i) {
            int srcIndex = i * 6;
            int destIndex = (copyIndex * numVertices1 + i) * 6;

            for (int j = 0; j < 6; ++j) {
                verticesAll1[destIndex + j] = vertices1[srcIndex + j];
            }
        }
    }
    calculateCubePositions1();
    for (int i = 0; i < numCubes1; ++i) {
        for(int j =0; j < numVertices1; ++j) {
            int vertexIndex = i * 36 * 6 + j * 6;
            transformedVertices1[vertexIndex] = getScale()[0]*(verticesAll1[vertexIndex] + cubePositions1[i * 3]);
            transformedVertices1[vertexIndex + 1] = getScale()[1]*(verticesAll1[vertexIndex + 1] +cubePositions1[i * 3 + 1]);
            transformedVertices1[vertexIndex + 2] = getScale()[2]*(verticesAll1[vertexIndex + 2] + cubePositions1[i * 3 + 2]);
            transformedVertices1[vertexIndex + 3] = verticesAll1[vertexIndex + 3]*getScale()[2]*3;
            transformedVertices1[vertexIndex + 4] = verticesAll1[vertexIndex + 4]*getScale()[2]*3;
            transformedVertices1[vertexIndex + 5] = verticesAll1[vertexIndex + 5]*getScale()[2]*3;
        }
    }

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(transformedVertices1), transformedVertices1, GL_STREAM_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void LightingCubeYellow::render() {

    for (int copyIndex = 0; copyIndex < numCubes1; ++copyIndex) {
        for (int i = 0; i < numVertices1; ++i) {
            int srcIndex = i * 6;
            int destIndex = (copyIndex * numVertices1 + i) * 6;

            for (int j = 0; j < 6; ++j) {
                verticesAll1[destIndex + j] = vertices1[srcIndex + j];
            }
        }
    }
    calculateCubePositions1();
    for (int i = 0; i < numCubes1; ++i) {
        for(int j =0; j < numVertices1; ++j) {
            int vertexIndex = i * 36 * 6 + j * 6;
            transformedVertices1[vertexIndex] = getScale()[0]*(verticesAll1[vertexIndex] + cubePositions1[i * 3]);
            transformedVertices1[vertexIndex + 1] = getScale()[1]*(verticesAll1[vertexIndex + 1] +cubePositions1[i * 3 + 1]);
            transformedVertices1[vertexIndex + 2] = getScale()[2]*(verticesAll1[vertexIndex + 2] + cubePositions1[i * 3 + 2]);
            transformedVertices1[vertexIndex + 3] = verticesAll1[vertexIndex + 3]*getScale()[2]*3;
            transformedVertices1[vertexIndex + 4] = verticesAll1[vertexIndex + 4]*getScale()[2]*3;
            transformedVertices1[vertexIndex + 5] = verticesAll1[vertexIndex + 5]*getScale()[2]*3;
        }
    }

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(transformedVertices1), transformedVertices1);

    shader->use();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, this->getPosition());
    model = glm::rotate(model, (float) getCurrentTime(), rotate);
    shader->setMat4("model", model);
    setVPMatrix();

    // render box
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36*18);
}

void LightingCubeYellow::setRotate(const glm::vec3 &rotate) {
    LightingCubeYellow::rotate = rotate;
}

