#include "Transform.h"
#include "Object.h"

namespace rexicon
{

	void Transform::OnInit()
	{
		GetObject()->SetTransformModule();
	}

	void Transform::OnTick()
	{

	}
}