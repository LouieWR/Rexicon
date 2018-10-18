#include <SDL2/SDL.h>

#include <AL/al.h>
#include <AL/alc.h>

#include <memory>
#include <vector>

namespace rexicon
{

class Object;

class Core
{

private:
	bool running;
	SDL_Window *window;
	ALCdevice* device;
	ALCcontext* context;
	std::weak_ptr<Core> self;
	std::vector<std::shared_ptr<Object>> objects;

public:
	static std::shared_ptr<Core> initialise();
	void start();
	void stop();
	std::shared_ptr<Object> AddObject();

};
}