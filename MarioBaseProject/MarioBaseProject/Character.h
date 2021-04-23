#pragma once
#ifndef _CHARACTER_
#define _CHARACTER_
#include <iostream>
#include <SDL.h>
#include "Commons.h"
#include "Texture2D.h"
#include "LevelMap.h"

class Texture2D;

class Character
{
protected :
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
	bool m_moving_left;
	bool m_moving_right;
	bool m_jumping;
	bool m_can_jump;
	float m_jump_force;
	float m_collision_radius;
	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);
	virtual void Jump();

public :
	Character(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map);
	~Character();

	float GetCollisionRadius();
	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void SetPosition(Vector2D new_position);
	Vector2D GetPosition();
	virtual void AddGravity(float deltaTime);
	Rect2D GetCollisionBox() { return Rect2D(m_position.x, m_position.y, m_texture->GetWidth(), m_texture->GetHeight()); }
	bool IsJumping() { return m_jumping; };
	void CancelJump() { m_jumping = false; };
	FACING m_facing_direction;
	float m_movement_speed;

private:
	LevelMap* m_current_level_map;
};

#endif // !_CHARACTER_