#include "Transform.h"
#include "Object.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace rexicon
{

void Transform::OnInit()
{
	pos = rot = glm::vec3(0, 0, 0);
	scl = glm::vec3(1, 1, 1);
	GetObject()->SetTransformModule();
}

void Transform::OnTick()
{
	if (rot.x > 90.0f)
	{
		rot.x -= 90.0f;
	}
	if (rot.x < -90.0f)
	{
		rot.x += 90.0f;
	}
	if (rot.y > 90.0f)
	{
		rot.y -= 90.0f;
	}
	if (rot.y < -90.0f)
	{
		rot.y += 90.0f;
	}
	if (rot.z > 90.0f)
	{
		rot.z -= 90.0f;
	}
	if (rot.z < -90.0f)
	{
		rot.z += 90.0f;
	}
}

glm::mat4 Transform::GetTransformMat()
{
	glm::mat4 rtn = glm::mat4(1.0f);

	rtn = glm::translate(rtn, pos); // Translate it to the position of the transform module

	rtn = glm::rotate(rtn, glm::radians(rot.x), glm::vec3(1, 0, 0)); // Rotate it about each of the 3 axis
	rtn = glm::rotate(rtn, glm::radians(rot.y), glm::vec3(0, 1, 0));
	rtn = glm::rotate(rtn, glm::radians(rot.z), glm::vec3(0, 0, 1));

	rtn = glm::scale(rtn, scl);

	return rtn;
}
}