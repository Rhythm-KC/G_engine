#ifndef VERTEX_LAYOUT_H
#define VERTEX_LAYOUT_H

#include <vector>
#include <GLFW/glfw3.h>

#include "Render/OpenGL/OpenGLRenderer.h"

struct VertexBufferLayoutElement{
    unsigned int type;
    unsigned int count;
    bool normalized;

    static unsigned int getSizeOfLayoutType(unsigned int type){
        switch(type){
            case GL_FLOAT: return 4;
            case GL_UNSIGNED_INT: return 4;
            case GL_UNSIGNED_BYTE: return 1;
        };
        ASSERT(false);
        return 0;
    }
};
class VertexBufferLayout{
    private:
        std::vector<VertexBufferLayoutElement> m_elements;
        unsigned int m_stride;
    public:
        template<typename T>
        void push(unsigned int count){
            static_assert(sizeof(T) ==0, "Unsupported version of push");
        }

        template<>
        void push<float>(unsigned int count){
            m_elements.push_back({GL_FLOAT, count, false});
            m_stride += count * VertexBufferLayoutElement::getSizeOfLayoutType(GL_FLOAT);
        }

        template<>
        void push<unsigned int>(unsigned int count){
            m_elements.push_back({GL_UNSIGNED_INT, count, false});
            m_stride += count * VertexBufferLayoutElement::getSizeOfLayoutType(GL_UNSIGNED_INT);
        }

        template<>
        void push<unsigned char>(unsigned int count){
            m_elements.push_back({GL_UNSIGNED_BYTE, count, true});
            m_stride += count * VertexBufferLayoutElement::getSizeOfLayoutType(GL_UNSIGNED_BYTE);
        }

        const std::vector<VertexBufferLayoutElement> getElements() const;
        const unsigned int getStride() const;
};

#endif