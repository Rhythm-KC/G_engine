#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Render/OpenGL/OpenGLRenderer.h"
#include "Render/OpenGL/Buffers/VertexBuffer.h"
#include "Render/OpenGL/Buffers/IndexBuffer.h"
#include "Render/OpenGL/Buffers/VertexArray.h"
#include "Render/OpenGL/Buffers/VertexBufferLayout.h"
#include "Render/OpenGL/Shaders/Shader.h"
#include "Render/OpenGL/Textures/Texture.h"

#include <stb_image.h>

void GLClearError(){
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* func, const char* file_name, int line_no){
    while ( unsigned int error = glGetError())
    {
        std::cout << "OpenGL Error (" 
                  << error <<  " in "<< file_name << " at " <<line_no << " for func " 
                  << func<<" )" << std::endl;
        return false;
    }
    return true;
    
}
OpenGLRenderer::OpenGLRenderer() : m_window(nullptr){

}

OpenGLRenderer::~OpenGLRenderer()
{
    if (m_window) {
        GLCall(glfwDestroyWindow(m_window));
        m_window = nullptr;
    }
    GLCall(glfwTerminate());
}
void error_callback(int err, const char* description){
    fprintf(stderr, "Error: %s\n", description);
}
void OpenGLRenderer::Initialize(){


    if (!glfwInit()) {
        glfwSetErrorCallback(error_callback);
        return;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Request OpenGL 3.x
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Request OpenGL 3.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(800, 600, "G_engine", NULL, NULL);
    if (!m_window) {
        glfwSetErrorCallback(error_callback);
        glfwTerminate();
        return;
    }


    // Make the window's context current
    glfwMakeContextCurrent(m_window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return;
    } 
    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    float positions[] = {
        -0.5, -0.5, 0.0f, 0.0f,
        0.5, -0.5, 1.0f, 0.0f,
        0.5, 0.5, 1.0f, 1.0f,
        -0.5, 0.5, 0.0f, 1.0f
    }; 
    unsigned int indices[6] = {0,1,2, 
    2,3,0};

    // creating the vertex buffer
    auto vb = VertexBuffer(positions, 16 * sizeof(float));
    vb.Bind();

    VertexArray va;
    VertexBufferLayout layout;
    layout.push<float>(2);
    layout.push<float>(2);
    va.addBuffer(vb, layout);

    auto ibo = IndexBuffer(indices, 6);

    auto basicShader = Shader("res/shader/basic.shader");
    basicShader.Bind();

    Texture texture("res/texture/brick.jpg");
    texture.Bind();
    basicShader.setUniform1i("u_Texture", 0);


    vb.Unbind();
    ibo.Unbind();
    basicShader.Unbind();

    while (m_window && !glfwWindowShouldClose(m_window)){
        draw(vb, ibo, basicShader);
        GLCall(glfwSwapBuffers(m_window));
        GLCall(glfwPollEvents());
        clear();
    }
}

void OpenGLRenderer::draw(const VertexBuffer &vb, const IndexBuffer &ib, const Shader &shader) const{
    ib.Bind();
    vb.Bind();
    shader.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr));
}
void OpenGLRenderer::clear() const{
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}