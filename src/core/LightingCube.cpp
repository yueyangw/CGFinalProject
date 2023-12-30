//
// Created by Joyce on 2023/12/22.
//
#include <core/LightingCube.h>
const int numCubes = 18;
const float cubeSpacing = 2.0f;

float cubePositions[numCubes * 3];
float vertices[] = {
        -0.5f, -0.5f, -0.5f, 0.1176,0.5647,1.0,
        0.5f, -0.5f, -0.5f, 0.1176,0.5647,1.0,
        0.5f, 0.5f, -0.5f, 0.1176,0.5647,1.0,
        0.5f, 0.5f, -0.5f, 0.1176,0.5647,1.0,
        -0.5f, 0.5f, -0.5f, 0.1176,0.5647,1.0,
        -0.5f, -0.5f, -0.5f, 0.1176,0.5647,1.0,

        -0.5f, -0.5f, 0.5f, 0.1176,0.5647,1.0,
        0.5f, -0.5f, 0.5f, 0.1176,0.5647,1.0,
        0.5f, 0.5f, 0.5f, 0.1176,0.5647,1.0,
        0.5f, 0.5f, 0.5f, 0.1176,0.5647,1.0,
        -0.5f, 0.5f, 0.5f, 0.1176,0.5647,1.0,
        -0.5f, -0.5f, 0.5f, 0.1176,0.5647,1.0,

        -0.5f, 0.5f, 0.5f, 0.1176,0.5647,1.0,
        -0.5f, 0.5f, -0.5f, 0.1176,0.5647,1.0,
        -0.5f, -0.5f, -0.5f, 0.1176,0.5647,1.0,
        -0.5f, -0.5f, -0.5f, 0.1176,0.5647,1.0,
        -0.5f, -0.5f, 0.5f, 0.1176,0.5647,1.0,
        -0.5f, 0.5f, 0.5f, 0.1176,0.5647,1.0,

        0.5f, 0.5f, 0.5f, 0.1176,0.5647,1.0,
        0.5f, 0.5f, -0.5f, 0.1176,0.5647,1.0,
        0.5f, -0.5f, -0.5f, 0.1176,0.5647,1.0,
        0.5f, -0.5f, -0.5f, 0.1176,0.5647,1.0,
        0.5f, -0.5f, 0.5f, 0.1176,0.5647,1.0,
        0.5f, 0.5f, 0.5f, 0.1176,0.5647,1.0,

        -0.5f, -0.5f, -0.5f, 0.1176,0.5647,1.0,
        0.5f, -0.5f, -0.5f, 0.1176,0.5647,1.0,
        0.5f, -0.5f, 0.5f, 0.1176,0.5647,1.0,
        0.5f, -0.5f, 0.5f, 0.1176,0.5647,1.0,
        -0.5f, -0.5f, 0.5f, 0.1176,0.5647,1.0,
        -0.5f, -0.5f, -0.5f, 0.1176,0.5647,1.0,

        -0.5f, 0.5f, -0.5f, 0.1176,0.5647,1.0,
        0.5f, 0.5f, -0.5f, 0.1176,0.5647,1.0,
        0.5f, 0.5f, 0.5f, 0.1176,0.5647,1.0,
        0.5f, 0.5f, 0.5f, 0.1176,0.5647,1.0,
        -0.5f, 0.5f, 0.5f, 0.1176,0.5647,1.0,
        -0.5f, 0.5f, -0.5f, 0.1176,0.5647,1.0
};
void calculateCubePositions() {
    for (int i = 0; i < numCubes; ++i) {
        float phi = acos(1 - 2.0f * i / (numCubes - 1));
        float theta = M_PI * (1 + sqrt(5.0f)) * i;

        float x = cubeSpacing * sin(phi) * cos(theta);
        float y = cubeSpacing * sin(phi) * sin(theta);
        float z = cubeSpacing * cos(phi);

        cubePositions[i * 3] = x;
        cubePositions[i * 3 + 1] = y;
        cubePositions[i * 3 + 2] = z;
    }
}

const int numVertices = 36;  // 顶点数量
float verticesAll[36* 18 * 6];  // 原始顶点数组
float transformedVertices[36* 18 * 6];  // 存储变换后的顶点数组



LightingCube::LightingCube(Camera* c, glm::mat4 *p) : RenderObject(c, p) {
    shader = new Shader("shaders/ground.vert", "shaders/ground.frag");

    for (int copyIndex = 0; copyIndex < numCubes; ++copyIndex) {
        for (int i = 0; i < numVertices; ++i) {
            int srcIndex = i * 6;
            int destIndex = (copyIndex * numVertices + i) * 6;

            for (int j = 0; j < 6; ++j) {
                verticesAll[destIndex + j] = vertices[srcIndex + j];
            }
        }
    }
    calculateCubePositions();
    for (int i = 0; i < numCubes; ++i) {
        for(int j =0; j < numVertices; ++j) {
            int vertexIndex = i * 36 * 6 + j * 6;
            transformedVertices[vertexIndex] = getScale()[0]*(verticesAll[vertexIndex] + cubePositions[i * 3]);
            transformedVertices[vertexIndex + 1] = getScale()[1]*(verticesAll[vertexIndex + 1] +cubePositions[i * 3 + 1]);
            transformedVertices[vertexIndex + 2] = getScale()[2]*(verticesAll[vertexIndex + 2] + cubePositions[i * 3 + 2]);
            transformedVertices[vertexIndex + 3] = verticesAll[vertexIndex + 3]*getScale()[2]*3;
            transformedVertices[vertexIndex + 4] = verticesAll[vertexIndex + 4]*getScale()[2]*3;
            transformedVertices[vertexIndex + 5] = verticesAll[vertexIndex + 5]*getScale()[2]*3;
        }
    }

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(transformedVertices), transformedVertices, GL_STREAM_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void LightingCube::render() {

    for (int copyIndex = 0; copyIndex < numCubes; ++copyIndex) {
        for (int i = 0; i < numVertices; ++i) {
            int srcIndex = i * 6;
            int destIndex = (copyIndex * numVertices + i) * 6;

            for (int j = 0; j < 6; ++j) {
                verticesAll[destIndex + j] = vertices[srcIndex + j];
            }
        }
    }
    calculateCubePositions();
    for (int i = 0; i < numCubes; ++i) {
        for(int j =0; j < numVertices; ++j) {
            int vertexIndex = i * 36 * 6 + j * 6;
            transformedVertices[vertexIndex] = getScale()[0]*(verticesAll[vertexIndex] + cubePositions[i * 3]);
            transformedVertices[vertexIndex + 1] = getScale()[1]*(verticesAll[vertexIndex + 1] +cubePositions[i * 3 + 1]);
            transformedVertices[vertexIndex + 2] = getScale()[2]*(verticesAll[vertexIndex + 2] + cubePositions[i * 3 + 2]);
            transformedVertices[vertexIndex + 3] = verticesAll[vertexIndex + 3]*getScale()[2]*3;
            transformedVertices[vertexIndex + 4] = verticesAll[vertexIndex + 4]*getScale()[2]*3;
            transformedVertices[vertexIndex + 5] = verticesAll[vertexIndex + 5]*getScale()[2]*3;
        }
    }

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(transformedVertices), transformedVertices);

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

void LightingCube::setRotate(const glm::vec3 &rotate) {
    LightingCube::rotate = rotate;
}



