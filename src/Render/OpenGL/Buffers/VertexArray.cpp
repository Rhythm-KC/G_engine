#include <glad/glad.h>

#include "Render/OpenGL/Buffers/VertexArray.h"
#include "Render/OpenGL/Buffers/VertexBufferLayout.h"
#include "Render/OpenGL/Buffers/VertexBuffer.h"
#include "Render/OpenGL/OpenGLRenderer.h"


VertexArray::VertexArray(){
    GLCall(glGenVertexArrays(1, &m_renderID));

}
VertexArray::~VertexArray(){
    GLCall(glDeleteVertexArrays(1, &m_renderID));
}

void VertexArray::Bind(){
    GLCall(glBindVertexArray(m_renderID));
}
void VertexArray::Unbind(){
    GLCall(glBindVertexArray(0));
}

void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout &layout)
{
    Bind();
    vb.Bind();
    const auto &elements = layout.getElements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i< elements.size(); i++){
        const auto &element = elements[i];
        GLCall(glEnableVertexAttribArray(i));
        GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), (void *) offset));
        offset += element.getSizeOfLayoutType(element.type) * element.count;
    };

}