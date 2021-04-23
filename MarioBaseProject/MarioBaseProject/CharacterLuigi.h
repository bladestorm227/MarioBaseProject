#pragma once
#ifndef _LUIGICHARACTER_
#define _LUIGICHARACTER_
#include <iostream>
#include <SDL.h>
#include "Commons.h"
#include "Character.h"

class CharacterLuigi : public Character
{
public:
	CharacterLuigi(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map);
	~CharacterLuigi();
	virtual void Update(float deltaTime, SDL_Event e);;
};

#endif // !_LUIGICHARACTER_