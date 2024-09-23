#ifndef OPENGL_TEXTURES_H
#define OPENGL_TEXTURES_H

#include <string>

class Texture{
    private:
        unsigned int m_renderID;
        unsigned char* m_localBuffer;
        const std::string m_file_path;
        int m_width, m_height, m_BBP;

    public:
        Texture(const std::string &file_path);
        ~Texture();

        void Bind(unsigned int slot = 0) const;
        void Unbind() const;

};

#endif