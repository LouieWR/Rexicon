#ifndef REXICON_MODULE_H
#define REXICON_MODULE_H

#include <memory>

namespace rexicon
{

class Object;
class Core;

class Module
{
	friend class Object;

public:
	virtual ~Module();
	std::shared_ptr<Core> getCore();
	std::shared_ptr<Object> getObject();

private:
	std::weak_ptr<Object> entity;
	bool began;

	virtual void onInit();
	virtual void onBegin();
	virtual void onTick();
	virtual void onDisplay();
};

}

#endif