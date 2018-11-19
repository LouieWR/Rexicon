#include "Module.h"

#include <memory>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace rexicon
{

	class Object;

class Transform : public Module
{

public:
	void OnInit();

	glm::vec3 GetPosition() { return pos; }

	glm::vec3 GetRotation() { return rot; }

	glm::vec3 GetScale() { return scl; }

	glm::vec3 SetPosition(glm::vec3 _pos)
	{
		pos = _pos;
		return pos;
	}
	glm::vec3 SetRotation(glm::vec3 _rot)
	{
		rot = _rot;
		return rot;
	}
	glm::vec3 SetScale(glm::vec3 _scl)
	{
		scl = _scl;
		return scl;
	}

	glm::vec3 Translate(glm::vec3 _pos)
	{
		pos += _pos;
		return pos;
	}

	glm::vec3 Rotate(glm::vec3 _rot)
	{
		rot += _rot;
		return pos;
	}

	glm::mat4 GetTransformMat();

private:
	void OnTick();
	glm::vec3 pos = glm::vec3(0, 0, 0);
	glm::vec3 rot = glm::vec3(0, 0, 0);
	glm::vec3 scl = glm::vec3(0, 0, 0);
};

}
