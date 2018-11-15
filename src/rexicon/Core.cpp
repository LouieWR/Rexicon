#include "Core.h"
#include "Scene.h"
#include "Input.h"

#include <GL/glew.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

namespace rexicon
{

std::shared_ptr<Core> Core::initialise() // Lab Code
{
	std::shared_ptr<Core> rtn = std::make_shared<Core>();
	rtn->running = false;
	rtn->self = rtn;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}

	rtn->window = SDL_CreateWindow("Rexicon",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(rtn->window))
	{
		throw std::exception();
	}

	if (glewInit() != GLEW_OK)
	{
		throw std::exception();
	}

	rtn->device = alcOpenDevice(NULL);

	if (!rtn->device)
	{
		throw std::exception();
	}

	rtn->context = alcCreateContext(rtn->device, NULL);

	if (!rtn->context)
	{
		alcCloseDevice(rtn->device);
		throw std::exception();
	}

	if (!alcMakeContextCurrent(rtn->context))
	{
		alcDestroyContext(rtn->context);
		alcCloseDevice(rtn->device);
		throw std::exception();
	}

	// Remember to close after use
	//alcMakeContextCurrent(NULL);
	//alcDestroyContext(context);
	//alcCloseDevice(device);

	return rtn;
}

void Core::start()
{

	running = true;

	while (running)
	{
		SDL_Event event = { 0 };

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}


		for (std::vector<std::shared_ptr<Scene> >::iterator it = scenes.begin();
			it != scenes.end(); it++)
		{
			(*it)->Update();
		}

		glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		for (std::vector<std::shared_ptr<Scene> >::iterator it = scenes.begin();
			it != scenes.end(); it++)
		{
			(*it)->Draw();
		}

		SDL_GL_SwapWindow(window);
	}
}

void Core::stop()
{
	running = false;
}

std::shared_ptr<Scene> Core::AddScene()
{
	std::shared_ptr<Scene> rtn = std::make_shared<Scene>();
	scenes.push_back(rtn);
		
	rtn->self = rtn;
	rtn->core = self;

	rtn->AddInput();

	return rtn;
}

}