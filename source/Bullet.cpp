#include "Bullet.h"

Bullet::Bullet()
	:MoveableEntity()
{
	m_bIsDead = true;
}

Bullet::Bullet(int a_iSpriteID, int a_iWidth, int a_iHeight, float a_fRotation, Vector2 a_v2Position, Vector2 a_v2Velocity, Vector2 a_v2Acceleration)
	: MoveableEntity(a_iSpriteID, a_iWidth, a_iHeight, a_fRotation, a_v2Position, a_v2Velocity, a_v2Acceleration)
{
	m_bIsDead = true;
}

Bullet::Bullet(const Bullet & a_roBullet)
	: MoveableEntity(a_roBullet.m_uiSpriteID, a_roBullet.m_iWidth, a_roBullet.m_iHeight, a_roBullet.m_fRotation, a_roBullet.m_v2Position, a_roBullet.m_v2Velocity, a_roBullet.m_v2Acceleration)
{
	m_bIsDead = a_roBullet.m_bIsDead;
}

Bullet::~Bullet()
{
}

void Bullet::update(float a_fdeltaTime)
{
 	MoveableEntity::update(a_fdeltaTime);
	m_fLifeTimer -= a_fdeltaTime;
	if (m_fLifeTimer < 0)
	{
		kill();
	}
}

void Bullet::draw()
{
	Entity::draw();
}

bool Bullet::isDead()
{
	return m_bIsDead;
}

void Bullet::makeAlive()
{
	draw();
	m_bIsDead = false;
	m_fLifeTimer = m_cfLifeTime;
}

void Bullet::kill()
{
	UG::StopDrawingSprite(getSprite());
	m_bIsDead = true;
	setRotation(0.f);
	m_v2Position = Vector2(-20.f, -20.f);
	m_v2Velocity = Vector2(0.f, 0.f);
	m_v2Acceleration = Vector2(0.f, 0.f);
	//move offscreen
}