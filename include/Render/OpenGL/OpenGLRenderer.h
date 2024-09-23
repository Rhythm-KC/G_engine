#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include <GLFW/glfw3.h>

#include "Render/OpenGL/Buffers/IndexBuffer.h"
#include "Render/OpenGL/Buffers/VertexBuffer.h"
#include "Render/OpenGL/Shaders/Shader.h"

#define ASSERT(x) if(!(x)) __builtin_trap()
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();

bool GLLogCall(const char* func, const char* file_name, int line_no);

class OpenGLRenderer
{
    public:
        OpenGLRenderer();
        ~OpenGLRenderer();
        void Initialize() ;
        void draw(const VertexBuffer &vb, const IndexBuffer &ib, const Shader &shader) const;
        void clear() const;
    private:
        GLFWwindow* m_window;
};


#endif