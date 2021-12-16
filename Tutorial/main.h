#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "init.h"
#include "render.h"

void error_callback(int, const char*);
void framebuffer_size_callback(GLFWwindow*, int, int);
void processInput(GLFWwindow *window);