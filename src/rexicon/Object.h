#ifndef REXICON_OBJECT_H
#define REXICON_OBJECT_H

#include <memory>
#include <vector>
#include <iostream> // DELETE AFTER USE

#define ADDMODULE \
  std::shared_ptr<T> rtn = std::make_shared<T>(); \
  rtn->object = self; \
  rtn->self = rtn; \
  rtn->began = false; \
  modules.push_back(rtn);

namespace rexicon
{

class Core;
class Scene;
class Module;
class Transform;
class Collider;

class Object
{
	friend class Scene;

protected:

	std::weak_ptr<Object> self;
	std::weak_ptr<Core> core;
	std::weak_ptr<Scene> scene;
	std::vector<std::shared_ptr<Module> > modules;
	std::shared_ptr<Transform> transform;
	std::shared_ptr<Collider> collider;

public:

	virtual void OnInit() {};
	virtual void Update();
	virtual void Draw();

	void SetTransformModule();
	std::shared_ptr<Transform> GetTransformModule() { return transform; }
	void SetColliderModule();
	std::shared_ptr<Collider> GetColliderModule() { return collider; }

	template <typename T>
	std::shared_ptr<T> GetModule();

	template <typename T>
	std::shared_ptr<T> AddModule()
	{
		ADDMODULE
		rtn->OnInit();
		
		return rtn;
	}

	template <typename T, typename A>
	std::shared_ptr<T> AddModule(A a)
	{
		ADDMODULE
		rtn->OnInit(a);

		return rtn;
	}

	template <typename T, typename A, typename B>
	std::shared_ptr<T> AddModule(A a, B b)
	{
		ADDMODULE
		rtn->OnInit(a, b);

		return rtn;
	}

	std::shared_ptr<Scene> GetScene();
	std::shared_ptr<Core> GetCore();

};

}

#endif