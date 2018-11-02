#ifndef REXICON_INPUT_H
#define REXICON_INPUT_H

#include <memory>
#include <vector>

#include <SDL2/SDL.h>

namespace rexicon
{

class Input
{

protected:

	const Uint8 *keys;

public:

	bool CheckKey(SDL_Scancode _scancode)
	{
		int* numkeys = 0;
		keys = SDL_GetKeyboardState(numkeys);

		bool key = false;
		if (keys[_scancode])
		{
			key = true;
		}
		return key;
	}

};

}

#endif