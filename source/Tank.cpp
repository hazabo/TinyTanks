#include "Tank.h"

Tank::Tank()
	:MoveableEntity()
{

}

Tank::Tank(int a_iSpriteID, int a_iWidth, int a_iHeight, float a_fRotation, Vector2 a_v2Position, Vector2 a_v2Velocity, Vector2 a_v2Acceleration)
	: MoveableEntity(a_iSpriteID, a_iWidth, a_iHeight, a_fRotation, a_v2Position, a_v2Velocity, a_v2Acceleration)
{
	m_aicontrolKeys[0] = NULL;
	m_aicontrolKeys[1] = NULL;
	m_aicontrolKeys[2] = NULL;
	m_aicontrolKeys[3] = NULL;
}

Tank::Tank(int a_iSpriteID, int a_iWidth, int a_iHeight, float a_fRotation, Vector2 a_v2Position, Vector2 a_v2Velocity, Vector2 a_v2Acceleration, int a_iRotateLeft, int a_iRotateRight, int a_iMoveForward, int a_iMoveBackwards)
	: MoveableEntity(a_iSpriteID, a_iWidth, a_iHeight, a_fRotation, a_v2Position, a_v2Velocity, a_v2Acceleration)
{
	m_aicontrolKeys[0] = a_iRotateLeft;
	m_aicontrolKeys[1] = a_iRotateRight;
	m_aicontrolKeys[2] = a_iMoveForward;
	m_aicontrolKeys[3] = a_iMoveBackwards;
}
Tank::Tank(const Tank & a_Tank)
	:MoveableEntity(a_Tank.m_uiSpriteID, a_Tank.m_iWidth, a_Tank.m_iHeight, a_Tank.m_fRotation, a_Tank.m_v2Position, a_Tank.m_v2Velocity, a_Tank.m_v2Acceleration)
{
	m_aicontrolKeys[0] = a_Tank.m_aicontrolKeys[0];
	m_aicontrolKeys[1] = a_Tank.m_aicontrolKeys[1];
	m_aicontrolKeys[2] = a_Tank.m_aicontrolKeys[2];
	m_aicontrolKeys[3] = a_Tank.m_aicontrolKeys[3];
}

Tank::~Tank()
{
}

void Tank::update(float a_fdeltaTime)
{
	MoveableEntity::update(a_fdeltaTime);
	if (UG::IsKeyDown(m_aicontrolKeys[0]))
	{
		//rotate left
		float rotation = mc_fRotationSpeed*a_fdeltaTime;
		setRotation(getRotation() - rotation);
		m_v2ForwardVector.Rotate(rotation);
	}
	else if (UG::IsKeyDown(m_aicontrolKeys[1]))
	{
		//rotate right
		float rotation = mc_fRotationSpeed*a_fdeltaTime;
		setRotation(getRotation() + rotation);
		m_v2ForwardVector.Rotate(-rotation);
	}

	if (UG::IsKeyDown(m_aicontrolKeys[2]))
	{
		//move forward
		//acceleration?
		setVelocity(m_v2ForwardVector * mc_fMovementSpeed);
	}
	else if (UG::IsKeyDown(m_aicontrolKeys[3]))
	{
		//move backward
		setVelocity(m_v2ForwardVector * -mc_fMovementSpeed);
	}
	else
	{
		setVelocity(Vector2(0, 0));
	}

}

void Tank::draw()
{
	MoveableEntity::draw();
	UG::DrawLine((int)getPosition().x, (int)getPosition().y, (int)(getPosition().x + m_v2ForwardVector.x*50.f), (int)(getPosition().y + m_v2ForwardVector.y*50.f), UG::SColour(0x00, 0xFC, 0x00, 0xFF));
}

void Tank::setControlKeys(int a_iRotateLeft, int a_iRotateRight, int a_iMoveForward, int a_iMoveBackwards)
{
	m_aicontrolKeys[0] = a_iRotateLeft;
	m_aicontrolKeys[1] = a_iRotateRight;
	m_aicontrolKeys[2] = a_iMoveForward;
	m_aicontrolKeys[3] = a_iMoveBackwards;
}