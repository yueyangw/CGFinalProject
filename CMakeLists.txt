cmake_minimum_required(VERSION 3.23)
project(Project)

set(GLFW_H /opt/homebrew/Cellar/glfw/3.3.8/include)
set(GLEW_H /opt/homebrew/Cellar/glew/2.2.0_1/include)
include_directories(/usr/local/include ${GLFW_H} ${GLEW_H})

set(GLFW_LINK /opt/homebrew/Cellar/glfw/3.3.8/lib/libglfw.3.dylib)
set(GLEW_LINK /opt/homebrew/Cellar/glew/2.2.0_1/lib/libGLEW.2.2.dylib)
link_libraries(${GLFW_LINK} ${GLEW_LINK})

set(CMAKE_CXX_STANDARD 17)

#set(src_LIB src/3rd-party/*)
# 配置第三方库
file(GLOB_RECURSE src_LIB src/3rd-party/*)
add_library(LIB STATIC ${src_LIB})

# 配置核心代码
file(GLOB_RECURSE src_Core src/core/* src/utils/*)

include_directories(./src/ ./src/core/ ./src/3rd-party)

add_executable(Project src/main.cpp ${src_Core})
target_link_libraries(Project LIB)

# 构建时复制Shader
set(SHADER_SOURCE_DIR \"${CMAKE_SOURCE_DIR}/src/shaders\")
set(SHADER_BINARY_DIR \"${CMAKE_BINARY_DIR}/shaders\")
add_custom_target(CopyShaders ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${SHADER_SOURCE_DIR}
        ${SHADER_BINARY_DIR}
)
add_dependencies(Project CopyShaders)

# 构建时复制资源
set(RESOURCES_SOURCE_DIR \"${CMAKE_SOURCE_DIR}/src/resources\")
set(RESOURCES_BINARY_DIR \"${CMAKE_BINARY_DIR}/resources\")
add_custom_target(CopyResources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${RESOURCES_SOURCE_DIR}
        ${RESOURCES_BINARY_DIR}
)
add_dependencies(Project CopyResources)

# mac下链接库
target_link_libraries(Project "-framework OpenGL")
target_link_libraries(Project "-framework GLUT")
