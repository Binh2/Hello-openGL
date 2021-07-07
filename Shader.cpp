#include "Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };

    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use()
{
    glUseProgram(ID);
}
void Shader::setBool(const std::string& uniformName, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, uniformName.c_str()), (int)value);
}
void Shader::setInt(const std::string& uniformName, int value) const
{
    glUniform1i(glGetUniformLocation(ID, uniformName.c_str()), value);
}
void Shader::setFloat(const std::string& uniformName, float value) const
{
    glUniform1f(glGetUniformLocation(ID, uniformName.c_str()), value);
}
void Shader::setMat4(const std::string& uniformName, glm::mat4& matrix) const 
{
    glUniformMatrix4fv(glGetUniformLocation(ID, uniformName.c_str()), 1, GL_FALSE, glm::value_ptr(matrix));
}
void Shader::setVec3(const std::string& uniformName, glm::vec3& vec) const
{
    glUniform3fv(glGetUniformLocation(ID, uniformName.c_str()), 1, glm::value_ptr(vec));
}
void Shader::setVec3(const std::string& uniformName, float value1, float value2, float value3) const
{
    glUniform3fv(glGetUniformLocation(ID, uniformName.c_str()), 1, glm::value_ptr(glm::vec3(value1, value2, value3)));
}