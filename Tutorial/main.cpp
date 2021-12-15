#include "config.h"
#include "main.h"

#include <iostream>

using namespace std;

int main()
{
    glfwSetErrorCallback(error_callback);

    GLFWwindow *window = initWindow(SCR_WIDTH, SCR_HEIGHT);

    while(!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // rendering
        clearWithColor(0.2f, 0.3f, 0.3f, 1.0f);

        // check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void error_callback(int error, const char *msg)
{
    string s;
    s = "[" + to_string(error) + "] " + msg + '\n';
    cerr << s << endl;
}