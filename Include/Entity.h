#pragma once
#ifndef __Entity__
#define __Entity__

#include "UGFW.h"
#include "Enumerations.h"
#include "mathLib.h"

class Entity
{
public:
	Entity();
	Entity(int a_iSpriteID, int a_iWidth, int a_iHeight, float a_fRotation, Vector2 a_v2Position);
	Entity(const Entity& a_copy);
	~Entity();

	void update(const float a_fdeltaTime);
	void draw();

	void setSprite(unsigned int a_iSpriteID);
	void setWidth(int a_iWidth);
	void setHeight(int a_iHeight);
	void setRotation(float a_fRotation);
	void setPosition(Vector2 a_v2Position);

	unsigned int getSprite() const;
	int getWidth() const;
	int getHeight() const;
	float getRotation() const;
	Vector2 getPosition() const;
protected:
	unsigned int m_uiSpriteID;

	int m_iWidth;
	int m_iHeight;

	float m_fRotation;
	Vector2 m_v2Position;
};
#endif // !__Entity__