#include "Render/OpenGL/Buffers/VertexBuffer.h"
#include "Render/OpenGL/OpenGLRenderer.h"

#include <GLFW/glfw3.h>


VertexBuffer::VertexBuffer(const void * data, unsigned int size){
    GLCall(glGenBuffers(1, &m_renderID));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_renderID));
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer(){
    GLCall(glDeleteBuffers(1, &m_renderID));
}

void VertexBuffer::Bind() const{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_renderID));
}

void VertexBuffer::Unbind() const{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}