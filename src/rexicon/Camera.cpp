#include "Camera.h"
#include "Scene.h"
#include "Input.h"

namespace rexicon
{
	void Camera::Update()
	{
		if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_SPACE))
		{
			fov += 0.1f;
		}
	}

	void Camera::Draw()
	{

	}
}