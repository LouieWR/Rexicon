#include "Scene.h"

#include "Object.h"
#include "Camera.h"
#include "Input.h"
#include "Collider.h"

namespace rexicon
{

void Scene::Update()
{
	for (std::vector<std::shared_ptr<Object> >::iterator it = objects.begin();
		it != objects.end(); it++)
	{
		(*it)->Update();
	}
}

void Scene::Draw()
{
	for (std::vector<std::shared_ptr<Object> >::iterator it = objects.begin();
		it != objects.end(); it++)
	{
		(*it)->Draw();
	}
}

std::shared_ptr<Object> Scene::AddObject()
{
	std::shared_ptr<Object> rtn = std::make_shared<Object>();
	rtn->self = rtn;
	rtn->scene = self;
	objects.push_back(rtn);
	rtn->OnInit();

	return rtn;
}

std::shared_ptr<Camera> Scene::AddCamera()
{
	std::shared_ptr<Camera> rtn = std::make_shared<Camera>();
	rtn->self = rtn;
	rtn->scene = self;
	activeCamera = rtn;
	objects.push_back(rtn);
	rtn->OnInit();

	return rtn;
}

std::shared_ptr<Camera> Scene::GetCamera()
{
	return activeCamera;
}

std::shared_ptr<Input> Scene::AddInput()
{
	std::shared_ptr<Input> rtn = std::make_shared<Input>();
	input = rtn;

	return rtn;
}

void Scene::AddCollider(std::shared_ptr<Collider> _collider)
{
	colliders.push_back(_collider);
}

}