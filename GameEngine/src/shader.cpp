#include "shader.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "renderer.h"

shader::shader(const std::string& filepath)
    : m_FilePath(filepath), m_RendererID(0)
{
    
    ShaderProgramSource source = parseShader(filepath);
    // std::cout << "VERTEX" << std::endl;
    // std::cout << source.VertexSource << std::endl;
    // std::cout << "FRAGMENT" << std::endl;
    // std::cout << source.FragmentSource << std::endl;

    m_RendererID = createShader(source.VertexSource, source.FragmentSource);
}

shader::~shader()
{
    GLCall(glDeleteProgram(m_RendererID));
}

ShaderProgramSource shader::parseShader(const std::string& filepath)
{
    std::ifstream stream(filepath);
    
    //Checks if file can be read
    if(stream.fail()){
        std::cerr << "Error:" << strerror(errno);
    }

    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    while(getline(stream, line))
    {
        if(line.find("#shader") != std::string::npos)
        {
            if(line.find("vertex") != std::string::npos)
                type = ShaderType::VERTEX;
            else if(line.find("fragment") != std::string::npos)
                type = ShaderType::FRAGMENT;
        }
        else
        {
            ss[(int)type] << line << '\n';
        }

    }
    return { ss[0].str(), ss[1].str() };
}

unsigned int shader::compileShader(unsigned int type, const std::string& source)
{
    GLCall(unsigned int id = glCreateShader(type));
    const char* src = source.c_str();
    GLCall(glShaderSource(id, 1, &src, nullptr));
    GLCall(glCompileShader(id));

    //Error handling
    int result;
    GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
    if (result == GL_FALSE){
        int length;
        GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
        char* message = (char*)malloc(length * sizeof(char));
        GLCall(glGetShaderInfoLog(id, length, &length, message));
        std::cout << "Failed to compile shader! " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")<< std::endl;
        std::cout << message << std::endl;
        GLCall(glDeleteShader(id));
        return 0;
    }

    return id;
}

unsigned int shader::createShader(const std:: string& vertexShader, const std::string& fragmentShader)
{
    GLCall(unsigned int program = glCreateProgram());
    GLCall(unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader));
    GLCall(unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader));

    GLCall(glAttachShader(program, vs));
    GLCall(glAttachShader(program, fs));
    GLCall(glLinkProgram(program));
    GLCall(glValidateProgram(program));

    GLCall(glDeleteShader(vs));
    GLCall(glDeleteShader(fs));

    return program;
}

void shader::Bind() const
{
    GLCall(glUseProgram(m_RendererID));
}

void shader::Unbind() const
{
    GLCall(glUseProgram(0));
}

void shader::setUniforms1i(const std::string& name, int value)
{
    //Can't use GLCall here due to Assert error I think
    GLCall(glUniform1i(getUniformLocation(name), value));
}

void shader::setUniforms1f(const std::string& name, float value)
{
    GLCall(glUniform1f(getUniformLocation(name), value));
}

void shader::setUniforms4f(const std::string& name,float v0, float v1, float v2, float v3)
{
    GLCall(glUniform4f(getUniformLocation(name), v0, v1, v2, v3));
}

void shader::setUniformsMat4f(const std::string& name, const glm::mat4& matrix)
{
    GLCall(glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]));
}

int shader::getUniformLocation(const std::string& name)
{
    if(m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
        return m_UniformLocationCache[name];

    GLCall(int location = glGetUniformLocation(m_RendererID, name.c_str()));
    if (location == -1)
        std::cout << "Warning: uniform " << name << "doesn't exist!" << std::endl;
    m_UniformLocationCache[name] = location;
    return location;
}