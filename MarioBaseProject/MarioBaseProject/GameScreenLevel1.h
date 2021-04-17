#pragma once
#ifndef _GAMESCREENLEVEL1_
#define _GAMESCREENLEVEL1_
#include "GameScreen.h"
#include "Commons.h"
#include "Character.h"
#include "CharacterMario.h"
#include "CharacterLuigi.h"
#include "Collisions.h"

class Texture2D;
class Character;
class CharacterMario;
class CharacterLuigi;

class GameScreenLevel1 : GameScreen
{
private:
	Texture2D* m_background_texture;
	bool SetUpLevel();
	Character* my_character;
	CharacterMario* my_character_mario;
	CharacterLuigi* my_character_luigi;

public:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;
};

#endif // !_GAMESCREENLEVEL1_
