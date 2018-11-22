#include "Camera.h"
#include "Scene.h"
#include "Input.h"
#include "Transform.h"

#include <math.h>

namespace rexicon
{
void Camera::OnInit()
{
	projMat = glm::perspective(glm::radians(45.0f), 2.0f, 0.1f, 1000.0f);
}

void Camera::Update()
{
	FindDirection();
	FindFront();
	FindRight();

	switch (camType)
	{
	case CamType(basic): // Default type, not really meant to be used for more than testing
	{
		viewMat = glm::mat4(1.0f); // We set the camera type to the identity matrix in this case because the user hasn't set a proper camera type.
	}
	break;
	case CamType(first): // First person camera type
	{
		if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_LEFT))
		{
			transform->Rotate(glm::vec3(0.0f, 1.0f, 0.0f));
		}
		if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_RIGHT))
		{
			transform->Rotate(glm::vec3(0.0f, -1.0f, 0.0f));
		}
		if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_S))
		{
			transform->Translate(front * -0.2f);
		}
		if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_W))
		{
			transform->Translate(front * 0.2f);
		}
		if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_A))
		{
			transform->Translate(right * -0.2f);
		}
		if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_D))
		{
			transform->Translate(right * 0.2f);
		}
		if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_LALT))
		{
			transform->Translate(glm::vec3(0.0f, 1.0f, 0.0f) * -0.1f);
		}
		if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_SPACE))
		{
			transform->Translate(glm::vec3(0.0f, -1.0f, 0.0f) * -0.1f);
		}
		if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_LCTRL))
		{
			transform->Rotate(glm::vec3(1.0f, 0.0f, 0.0f));
		}
		if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_LSHIFT))
		{
			transform->Rotate(glm::vec3(-1.0f, 0.0f, 0.0f));
		}
		if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_1))
		{
			FindFront();
		}

		glm::vec3 rot = transform->GetRotation();
		if (rot.x > 45.0f)
		{
			transform->SetRotation(glm::vec3(45.0f, rot.y, rot.z));
		}
		if (rot.x < -45.0f)
		{
			transform->SetRotation(glm::vec3(-45.0f, rot.y, rot.z));
		}
	}
	break;
	case CamType(follow): // Follows a specific point with an offset and potential for smoothing
	{

	}
	break;
	}
	
}

void Camera::Draw()
{

}

glm::mat4 Camera::GetViewMat()
{
	glm::mat4 rtn = glm::mat4(1.0f);
	glm::vec3 pos = transform->GetPosition();
	glm::vec3 rot = transform->GetRotation();
	glm::vec3 scl = transform->GetScale();

	rtn = glm::translate(rtn, pos);
	rtn = glm::rotate(rtn, glm::radians(rot.y), glm::vec3(0, 1, 0));
	rtn = glm::rotate(rtn, glm::radians(rot.x), glm::vec3(1, 0, 0)); // Rotate it about each of the 3 axis
	rtn = glm::rotate(rtn, glm::radians(rot.z), glm::vec3(0, 0, 1));

	viewMat = rtn;
	return rtn;
}

glm::mat4 Camera::FindDirection()
{
	direction = glm::mat4(1.0f);
	glm::vec3 rot = transform->GetRotation();
	direction = glm::rotate(direction, glm::radians(rot.y), glm::vec3(0, 1, 0));
	direction = glm::rotate(direction, glm::radians(rot.x), glm::vec3(1, 0, 0));
	return direction;
}

glm::vec3 Camera::FindFront()
{
	front = direction * glm::vec4(0, 0, -1, 1);
	return front;
}

glm::vec3 Camera::FindRight()
{
	right = direction * glm::vec4(1, 0, 0, 1);
	return right;
}
}