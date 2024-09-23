#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include <string>
#include <unordered_map>

struct ShaderSource{
    std::string VertexSource;
    std::string FragmentSource;
};

class Shader
{
    private:
        unsigned int m_renderID;
        const std::string m_filePath;
        std::unordered_map<std::string, int> m_uniformCache;
        

        bool compileShader();
        unsigned int compileShader(const std::string &source, unsigned int type);
        unsigned int createShader(const std::string &vertexShader, const std::string &fragmentShader);
        ShaderSource parseShader(const std::string &filePath);
    public:
        Shader(const std::string &filepath);
        ~Shader();
        void Bind() const;
        void Unbind() const;
        void setUniform1i(const std::string &name, int i0);
        void setUniform4f(const std::string &name, float f0, float f1, float f2, float f3);
        int getUniformLocation(const std::string &name);


};
#endif