#ifndef CAMERA_H
#define CAMERA_H
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Camera {
private:
	float speed;
	glm::vec3 pos, front, up, right;

public:
	Camera();
	void proccessInput(GLFWwindow* window);
	void setSpeed(float speed);
	glm::mat4 getViewMatrix();
	void setFront(glm::vec3 vec);
};
#endif
