#pragma once
#ifndef __MoveableEntity__
#define __MoveableEntity__


#include "Entity.h"

class MoveableEntity : public Entity
{
public:
	MoveableEntity();
	MoveableEntity(int a_iSpriteID, int a_iWidth, int a_iHeight, float a_fRotation, Vector2 a_v2Position, Vector2 a_v2Velocity, Vector2 a_v2Acceleration);
	MoveableEntity(const MoveableEntity& a_copy);
	~MoveableEntity();

	void update(const float a_fdeltaTime);
	void draw();

	void setVelocity(Vector2 a_v2Velocity);
	void setAcceleration(Vector2 a_v2Acceleration);

	Vector2 getVelocity() const;
	Vector2 getAcceleration() const ;


protected:
	Vector2 m_v2Velocity;
	
	Vector2 m_v2Acceleration;
};
#endif // !__MoveableEntity__