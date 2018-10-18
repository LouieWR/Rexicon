#include "Object.h"

#include "Module.h"

namespace rexicon
{

	std::shared_ptr<Core> Object::getCore()
	{
		return core.lock();
	}

	void Object::tick()
	{
		for (std::vector<std::shared_ptr<Module> >::iterator it = components.begin();
			it != components.end(); it++)
		{
			if (!(*it)->began)
			{
				(*it)->onBegin();
				(*it)->began = true;
			}

			(*it)->onTick();
		}
	}

	void Object::display()
	{
		for (std::vector<std::shared_ptr<Module> >::iterator it = components.begin();
			it != components.end(); it++)
		{
			(*it)->onDisplay();
		}
	}

}