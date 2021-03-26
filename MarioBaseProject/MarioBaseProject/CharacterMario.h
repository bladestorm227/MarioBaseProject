#pragma once
#ifndef _MARIOCHARACTER_
#define _MARIOCHARACTER_
#include <iostream>
#include <SDL.h>
#include "Commons.h"
#include "Character.h"

class CharacterMario : public Character
{
public:
	CharacterMario(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position);
	~CharacterMario();
	virtual void Update(float deltaTime, SDL_Event e);
};

#endif // !_MARIOCHARACTER_