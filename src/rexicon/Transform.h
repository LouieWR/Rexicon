#include "Module.h"

#include <memory>
#include <glm/glm.hpp>

namespace rexicon
{

	class Object;

class Transform : public Module
{

public:
	void OnInit();

private:
	void OnTick();
	glm::vec4 pos;// Not done
	glm::vec4 rot;// Not done
	glm::vec4 scl;// Not done
		
};

}
