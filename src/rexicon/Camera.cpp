#include "Camera.h"
#include "Scene.h"
#include "Input.h"
#include "Transform.h"

namespace rexicon
{
void Camera::OnInit()
{
	projMat = glm::perspective(45.0f, 2.0f, 0.1f, 10000.0f);
	AddModule<rexicon::Transform>();
	transform->SetPosition(glm::vec4(0, 0, -10.0f, 1));
}

void Camera::Update()
{
	if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_W))
	{
		transform->Translate(glm::vec4(0, 0, 0.1f, 0));
	}
	if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_S))
	{
		transform->Translate(glm::vec4(0, 0, -0.1f, 0));
	}
	if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_A))
	{
		transform->Translate(glm::vec4(0.1f, 0, 0, 0));
	}
	if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_D))
	{
		transform->Translate(glm::vec4(-0.1f, 0, 0, 0));
	}

	if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_LEFT))
	{
		transform->Rotate(glm::vec3(0, -0.1f, 0));
	}
	if (GetScene()->GetInput()->CheckKey(SDL_SCANCODE_RIGHT))
	{
		transform->Rotate(glm::vec3(0, 0.1f, 0));
	}
}

void Camera::Draw()
{

}
}