#include "Module.h"

#include "Object.h"

namespace rexicon
{
Module::Module() { }
Module::~Module() { }
void Module::OnInit() { }
void Module::OnBegin() { }
void Module::OnTick() { }
void Module::OnDisplay() { }

std::shared_ptr<Object> Module::GetObject()
{
	return object.lock();
}

std::shared_ptr<Core> Module::GetCore()
{
	return GetObject()->GetCore();
}

}
