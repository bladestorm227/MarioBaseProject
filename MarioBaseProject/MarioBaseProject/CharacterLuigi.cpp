#include "CharacterLuigi.h"
#include "CharacterLuigi.h"
#include "Character.h"
#include <iostream>
#include "Texture2D.h"
#include "constants.h"

CharacterLuigi::CharacterLuigi(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position) : Character(renderer, imagePath, start_position)
{
}

CharacterLuigi::~CharacterLuigi()
{
	
}

void CharacterLuigi::Update(float deltaTime, SDL_Event e)
{
	AddGravity(deltaTime);

	//deal with jumping first
	if (m_jumping)
	{
		//adjust position
		m_position.y -= m_jump_force * deltaTime;

		//reduce jump force
		m_jump_force -= JUMP_FORCE_DECREMENT * deltaTime;

		//is jump force 0?
		if (m_jump_force <= 0.0f)
		{
			m_jumping = false;
		}


	}
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			m_moving_left = true;
			break;
		case SDLK_d:
			m_moving_right = true;
			break;
		case SDLK_w:
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
		case SDLK_a:
			m_moving_left = false;
			break;
		case SDLK_d:
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