#include "Entity.h"

Entity::Entity()
{
	
}

Entity::Entity(int a_iSpriteID, int a_iwidth, int a_iHeight, float a_fRotation, Vector2 a_v2Position)
{
	m_uiSpriteID = a_iSpriteID;
	m_iWidth = a_iwidth;
	m_iHeight = a_iHeight;
	m_fRotation = a_fRotation;
	m_v2Position = a_v2Position;
	UG::MoveSprite(m_uiSpriteID, m_v2Position.x, m_v2Position.y);
}

Entity::Entity(const Entity & a_copy)
{
	m_uiSpriteID = a_copy.m_uiSpriteID;
	m_iWidth = a_copy.m_iWidth;
	m_iHeight = a_copy.m_iHeight;
	m_fRotation = a_copy.m_fRotation;
	m_v2Position = a_copy.m_v2Position;
	UG::MoveSprite(m_uiSpriteID, m_v2Position.x, m_v2Position.y);
}

Entity::~Entity()
{
	UG::DestroySprite(m_uiSpriteID);
}

void Entity::update(const float a_fdeltaTime)
{

}

void Entity::draw()
{
	UG::DrawSprite(m_uiSpriteID);
}

void Entity::setSprite(unsigned int a_iSpriteID)
{
	m_uiSpriteID = a_iSpriteID;
}

void Entity::setWidth(int a_iWidth)
{
	m_iWidth = a_iWidth;
}

void Entity::setHeight(int a_iHeight)
{
	m_iHeight = a_iHeight;
}

void Entity::setRotation(float a_fRotation)
{
	UG::RotateSprite(m_uiSpriteID, m_fRotation - a_fRotation);
	while (a_fRotation > 360)
	{
		a_fRotation -= 360;
	}
	while (a_fRotation < 0)
	{
		a_fRotation += 360;
	}
	m_fRotation = a_fRotation;
	
	//unsure
}

void Entity::setPosition(Vector2 a_v2Position)
{
	m_v2Position = a_v2Position;
	UG::MoveSprite(m_uiSpriteID, m_v2Position.x, m_v2Position.y);
}

unsigned int Entity::getSprite() const 
{
	return m_uiSpriteID;
}

int Entity::getWidth() const
{
	return m_iWidth;
}

int Entity::getHeight() const
{
	return m_iHeight;
}

float Entity::getRotation() const
{
	return m_fRotation;
}

Vector2 Entity::getPosition() const 
{
	return m_v2Position;
}
