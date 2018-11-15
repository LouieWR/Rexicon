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

public:

	void OnInit();
	void Update();
	void Draw();

	glm::mat4 GetProjection() { return projMat; }

};

}

#endif