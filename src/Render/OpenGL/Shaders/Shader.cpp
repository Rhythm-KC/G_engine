#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "Render/OpenGL/Shaders/Shader.h"
#include "Render/OpenGL/OpenGLRenderer.h"


Shader::Shader(const std::string &filepath):
    m_filePath(filepath),
    m_renderID(0)
{

    auto shaders = parseShader(m_filePath);
    m_renderID = createShader(shaders.VertexSource, shaders.FragmentSource);
}

Shader::~Shader(){
    GLCall(glDeleteProgram(m_renderID));
}

void Shader::Bind() const{
    GLCall(glUseProgram(m_renderID));
}

void Shader::Unbind() const{
    GLCall(glUseProgram(0));
}

ShaderSource Shader::parseShader(const std::string &filePath){
    enum class ShaderType{
        None = -1, Vertex = 0, Fragment = 1
    };

    std::stringstream ss[2];
    std::ifstream stream(filePath);
    std::cout <<stream.is_open()<< std::endl;
    std::string line;
    ShaderType type = ShaderType::None;
    while(getline(stream, line)){
        if(line.find("#shader") != std::string::npos){
            if( line.find("vertex") != std::string::npos){
                type = ShaderType::Vertex;
            }
            if( line.find("fragment") != std::string::npos){
                type = ShaderType::Fragment;
            }
        }
        else{
            ss[(int) type] << line <<"\n";
        }
    }
    return {ss[0].str(), ss[1].str()};
}

unsigned int Shader::compileShader(const std::string &source, unsigned int type){

    unsigned int id = glCreateShader(type);
    const char* src_ptr = source.c_str();
    glShaderSource(id, 1, &src_ptr, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE){
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char *)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to complie shader: " << message << std::endl; 
        glDeleteShader(id);
        return 0;

    }
    
    return id;
}

unsigned int Shader::createShader(const std::string &vertexShader, const std::string &fragmentShader){
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(vertexShader, GL_VERTEX_SHADER);
    unsigned int fs = compileShader(fragmentShader, GL_FRAGMENT_SHADER);
    GLCall(glAttachShader(program, vs));
    GLCall(glAttachShader(program, fs));
    GLCall(glLinkProgram(program));
    GLCall(glValidateProgram(program));

    // we can delete the shaders as we have linked and validated the program
    GLCall(glDeleteShader(vs));
    GLCall(glDeleteShader(fs));

    return program;
}
void Shader::setUniform1i(const std::string &name, int i0)
{
    GLCall(glUniform1i(getUniformLocation(name), i0));
}
void Shader::setUniform4f(const std::string &name, float f0, float f1, float f2, float f3){
    GLCall(glUniform4f(getUniformLocation(name), f0, f1, f2, f3));

}
int Shader::getUniformLocation(const std::string &name){
    if (m_uniformCache.find(name) != m_uniformCache.end())
    {
        return m_uniformCache[name];
    }
    GLCall(int location = glGetUniformLocation(m_renderID, name.c_str()));
    if (location == -1){
        std::cout << "Warning: location " << name << " does not exist!" <<std::endl;
    }
    m_uniformCache[name] = location;
    return location;

}