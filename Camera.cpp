#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Camera::Camera() {
	float speed;
	pos = glm::vec3(0.0f, 0.0f, 3.0f);
	front = glm::vec3(0.0f, 0.0f, -1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 target = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 direction = glm::normalize(pos - target);

    right = glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), direction));

    up = glm::cross(direction, right);
}
void Camera::proccessInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        pos += speed * front;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        pos -= speed * front;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        pos -= glm::normalize(glm::cross(front, up)) * speed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        pos += glm::normalize(glm::cross(front, up)) * speed;
}
void Camera::setSpeed(float speed) 
{
    this->speed = speed;
}
void Camera::setFront(glm::vec3 vec) 
{
    front = vec;
}
glm::mat4 Camera::getViewMatrix() 
{
    return glm::lookAt(pos, pos + front, up);
}