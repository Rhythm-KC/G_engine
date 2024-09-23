#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

class IndexBuffer{
    private:
        unsigned int m_renderID;
        unsigned int m_count;

    public:
        IndexBuffer(const unsigned int* data, unsigned int count);
        ~IndexBuffer();

        void Bind() const;
        void Unbind() const;
        unsigned int getCount() const;

};
#endif