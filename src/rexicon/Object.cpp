#include "Object.h"

#include "Module.h"
#include "Transform.h"
#include "Collider.h"
#include "Scene.h"

#include "SDL2/SDL.h"

namespace rexicon
{

void Object::Update()
{
	for (std::vector<std::shared_ptr<Module> >::iterator it = modules.begin();
		it != modules.end(); it++)
	{
		if (!(*it)->began)
		{
			(*it)->OnBegin();
			(*it)->began = true;
		}

		(*it)->OnTick();
	}
}

void Object::Draw()
{
	for (std::vector<std::shared_ptr<Module> >::iterator it = modules.begin();
		it != modules.end(); it++)
	{
		(*it)->OnDisplay();
	}
}

void Object::SetTransformModule()
{
	transform = GetModule<Transform>();
}

void Object::SetColliderModule()
{
	collider = GetModule<Collider>();
	GetScene()->AddCollider(collider);
}

template <typename T>
std::shared_ptr<T> Object::GetModule()
{
	for (size_t i = 0; i < modules.size(); i++)
	{
		std::shared_ptr<T> tst = std::dynamic_pointer_cast<T>(modules.at(i));

		if (tst)
		{
			return tst;
		}
	}

	throw std::exception();
}

std::shared_ptr<Scene> Object::GetScene()
{
	return scene.lock();
}

std::shared_ptr<Core> Object::GetCore()
{
	return core.lock();
}

}