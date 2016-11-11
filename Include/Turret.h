#pragma once
#ifndef __Turret__
#define __Turret__


#include "Entity.h"
#include "Bullet.h"

class Turret : public Entity
{
public:
	Turret();
	//constructor without controls
	Turret(int a_iSpriteID, int a_iWidth, int a_iHeight, float a_fRotation, Vector2 a_v2Position);
	//constructor with controls
	Turret(int a_iSpriteID, int a_iWidth, int a_iHeight, float a_fRotation, Vector2 a_v2Position, int a_iRotateleft, int a_iRotateRight, int a_iShoot);
	Turret(const Turret& a_oCopy);
	~Turret();

	void update(float a_fdeltatime, Vector2 a_v2ParentPosition);
	void draw();

	void setKeys(int a_iRotateleft, int a_iRotateRight, int a_iShoot);
	void fire(int a_iFiringBullet);

	Bullet & getBullet(int a_iBulletNum);

protected:
	const float mc_fRotationSpeed = 180.f;
	const float mc_fFireRate = 0.5f;
	const float mc_fFireSpeed = 4.f;
	int iBulletSprite1 = UG::CreateSprite("./images/Bullet.png", 16, 16, true, UG::SColour(255, 255, 255, 255));
	int iBulletSprite2 = UG::CreateSprite("./images/Bullet.png", 16, 16, true, UG::SColour(255, 255, 255, 255));
	int iBulletSprite3 = UG::CreateSprite("./images/Bullet.png", 16, 16, true, UG::SColour(255, 255, 255, 255));
	int iBulletSprite4 = UG::CreateSprite("./images/Bullet.png", 16, 16, true, UG::SColour(255, 255, 255, 255));
	int iBulletSprite5 = UG::CreateSprite("./images/Bullet.png", 16, 16, true, UG::SColour(255, 255, 255, 255));
	Bullet m_aoBulletArray[5]{ Bullet(iBulletSprite1,16,16,0,Vector2(-20.f,-20.f),Vector2(0.f,0.f),Vector2(0.f,0.f))
							  ,Bullet(iBulletSprite2,16,16,0,Vector2(-20.f,-20.f),Vector2(0.f,0.f),Vector2(0.f,0.f))
							  ,Bullet(iBulletSprite3,16,16,0,Vector2(-20.f,-20.f),Vector2(0.f,0.f),Vector2(0.f,0.f))
							  ,Bullet(iBulletSprite4,16,16,0,Vector2(-20.f,-20.f),Vector2(0.f,0.f),Vector2(0.f,0.f))
							  ,Bullet(iBulletSprite5,16,16,0,Vector2(-20.f,-20.f),Vector2(0.f,0.f),Vector2(0.f,0.f)) };
	int m_aiControlKeys[3];

	float m_fFireTimer;
	
};
#endif // !__Turret__


