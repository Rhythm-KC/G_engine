#include "Render/OpenGL/Buffers/VertexBufferLayout.h"
#include <vector>

const std::vector<VertexBufferLayoutElement> VertexBufferLayout::getElements() const{
    return m_elements;
}

const unsigned int VertexBufferLayout::getStride() const{
    return m_stride;
}