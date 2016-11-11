#pragma once
#ifndef __BOX__
#define __BOX__

#include "Entity.h"

class Box
{
public:
	Box();
	Box(Vector2 a_v2BottomLeft, Vector2 a_v2TopRight);
	Box(const Box& a_roCopy);
	~Box();

	void update();
	void draw();

	float getLeft();
	float getRight();
	float getTop();
	float getBottom();

protected:
	Vector2 m_v2BottomLeft;
	Vector2 m_v2TopRight;
	UG::SColour m_oColour = UG::SColour(0x00, 0x00, 0x00, 0xFF);
	int m_iLineThickness = 5;
};



#endif // !__Entity__