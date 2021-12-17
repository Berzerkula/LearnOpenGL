#include "config.h"
#include "main.h"

#include <iostream>

using namespace std;

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *fragmentRedShaderSource = "#version 330 core\n"
	"out vec4 FragColor;\n"
	"\n"
	"void main()\n"
	"{\n"
	" FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
	"}\0";

const char *fragmentGreenShaderSource = "#version 330 core\n"
	"out vec4 FragColor;\n"
	"\n"
	"void main()\n"
	"{\n"
	" FragColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);\n"
	"}\0";

const char *fragmentYellowShaderSource = "#version 330 core\n"
	"out vec4 FragColor;\n"
	"\n"
	"void main()\n"
	"{\n"
	" FragColor = vec4(1.0f, 1.5f, 0.0f, 1.0f);\n"
	"}\0";


int main()
{
    glfwSetErrorCallback(error_callback);

    GLFWwindow *window = initWindow(SCR_WIDTH, SCR_HEIGHT);

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    createVertexShader(vertexShader, vertexShaderSource);

	unsigned int shaderRedProgram = glCreateProgram();
    unsigned int shaderGreenProgram = glCreateProgram();
    unsigned int shaderYellowProgram = glCreateProgram();
    createShaderProgram(vertexShader, fragmentRedShaderSource, shaderRedProgram);
    createShaderProgram(vertexShader, fragmentGreenShaderSource, shaderGreenProgram);
    createShaderProgram(vertexShader, fragmentYellowShaderSource, shaderYellowProgram);

    glDeleteShader(vertexShader);
    
    // For triangles
    float triangle_1[] = {
        -0.6f, -0.6f,  0.0f, // left
         0.0f, -0.6f,  0.0f, // right
        -0.3f,  0.3f,  0.0f  // top
    };

    float triangle_2[] = {
         0.0f, -0.6f,  0.0f, // left
         0.6f, -0.6f,  0.0f, // right
         0.3f,  0.3f,  0.0f  // top
    };

    // For rectangle
	float rectangle[] = {
         0.3f,  0.5f, 0.0f, // top right
	     0.3f,  0.3f, 0.0f, // bottom right
        -0.3f,  0.3f, 0.0f, // bottom left
        -0.3f,  0.5f, 0.0f  // top left
	};

     unsigned int indices[] = {
         0, 1, 3, // first triangle
         1, 2, 3  // second triangle
     };

    // Vertex Buffer Object, Vertex Array Object and Element Buffer Object
	unsigned int EBO, VAOs[3], VBOs[3];
	glGenVertexArrays(3, VAOs);
    glGenBuffers(3, VBOs);
    glGenBuffers(1, &EBO);

    // First triangle setup
	glBindVertexArray(VAOs[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_1), triangle_1, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

    // Second triangle setup
    glBindVertexArray(VAOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_2), triangle_2, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Rectangle setup
    glBindVertexArray(VAOs[2]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(rectangle), rectangle, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

    // Uncomment for wireframe polygons
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while(!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // rendering
        clearWithColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw First Trianagle as Red
        glUseProgram(shaderRedProgram);
        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        // Draw Second Triangle as Green
        glUseProgram(shaderGreenProgram);
        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Draw Rectangle as Yellow
        glUseProgram(shaderYellowProgram);
        glBindVertexArray(VAOs[2]);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    // Cleanup
    glDeleteVertexArrays(2, VAOs);
    glDeleteBuffers(2, VBOs);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderRedProgram);
    glDeleteProgram(shaderGreenProgram);
    glDeleteProgram(shaderYellowProgram);

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