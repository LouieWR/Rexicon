#include "Camera.h"
#include "Scene.h"
#include "Input.h"
#include "Transform.h"

#include <cmath>

namespace rexicon
{
void Camera::OnInit()
{
	projMat = glm::perspective(glm::radians(65.0f), 2.0f, 0.1f, 100.0f);
}

void Camera::Update()
{
	switch (camType)
	{
	case CamType(basic): // Default type, not really meant to be used for more than testing
	{
		viewMat = glm::mat4(1.0f); // We set the camera type to the identity matrix in this case because the user hasn't set a proper camera type.
	}
	case CamType(first): // First person camera type
	{

	}
	case CamType(follow): // Follows a specific point with an offset and potential for smoothing
	{
		if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_1))
		{
			transform->Rotate(glm::vec3(0.0f, 5.0f, 0.0f));
		}
		if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_2))
		{
			transform->Rotate(glm::vec3(0.0f, -5.0f, 0.0f));
		}
		
	}
	}
	
}

void Camera::Draw()
{

}

glm::mat4 Camera::GetViewMat()
{
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	return viewMat;
}
}