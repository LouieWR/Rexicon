#ifndef REXICON_CAMERA_H
#define REXICON_CAMERA_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <memory>
#include <vector>

#include "Object.h"

namespace rexicon
{

class Camera : public Object
{

private:
	glm::mat4 projMat;

	glm::vec3 offset = glm::vec3(0, 0, 1.0f);

	enum CamType { basic, first, follow };
	CamType camType = first;

	glm::mat4 viewMat;
	glm::mat4 direction;
	glm::vec3 front;
	glm::vec3 right;
	glm::vec3 up;

	glm::mat4 FindDirection();
	glm::vec3 FindFront();
	glm::vec3 FindRight();

public:

	void OnInit();
	void Update();
	void Draw();

	glm::mat4 GetProjection() { return projMat; }
	glm::mat4 GetViewMat();

};

}

#endif