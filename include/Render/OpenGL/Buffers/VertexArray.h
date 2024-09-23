#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include "Render/OpenGL/Buffers/VertexBuffer.h"
#include "Render/OpenGL/Buffers/VertexBufferLayout.h"

class VertexArray
{
    private:
        unsigned int m_renderID;
    public:
        VertexArray();
        ~VertexArray();
        void Bind();
        void Unbind();
        void addBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout);
};

#endif