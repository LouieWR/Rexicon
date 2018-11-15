#include "Transform.h"
#include "Object.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace rexicon
{

void Transform::OnInit()
{
	pos = rot = scl = glm::vec4(0, 0, 0, 0);
	GetObject()->SetTransformModule();
}

void Transform::OnTick()
{

}

glm::mat4 Transform::GetTransformMat()
{
	glm::mat4 rtn = glm::mat4(1.0f);

	rtn = glm::rotate(rtn, rot.x, glm::vec3(1, 0, 0)); // Rotate it about each of the 3 axis
	rtn = glm::rotate(rtn, rot.y, glm::vec3(0, 1, 0));
	rtn = glm::rotate(rtn, rot.z, glm::vec3(0, 0, 1));

	rtn = glm::translate(rtn, pos); // Translate it to the position of the transform module

	return rtn;
}
}