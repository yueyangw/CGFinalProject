//
// Created by Joyce on 2023/12/22.
//
#include <core/LightingCube.h>
#include <stb_image.h>
#include <utils/filesystem.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
const int numCubes = 18;
const float cubeSpacing = 2.0f;

float cubePositions[numCubes * 3];
float vertices[] = {
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f
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
float verticesAll[36* 18 * 5];  // 原始顶点数组
float transformedVertices[36* 18 * 5];  // 存储变换后的顶点数组



LightingCube::LightingCube(Camera* c, glm::mat4 *p) : RenderObject(c, p) {

}

void LightingCube::render() {
    shader = new Shader("shaders/6.2.coordanite.vert", "shaders/6.2.coordanite.frag");

    for (int copyIndex = 0; copyIndex < numCubes; ++copyIndex) {
        for (int i = 0; i < numVertices; ++i) {
            int srcIndex = i * 5;
            int destIndex = (copyIndex * numVertices + i) * 5;

            for (int j = 0; j < 5; ++j) {
                verticesAll[destIndex + j] = vertices[srcIndex + j];
            }
        }
    }
    printf("%lf",getScale()[0]);
    calculateCubePositions();
    for (int i = 0; i < numCubes; ++i) {
        for(int j =0; j < numVertices; ++j) {
            int vertexIndex = i * 36 * 5 + j * 5;
            transformedVertices[vertexIndex] = getScale()[0]*(verticesAll[vertexIndex] + cubePositions[i * 3]);
            transformedVertices[vertexIndex + 1] = getScale()[1]*(verticesAll[vertexIndex + 1] +cubePositions[i * 3 + 1]);
            transformedVertices[vertexIndex + 2] = getScale()[2]*(verticesAll[vertexIndex + 2] + cubePositions[i * 3 + 2]);
            transformedVertices[vertexIndex + 3] = getScale()[0]*(verticesAll[vertexIndex + 3]);  // 复制纹理坐标 u
            transformedVertices[vertexIndex + 4] = getScale()[1]*(verticesAll[vertexIndex + 4]);  // 复制纹理坐标 v
        }
    }




    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(transformedVertices), transformedVertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // texture 1
    // ---------
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    unsigned char *data = stbi_load("resources/textures/container.jpg", &width, &height,
                                    &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    shader->use();
    shader->setInt("texture1", 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);



    shader->use();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, this->getPosition());
    model = glm::rotate(model, (float) glfwGetTime(), rotate);
    shader->setMat4("model", model);
    setVPMatrix();

    // render box
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36*18);
}

void LightingCube::setRotate(const glm::vec3 &rotate) {
    LightingCube::rotate = rotate;
}



