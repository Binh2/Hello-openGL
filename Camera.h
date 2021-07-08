#ifndef CAMERA_H
#define CAMERA_H
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Camera {
private:
	float speed;
public:
	float zoom;
	glm::vec3 pos, front, up, right;
	Camera();
	void proccessInput(GLFWwindow* window);
	void setSpeed(float speed);
	glm::mat4 getViewMatrix();
	void setFront(glm::vec3 vec);
};
#endif
