#pragma once
#ifndef _MARIOCHARACTER_
#define _MARIOCHARACTER_
#include <iostream>
#include <SDL.h>
#include "Commons.h"
#include "Character.h"

class CharacterMario : public Character
{
protected:
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
	bool m_moving_left;
	bool m_moving_right;
	bool m_jumping;
	bool m_can_jump;
	float m_jump_force;
	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);
	virtual void Jump();

public:
	CharacterMario(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position);
	~CharacterMario();
	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void SetPosition(Vector2D new_position);
	Vector2D GetPosition();
	virtual void AddGravity(float deltaTime);
private:
	FACING m_facing_direction;
};

#endif // !_MARIOCHARACTER_