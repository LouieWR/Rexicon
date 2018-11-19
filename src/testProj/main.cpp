#include "rexicon/rexicon.h"

#include <iostream>

class Rotator : public rexicon::Module
{
public:
	virtual void OnInit()
	{

	}
	virtual void OnBegin()
	{

	}
	virtual void OnTick()
	{
		if (GetObject()->GetScene()->GetInput()->CheckKey(SDL_SCANCODE_LEFT))
		{
			GetObject()->GetTransformModule()->Rotate(glm::vec3(0, 0.1f, 0));
		}
		if (GetObject()->GetScene()->GetInput()->CheckKey(SDL_SCANCODE_RIGHT))
		{
			GetObject()->GetTransformModule()->Rotate(glm::vec3(0, -0.1f, 0));
		}
	}
	virtual void OnDisplay()
	{

	}
};

int main()
{
	std::shared_ptr<rexicon::Core> c = rexicon::Core::initialise();

	std::shared_ptr<rexicon::Scene> s = c->AddScene();

	std::shared_ptr<rexicon::Object> o = s->AddObject();
	std::shared_ptr<rexicon::Transform> otr = o->AddModule<rexicon::Transform>();
	otr->SetPosition(glm::vec3(0, 0, -10.0f));
	std::shared_ptr<rexicon::MeshRenderer> omr = o->AddModule<rexicon::MeshRenderer>("../resources/objects/Typhoon/eurofighter.obj", "../resources/objects/Typhoon/EurofighterDiffuse.bmp");

	std::shared_ptr<rexicon::Object> o2 = s->AddObject();
	std::shared_ptr<rexicon::Transform> otr2 = o2->AddModule<rexicon::Transform>();
	otr2->SetPosition(glm::vec3(5.0f, 0.0f, -5.0f));
	std::shared_ptr<rexicon::MeshRenderer> omr2 = o2->AddModule<rexicon::MeshRenderer>();

	std::shared_ptr<rexicon::Camera> cam = s->AddCamera();
	std::shared_ptr<rexicon::Transform> ctr = cam->AddModule<rexicon::Transform>();
	ctr->SetPosition(glm::vec3(0.0f, 0.0f, 25.0f));

	c->start();

	return 0;
}