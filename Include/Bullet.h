#pragma once
#ifndef __Bullet__
#define __Bullet__

#include "MoveableEntity.h"

class Bullet :public MoveableEntity
{
public:
	Bullet();
	Bullet(int a_iSpriteID, int a_iWidth, int a_iHeight, float a_fRotation, Vector2 a_v2Position, Vector2 a_v2Velocity, Vector2 a_v2Acceleration);
	Bullet(const Bullet& a_roBullet);
	~Bullet();

	void update(float a_fdeltaTime);
	void draw();
	bool isDead();

	void makeAlive();
	void kill();
protected:
	bool m_bIsDead;

	const float m_cfLifeTime = 5.f;

	float m_fLifeTimer;
};
#endif // !__Bullet__