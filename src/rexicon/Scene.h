#ifndef REXICON_OBJECT_H
#define REXICON_OBJECT_H

#include <memory>
#include <vector>

#define ADDCOMPONENT \
  std::shared_ptr<T> rtn = std::make_shared<T>(); \
  rtn->entity = self; \
  rtn->began = false; \
  components.push_back(rtn);

namespace rexicon
{

class Core;
class Module;

class Object
{
	friend class Core;

private:

	std::weak_ptr<Object> self;
	std::weak_ptr<Core> core;
	std::vector<std::shared_ptr<Module> > components;

	void tick();
	void display();

public:

	template <typename T>
	std::shared_ptr<T> getComponent()
	{
		for (size_t i = 0; i < components.size(); i++)
		{
			std::shared_ptr<T> tst = std::dynamic_pointer_cast<T>(components.at(i));

			if (tst)
			{
				return tst;
			}
		}

		throw std::exception();
	}

	template <typename T>
	std::shared_ptr<T> addComponent()
	{
		ADDCOMPONENT
			rtn->onInit();
			return rtn;
	}

	template <typename T, typename A>
	std::shared_ptr<T> addComponent(A a)
	{
		ADDCOMPONENT
			rtn->onInit(a);

		return rtn;
	}

	template <typename T, typename A, typename B>
	std::shared_ptr<T> addComponent(A a, B b)
	{
		ADDCOMPONENT
			rtn->onInit(a, b);

		return rtn;
	}

	std::shared_ptr<Core> getCore();

};

}

#endif