#pragma once

#include <string>
#include <unordered_map>

struct ShaderProgramSource
{
    std::string vertexSource;
    std::string fragmentSource;
};

class Shader
{
private:
    std::string m_path;
    unsigned int m_shaderId;
    std::unordered_map<std::string, int> m_uniformLocationCache;
public:
    Shader(const std::string& path);
    ~Shader();

    void bind() const;
    void unbind() const;

    void setUniform1i(const std::string& name, int value);
    void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

private:
    ShaderProgramSource parseShader(const std::string& path);
    unsigned int compileShader(unsigned int type, const std::string& source);
    unsigned int createShader(const std::string& vertexSource, const std::string& fragmentSource);
    int getUniformLocation(const std::string& name);
};