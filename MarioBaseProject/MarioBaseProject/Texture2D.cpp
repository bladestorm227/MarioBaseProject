#include "Texture2D.h"
#include <SDL_image.h>
#include <iostream>

Texture2D::Texture2D(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}
Texture2D::~Texture2D()
{
	//Free up memory
	Free();

	m_renderer = nullptr;
}

void Texture2D::Free()
{
	//check if texture exists before removing it
	if (m_texture != nullptr)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
	}
}

void Texture2D::Render(Vector2D new_position, SDL_RendererFlip flip, double angle)
{
	//set where to render the texture
	SDL_Rect renderLocation = { 0,0,m_width, m_height };

	//Render to screen
	SDL_RenderCopyEx(m_renderer, m_texture, NULL, &renderLocation, angle, NULL, flip);
}

bool Texture2D::LoadFromFile(std::string path)
{
    //remove memory used for a previous texture
    Free();

    //Load the image
    SDL_Surface* p_surface = IMG_Load(path.c_str());
    if (p_surface != nullptr)
    {
        //colour key the image to be transparent
        SDL_SetColorKey(p_surface, SDL_TRUE, SDL_MapRGB(p_surface->format, 0, 0XFF, 0XFF));

        //create the texture from the pixels on the surface
        m_texture = SDL_CreateTextureFromSurface(m_renderer, p_surface);


        if (m_texture == nullptr)
        {
            std::cout << "Unable to create texture from surface. Error: " << SDL_GetError();
        }
        else
        {
            m_width = p_surface->w;
            m_height = p_surface->h;
        }
        //remove the loaded surface now that we have a texture
        SDL_FreeSurface(p_surface);

        //Return whether the process was successful
        return m_texture != nullptr;
    }
}