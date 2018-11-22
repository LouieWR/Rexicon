#include "rexicon/rexicon.h"

#include <iostream>

class Mover : public rexicon::Module
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
		if (GetObject()->GetScene()->GetInput()->CheckKey(SDL_SCANCODE_K))
		{
			GetObject()->GetTransformModule()->Translate(glm::vec3(0.0f, 0.0f, 0.1f));
		}
		if (GetObject()->GetScene()->GetInput()->CheckKey(SDL_SCANCODE_L))
		{
			GetObject()->GetTransformModule()->Translate(glm::vec3(0.0f, 0.0f, -0.1f));
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
	otr->SetPosition(glm::vec3(-5, 0, 5));
	std::shared_ptr<rexicon::MeshRenderer> omr = o->AddModule<rexicon::MeshRenderer>("../resources/objects/Cat/curuthers.obj", "../resources/objects/Cat/curuthers_diffuse.png");

	std::shared_ptr<rexicon::Object> o2 = s->AddObject();
	std::shared_ptr<rexicon::Transform> otr2 = o2->AddModule<rexicon::Transform>();
	otr2->SetPosition(glm::vec3(5, 0, 0));
	std::shared_ptr<rexicon::MeshRenderer> omr2 = o2->AddModule<rexicon::MeshRenderer>();

	std::shared_ptr<rexicon::Object> o3 = s->AddObject();
	std::shared_ptr<rexicon::Transform> otr3 = o3->AddModule<rexicon::Transform>();
	otr3->SetPosition(glm::vec3(0, 0, -20));
	otr3->SetScale(glm::vec3(0.2, 0.2, 0.2));
	std::shared_ptr<rexicon::MeshRenderer> omr3 = o3->AddModule<rexicon::MeshRenderer>("../resources/objects/Boat/OldBoat.obj", "../resources/objects/Boat/boattex.jpg");

	std::shared_ptr<rexicon::Object> sph1 = s->AddObject();
	std::shared_ptr<rexicon::Transform> sph1tr = sph1->AddModule<rexicon::Transform>();
	sph1tr->SetPosition(glm::vec3(0, 0, 0));
	std::shared_ptr<rexicon::MeshRenderer> sph1mr = sph1->AddModule<rexicon::MeshRenderer>("../resources/objects/Shapes/Sphere.obj");
	std::shared_ptr<rexicon::Collider> sph1cl = sph1->AddModule<rexicon::Collider>();
	std::shared_ptr<Mover> sph1mv = sph1->AddModule<Mover>();

	std::shared_ptr<rexicon::Object> sph2 = s->AddObject();
	std::shared_ptr<rexicon::Transform> sph2tr = sph2->AddModule<rexicon::Transform>();
	sph2tr->SetPosition(glm::vec3(0, 0, 0));
	sph2tr->SetScale(glm::vec3(.5, .5, .5));
	std::shared_ptr<rexicon::MeshRenderer> sph2mr = sph2->AddModule<rexicon::MeshRenderer>("../resources/objects/Shapes/Sphere.obj");
	std::shared_ptr<rexicon::Collider> sph2cl = sph2->AddModule<rexicon::Collider>();
	sph2cl->SetBoundingSphRadius(0.5f);

	std::shared_ptr<rexicon::Object> floor = s->AddObject();
	std::shared_ptr<rexicon::Transform> floortr = floor->AddModule<rexicon::Transform>();
	floortr->SetScale(glm::vec3(50, 0, 50));
	floortr->SetPosition(glm::vec3(0, -5, 0));
	std::shared_ptr<rexicon::MeshRenderer> floormr = floor->AddModule<rexicon::MeshRenderer>("../resources/objects/Shapes/Cube.obj");
	//std::shared_ptr<rexicon::Collider> floorcl = floor->AddModule<rexicon::Collider>();

	std::shared_ptr<rexicon::Camera> cam = s->AddCamera();
	std::shared_ptr<rexicon::Transform> ctr = cam->AddModule<rexicon::Transform>();
	ctr->SetPosition(glm::vec3(0, 0, 0));

	c->start();

	return 0;
}