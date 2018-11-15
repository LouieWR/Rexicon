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
	//o->GetTransformModule()->SetPosition(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	//o->GetTransformModule()->SetScale(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	std::shared_ptr<rexicon::Camera> cam = s->AddCamera();
	std::shared_ptr<rexicon::Transform> tr = cam->AddModule<rexicon::Transform>();

	//std::shared_ptr<Rotator> ts = o->AddModule<Rotator>();
	std::shared_ptr<rexicon::MeshRenderer> mr = o->AddModule<rexicon::MeshRenderer>();
	std::shared_ptr<rexicon::MeshRenderer> mr2 = o->AddModule<rexicon::MeshRenderer>();
	 
	c->start();

	return 0;
}