#pragma once

#include "MoveableEntity.h"

MoveableEntity::MoveableEntity()
	:Entity()
{
	
}

MoveableEntity::MoveableEntity(int a_iSpriteID, int a_iWidth, int a_iHeight, float a_fRotation, Vector2 a_v2Position, Vector2 a_v2Velocity, Vector2 a_v2Acceleration)
	: Entity(a_iSpriteID, a_iWidth, a_iHeight, a_fRotation, a_v2Position)
{
	
	m_v2Velocity = a_v2Velocity;
	m_v2Acceleration = a_v2Acceleration;
}

MoveableEntity::MoveableEntity(const MoveableEntity & a_copy)
	:Entity(a_copy.m_uiSpriteID, a_copy.m_iWidth, a_copy.m_iHeight, a_copy.m_fRotation, a_copy.m_v2Position)
{
	m_v2Velocity = a_copy.m_v2Velocity;
	m_v2Acceleration = a_copy.m_v2Acceleration;
}

MoveableEntity::~MoveableEntity()
{
}

void MoveableEntity::update(const float a_fdeltaTime)
{
	Entity::update(a_fdeltaTime);
	//s=ut+0.5ut^2
	setPosition(getPosition() + ((m_v2Velocity + (m_v2Acceleration*0.5*a_fdeltaTime)*a_fdeltaTime)));
	m_v2Velocity = m_v2Velocity + m_v2Acceleration*a_fdeltaTime;
}

void MoveableEntity::draw()
{
	Entity::draw();
}

void MoveableEntity::setVelocity(Vector2 a_v2Velocity)
{
	m_v2Velocity = a_v2Velocity;
}

void MoveableEntity::setAcceleration(Vector2 a_v2Acceleration)
{
	m_v2Acceleration = a_v2Acceleration;
}

Vector2 MoveableEntity::getVelocity() const 
{
	return m_v2Velocity;
}

Vector2 MoveableEntity::getAcceleration() const 
{
	return m_v2Acceleration;
}
