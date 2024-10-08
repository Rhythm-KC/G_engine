#include "Render/OpenGL/Buffers/IndexBuffer.h"
#include "Render/OpenGL/OpenGLRenderer.h"

#include <GLFW/glfw3.h>

IndexBuffer::IndexBuffer(const unsigned int * data, unsigned int count):
m_count(count)
{
    GLCall(glGenBuffers(1, &m_renderID));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderID));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer(){
    GLCall(glDeleteBuffers(1, &m_renderID));
}

void IndexBuffer::Bind() const{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderID));
}

void IndexBuffer::Unbind() const{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

unsigned int IndexBuffer::getCount() const{
    return m_count;
}