#include "Turret.h" 
#include "Bullet.h"
#include <math.h>

Turret::Turret()
	:Entity()
{
}

Turret::Turret(int a_iSpriteID, int a_iWidth, int a_iHeight, float a_fRotation, Vector2 a_v2Position)
	:Entity(a_iSpriteID, a_iWidth, a_iHeight, a_fRotation, a_v2Position)
{
}

Turret::Turret(int a_iSpriteID, int a_iWidth, int a_iHeight, float a_fRotation, Vector2 a_v2Position, int a_iRotateleft, int a_iRotateRight, int a_iShoot)
	: Entity(a_iSpriteID, a_iWidth, a_iHeight, a_fRotation, a_v2Position)
{
	m_aiControlKeys[0] = a_iRotateleft;
	m_aiControlKeys[1] = a_iRotateRight;
	m_aiControlKeys[2] = a_iShoot;
}

Turret::Turret(const Turret & a_oCopy)
	: Entity(a_oCopy)
{
	m_aiControlKeys[0] = a_oCopy.m_aiControlKeys[0];
	m_aiControlKeys[1] = a_oCopy.m_aiControlKeys[1];
	m_aiControlKeys[2] = a_oCopy.m_aiControlKeys[2];
}

Turret::~Turret()
{
	UG::DestroySprite(iBulletSprite1);
	UG::DestroySprite(iBulletSprite2);
	UG::DestroySprite(iBulletSprite3);
	UG::DestroySprite(iBulletSprite4);
	UG::DestroySprite(iBulletSprite5);
}

void Turret::update(float a_fdeltaTime, Vector2 a_v2ParentPosition)
{
	Entity::update(a_fdeltaTime);
	for (int i = 0; i <= 4; i++)
	{
		if (!m_aoBulletArray[i].isDead())
		{
			m_aoBulletArray[i].update(a_fdeltaTime);
		}
	}

	m_fFireTimer -= a_fdeltaTime;

	setPosition(a_v2ParentPosition);

	if (UG::IsKeyDown(m_aiControlKeys[0]))
	{
		//rotate left
		float rotation = mc_fRotationSpeed*a_fdeltaTime;
		setRotation(getRotation() - rotation);
	}
	else if (UG::IsKeyDown(m_aiControlKeys[1]))
	{
		//rotate right
		float rotation = mc_fRotationSpeed*a_fdeltaTime;
		setRotation(getRotation() + rotation);
	}

	if (UG::IsKeyDown(m_aiControlKeys[2]))
	{
		if (m_fFireTimer < 0)
		{
			int i = 0;
			bool bEndReached=false;
			//until a bullet that is not fired is found
			//look for one
			
			while (!m_aoBulletArray[i].isDead()&&!bEndReached)
			{
				//if end of array reached
				if (i == 4)
				{
					//stop looking
					bEndReached = true;
				}
				//else keep looking
				else
				{
					i++;
				}
				
				
			}
			//if none are found do not fire
			if (m_aoBulletArray[i].isDead())
			{
				fire(i);
				m_fFireTimer = mc_fFireRate;
			}
			
			
		}
	}

}

void Turret::draw()
{
	Entity::draw();
}

void Turret::setKeys(int a_iRotateleft, int a_iRotateRight, int a_iShoot)
{
	m_aiControlKeys[0] = a_iRotateleft;
	m_aiControlKeys[1] = a_iRotateRight;
	m_aiControlKeys[2] = a_iShoot;
}

void Turret::fire(int a_iFiringBullet)
{
	float currentRotation = getRotation();
	//x and y compoents of a vector are sin and cos theta respectively where theta is the angle between "north" and the vector
	Vector2 direction = Vector2(sinf(currentRotation*M_PI/180.f), cosf(currentRotation*M_PI / 180.f));

	m_aoBulletArray[a_iFiringBullet].setPosition(m_v2Position + direction*58.f/*totally not a magic number*/);
	m_aoBulletArray[a_iFiringBullet].setVelocity(direction*mc_fFireSpeed);
	m_aoBulletArray[a_iFiringBullet].setRotation(currentRotation);
	m_aoBulletArray[a_iFiringBullet].makeAlive();
}

Bullet& Turret::getBullet(int a_iBulletNum)
{
	return m_aoBulletArray[a_iBulletNum];
}
