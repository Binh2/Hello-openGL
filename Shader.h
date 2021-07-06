
#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
    unsigned int ID;
    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
    void setBool(const std::string& uniformName, bool value) const;
    void setInt(const std::string& uniformName, int value) const;
    void setFloat(const std::string& uniformName, float value) const;
    void setMat4(const std::string& uniformName, glm::mat4& matrix) const;
};

#endif