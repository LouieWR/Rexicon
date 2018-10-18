#include "rexicon/rexicon.h"

#include <iostream>

class TestScreen : public rexicon::Module
{
public:
	void onInit(std::string color)
	{
		//std::cout << "onInit " << color << std::endl;
	}

	void onBegin()
	{
		//std::cout << "onBegin" << std::endl;
	}

	void onTick()
	{
		//std::cout << "onTick" << std::endl;
	}

	void onDisplay()
	{
		//std::cout << "onTick" << std::endl;
	}
};

int main()
{
	std::shared_ptr<rexicon::Core> c = rexicon::Core::initialise();

	std::shared_ptr<rexicon::Object> e = c->AddObject();

	std::shared_ptr<TestScreen> ts = e->addComponent<TestScreen>("Green");
	std::shared_ptr<rexicon::MeshRenderer> mr = e->addComponent<rexicon::MeshRenderer>();
	std::shared_ptr<rexicon::MeshRenderer> mr2 = e->getComponent<rexicon::MeshRenderer>();

	c->start();

	return 0;
}