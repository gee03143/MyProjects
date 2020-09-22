#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Shader.h"
#include "Triangle.h"
#include "Aabb.h"
#include "Circle.h"
#include "Camera.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    Shader shader("Shaders/vertex.txt", "Shaders/fragment.txt");
    Triangle triangle(glm::vec2(400.0, 300.0), glm::vec2(150.0, 150.0), glm::vec3(1.0, 0.5, 0.5));
    Triangle triangle2(glm::vec2(150.0, 450.0), glm::vec2(150.0, 150.0), glm::vec3(1.0, 1.0, 1.0));
    Aabb aabb(glm::vec2(700.0,100.0), glm::vec2(750.0, 500.0), glm::vec2(1.0, 1.0), glm::vec3(0.5, 0.5, 1.0));
    Circle circle(glm::vec2(600.0, 400.0), glm::vec2(1.0, 1.0), glm::vec3(0.5, 0.5, 1.0), 32.0f);

    Camera camera(glm::vec3(400.0, 300.0, 1000.0), (float)SCR_WIDTH , (float)SCR_HEIGHT, shader);
    
    //camera.SetPerspective(45.0f, -10.0f, 100.0f);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        triangle.Draw(&shader);
        triangle2.Draw(&shader);
        aabb.Draw(&shader);
        circle.Draw(&shader);

        //TODO : �ùķ��̼� ���� ����, ī�޶� ������ �����ϱ�

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}