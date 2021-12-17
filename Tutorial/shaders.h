#include <glad/glad.h>
#include <GLFW/glfw3.h>

void createShaderProgram(unsigned int vertexShader, unsigned int shaderProgram);
void createShaderProgram(unsigned int vertexShader, const char *fragmentShaderSource, unsigned int shaderProgram);
void createVertexShader(unsigned int vertexShader);