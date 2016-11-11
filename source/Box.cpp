#include "Box.h"

Box::Box()
{

}

Box::Box(Vector2 a_v2BottomLeft, Vector2 a_v2TopRight)
{
	m_v2BottomLeft = a_v2BottomLeft;
	m_v2TopRight = a_v2TopRight;
}

Box::Box(const Box & a_roCopy)
{
	m_v2BottomLeft = a_roCopy.m_v2BottomLeft;
	m_v2TopRight = a_roCopy.m_v2TopRight;
}

Box::~Box()
{

}

void Box::update()
{

}

void Box::draw()
{
	
	for (int i = 0; i < m_iLineThickness; i++)
	{
		//top
		UG::DrawLine((int)getLeft(), (int)getTop() - i, (int)getRight(), (int)getTop() - i, m_oColour);
		//bottom
		UG::DrawLine((int)getLeft(), (int)getBottom() + i + 1, (int)getRight(), (int)getBottom() + i + 1, m_oColour);
		//left
		UG::DrawLine((int)getLeft() + i, (int)getTop(), (int)getLeft() + i, (int)getBottom(), m_oColour);
		//right
		UG::DrawLine((int)getRight() - i, (int)getTop(), (int)getRight() - i, (int)getBottom(), m_oColour);
	}
	
}

float Box::getLeft()
{
	return m_v2BottomLeft.x;
}

float Box::getRight()
{
	return m_v2TopRight.x;
}

float Box::getTop()
{
	return m_v2TopRight.y;
}

float Box::getBottom()
{
	return m_v2BottomLeft.y;
}