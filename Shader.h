
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
    void setBool(const std::string&, bool) const;
    void setInt(const std::string&, int) const;
    void setFloat(const std::string&, float) const;
    void setMat4(const std::string&, glm::mat4&) const;
};

#endif