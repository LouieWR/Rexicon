#include "Module.h"

#include <glm/glm.hpp>
#include "GL/glew.h"

namespace rexicon
{
	class Collider : public Module
	{
	public:
		Collider();
		~Collider();

		void OnInit();

		void OnTick();

		void SetBoundingSphRadius(float _boundingSphRadius) { boundingSphRadius = _boundingSphRadius; }
		float GetBoundingSphRadius() { return boundingSphRadius; }
	private:
		float boundingSphRadius = 1.0f; // Used for sphere collisions
		glm::vec3 boundingCorner1 = glm::vec3(1.0f, 1.0f, 1.0f);
		glm::vec3 boundingCorner2 = glm::vec3(-1.0f, -1.0f, -1.0f);

		bool CheckCollision(std::shared_ptr<Collider> _against);

		enum ColType { Sphere, Box, Mesh };

		ColType colType;
	};

}
