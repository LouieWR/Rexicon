#ifndef REXICON_MODULE_H
#define REXICON_MODULE_H

#include <memory>

//Derived classes
//#include "Transform.h"

namespace rexicon
{

class Object;
class Core;

class Module
{
	friend class Object;

public:
	Module();
	~Module();
	std::shared_ptr<Core> GetCore();
	std::shared_ptr<Object> GetObject();

protected:
	std::weak_ptr<Module> self;

	std::weak_ptr<Object> object;
	bool began;

private:

	virtual void OnInit();
	virtual void OnBegin();
	virtual void OnTick();
	virtual void OnDisplay();
};

}

#endif