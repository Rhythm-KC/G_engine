#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

class VertexBuffer{
    private:
        unsigned int m_renderID;

    public:
        VertexBuffer(const void* data, unsigned int size);
        ~VertexBuffer();

         void Bind() const;
         void Unbind() const;

};
#endif