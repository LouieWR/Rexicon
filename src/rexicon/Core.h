#include <SDL2/SDL.h>

#include <AL/al.h>
#include <AL/alc.h>

#include <memory>
#include <vector>

namespace rexicon
{

class Object;
class Scene;

class Core
{

private:
	bool running;
	SDL_Window *window;
	ALCdevice* device;
	ALCcontext* context;
	std::vector<std::shared_ptr<Scene>> scenes;
	std::weak_ptr<Core> self;

public:
	static std::shared_ptr<Core> initialise();
	void start();
	void stop();
	std::shared_ptr<Scene> AddScene();
	std::shared_ptr<Scene> GetScene(Uint32 sceneID);
};
}