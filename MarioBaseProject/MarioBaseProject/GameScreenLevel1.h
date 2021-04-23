#pragma once
#ifndef _GAMESCREENLEVEL1_
#define _GAMESCREENLEVEL1_
#include "GameScreen.h"
#include "Commons.h"
#include "Character.h"
#include "CharacterMario.h"
#include "CharacterLuigi.h"
#include "Collisions.h"
#include "LevelMap.h"

class Texture2D;
class Character;
class CharacterMario;
class CharacterLuigi;
class PowBlock;

class GameScreenLevel1 : GameScreen
{
private:
	Texture2D* m_background_texture;
	bool SetUpLevel();
	Character* my_character;
	CharacterMario* my_character_mario;
	CharacterLuigi* my_character_luigi;
	void SetLevelMap();
	LevelMap* m_level_map;
	PowBlock* m_pow_block;
	bool m_screenshake;
	float m_shake_time;
	float m_wobble;
	float m_background_yPos;
	void DoScreenShake();

public:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;
	void UpdatePOWBlock();
};

#endif // !_GAMESCREENLEVEL1_
