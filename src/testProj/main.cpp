#include "rexicon/rexicon.h"

#include <iostream>

class TestScreen : public rexicon::Module
{
public:
	virtual void OnInit(std::string color)
	{

	}
	virtual void OnBegin()
	{

	}
	virtual void OnTick()
	{

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
	std::shared_ptr<rexicon::Camera> cam = s->AddCamera();
	std::shared_ptr<rexicon::Transform> tr = cam->AddModule<rexicon::Transform>();

	std::shared_ptr<TestScreen> ts = o->AddModule<TestScreen>("Green");
	std::shared_ptr<rexicon::MeshRenderer> mr = o->AddModule<rexicon::MeshRenderer>();
	std::shared_ptr<rexicon::MeshRenderer> mr2 = o->AddModule<rexicon::MeshRenderer>();

	c->start();

	return 0;
}