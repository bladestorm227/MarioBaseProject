#include "CharacterMario.h"
#include "Character.h"
#include <iostream>
#include "Texture2D.h"
#include "constants.h"

CharacterMario::CharacterMario(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position) : Character(renderer, imagePath, start_position)
{
}

CharacterMario::~CharacterMario()
{
}

void CharacterMario::Update(float deltaTime, SDL_Event e)
{
	AddGravity(deltaTime);

	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			m_moving_left = true;
			break;
		case SDLK_RIGHT:
			m_moving_right = true;
			break;
		case SDLK_UP:
			if (m_can_jump)
			{
				Jump();
			}
			
			break;
		}

		break;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			m_moving_left = false;
			break;
		case SDLK_RIGHT:
			m_moving_right = false;
			break;
		}
	}

	Character::Update(deltaTime, e);


	if (m_moving_left)
	{
		MoveLeft(deltaTime);
	}
	else if (m_moving_right)
	{
		MoveRight(deltaTime);
	}
}