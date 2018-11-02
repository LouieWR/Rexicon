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
	float fov = 45.0f;
	float aspect = 2.0f;
	float near = 0.1f;
	float far = 1000.0f;

public:

	void Update();
	void Draw();

	float GetFOV() { return fov; }
	float GetAspect() { return aspect; }
	float GetNear() { return near; }
	float GetFar() { return far; }

};

}

#endif