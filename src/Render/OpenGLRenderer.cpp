#include "Render/OpenGLRenderer.h"
#include <GLFW/glfw3.h>
#include <iostream>

OpenGLRenderer::OpenGLRenderer() : window(nullptr){

}

OpenGLRenderer::~OpenGLRenderer()
{
    Cleanup();
}
void error_callback(int err, const char* description){
    fprintf(stderr, "Error: %s\n", description);
}
void OpenGLRenderer::Initialize(){

    if (!glfwInit()) {
        glfwSetErrorCallback(error_callback);
        return;
    }

    window = glfwCreateWindow(800, 600, "G_engine", NULL, NULL);
    if (!window) {
        glfwSetErrorCallback(error_callback);
        glfwTerminate();
        return;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    
    while(!glfwWindowShouldClose(window)){
        BeginFrame();
        EndFrame();
    };
    glfwTerminate();

}

void OpenGLRenderer::Cleanup(){
    if (window) {
        glfwDestroyWindow(window);
        window = nullptr;
    }
    glfwTerminate();
}

void OpenGLRenderer::BeginFrame() {
    if (window){
        glClear(GL_COLOR_BUFFER_BIT);
    }
}

void OpenGLRenderer::EndFrame() {
    if (window) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void OpenGLRenderer::DrawTriangle(float vertices[9])
{
    
}