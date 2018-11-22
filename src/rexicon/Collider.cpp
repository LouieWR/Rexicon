#include "Collider.h"
#include "Transform.h"
#include "Object.h"
#include "Scene.h"

namespace rexicon
{
	Collider::Collider()
	{

	}

	Collider::~Collider()
	{

	}

	void Collider::OnInit()
	{
		GetObject()->SetColliderModule();
	}

	void Collider::OnTick()
	{
		std::vector<std::shared_ptr<Collider>> cols = GetObject()->GetScene()->GetColliders();
		for (int i = 0; i < cols.size(); i++)
		{
			if (cols[i].get() != this) { CheckCollision(cols[i]); }
		}
	}

	bool Collider::CheckCollision(std::shared_ptr<Collider> _against)
	{
		bool isColliding = false;

		/* SPHERE COLLISION COMES FIRST */

		glm::vec3 pos1 = GetObject()->GetTransformModule()->GetPosition();
		float rad1 = boundingSphRadius;
		glm::vec3 pos2 = _against->GetObject()->GetTransformModule()->GetPosition();
		float rad2 = _against->GetBoundingSphRadius();

		glm::vec3 diffVec(0);
		diffVec.x = pos1.x - pos2.x;
		diffVec.y = pos1.y - pos2.y;
		diffVec.z = pos1.z - pos2.z;

		float dist = sqrt(diffVec.x * diffVec.x + diffVec.y * diffVec.y + diffVec.z * diffVec.z);

		if (dist < rad1 + rad2)
		{
			isColliding = true;
			std::cout << dist << std::endl;
		}
		/*
		if (colType > Sphere) // If the collision type is larger than sphere, we move up to the next level, box
		{

		}
		*/
		return isColliding;
	}
}