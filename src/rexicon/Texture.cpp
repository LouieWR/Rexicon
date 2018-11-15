#include "Texture.h"
#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include <gl/glew.h>

namespace rexicon
{
	unsigned int Texture::LoadTexture(std::string _filename)
	{
		// Load SDL surface
		SDL_Surface *image = SDL_LoadBMP(_filename.c_str());

		if (!image) // Check it worked
		{
			throw std::exception();
			std::cout << "Could not load texture" << std::endl;
		}

		texID = 0;
		glGenTextures(1, &texID);

		if (!texID)
		{
			throw std::exception();
		}

		glBindTexture(GL_TEXTURE_2D, texID);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->w, image->h, 0, GL_BGR, GL_UNSIGNED_BYTE, image->pixels);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);

		SDL_FreeSurface(image);
		return texID;
	}
}