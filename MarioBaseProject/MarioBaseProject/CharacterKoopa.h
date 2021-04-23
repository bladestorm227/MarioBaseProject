#pragma once
#ifndef _CHARACTERKOOPA_
#define _CHARACTERKOOPA_
#include <iostream>
#include <SDL.h>
#include "Commons.h"
#include "Character.h"

class CharacterKoopa : public Character
{
public:
	CharacterKoopa(SDL_Renderer* renderer, std::string imagePath, LevelMap* map, Vector2D start_position, FACING start_facing, float movement_speed);
	~CharacterKoopa();
	void TakeDamage();
	void Jump();
	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void SetAlive(bool isAlive) { m_alive = isAlive; };
	bool GetAlive() { return m_alive; };
	bool GetInjured() { return m_injured; };

protected:
	bool m_alive;
	
private:
	float m_single_sprite_w;
	float m_single_sprite_h;
	bool m_injured;
	float m_injured_time;
	void FlipRightwayUp();
	void Flip();
};

#endif // !_CHARACTERKOOPA_