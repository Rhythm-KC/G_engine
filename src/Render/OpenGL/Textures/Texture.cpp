#include "Render/OpenGL/Textures/Texture.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <iostream>

#include "Render/OpenGL/OpenGLRenderer.h"

Texture::Texture(const std::string &file_path):
    m_renderID(0),
    m_localBuffer(nullptr),
    m_file_path(file_path),
    m_height(0), m_width(0), m_BBP(0)
{
    stbi_set_flip_vertically_on_load(true);
    m_localBuffer = stbi_load(file_path.c_str(), &m_width, &m_height, &m_BBP, 4);

    if(! m_localBuffer){
        std::cout << "Error loading texture" << std::endl;
    }

    GLCall(glGenTextures(1, &m_renderID));
    GLCall(glBindTexture(GL_TEXTURE_2D, m_renderID)); 

    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

    GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuffer));
    Unbind();

    if(m_localBuffer){
        stbi_image_free(m_localBuffer);
    }
}

Texture::~Texture()
{
    GLCall(glDeleteTextures(1, &m_renderID));
}

void Texture::Bind(unsigned int slot) const
{
    GLCall(glActiveTexture(GL_TEXTURE0 + slot));
    GLCall(glBindTexture(GL_TEXTURE_2D, m_renderID));
}

void Texture::Unbind() const
{
    GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}
