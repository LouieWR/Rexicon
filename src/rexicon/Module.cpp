#include "Module.h"

#include "Object.h"

namespace rexicon
{

	Module::~Module() { }
	void Module::onInit() { }
	void Module::onBegin() { }
	void Module::onTick() { }
	void Module::onDisplay() { }

	std::shared_ptr<Object> Module::getObject()
	{
		return entity.lock();
	}

	std::shared_ptr<Core> Module::getCore()
	{
		return getObject()->getCore();
	}

}
