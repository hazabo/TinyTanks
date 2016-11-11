#pragma once
#ifndef __Tank__
#define __Tank__


#include "MoveableEntity.h"

class Tank: public MoveableEntity
{
public:
	Tank();
	//constructor without controls
	Tank(int a_SpriteID, int a_iWidth, int a_iHeight, float a_fRotation, Vector2 a_Position, Vector2 a_Velocity, Vector2 a_Acceleration);
	//constructor with controls
	Tank(int a_SpriteID, int a_iWidth, int a_iHeight, float a_fRotation, Vector2 a_Position, Vector2 a_Velocity, Vector2 a_Acceleration, int a_iRotateLeft, int a_iRotateRight, int a_iMoveForward, int a_iMoveBackwards);
	Tank(const Tank& a_roTank);
	~Tank();

	void update(float a_fdeltaTime);

	void draw();

	void setControlKeys(int a_iRotateLeft, int a_iRotateRight, int a_iMoveForward, int a_iMoveBackwards);


protected:
	int m_aicontrolKeys[4];

	const float mc_fRotationSpeed = 180.0f;
	const float mc_fMovementSpeed = 3.0f;

	Vector2 m_v2ForwardVector = Vector2(0, 1);
};
#endif // !__Tank__