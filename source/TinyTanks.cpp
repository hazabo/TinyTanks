//#include "UGFW.h"
//#include "Enumerations.h"

#include "TinyTanks.h"
#include <iostream>
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext.hpp>
*/

//#include "ClickableButton.h"

void resolveCollBoxToPlayer(Box* a_roBox, Tank* a_roPlayer);
void resolveCollBoxToBullet(Box* a_roBox, Bullet* a_roBullet);
bool collPlayerToBullet(Tank* a_roPlayer, Bullet* a_roBullet);

int main(int argv, char* argc[])
{
	if (UG::Create( 1280, 720, false, "Tiny Tanks", 100, 100 ))
	{
		UG::SetBackgroundColor(UG::SColour(0xFF, 0xFF, 0xFF, 0xFF));
		UG::AddFont("./fonts/invaders.fnt");
		int iScreenWidth = 0, iScreenHeight = 0;
		UG::GetScreenSize(iScreenWidth, iScreenHeight);
		

		float iTankWidth = 64.f;
		float iTankHeight = 72.f;
		float iTurretWidth = 36.f;
		float iTurretHeight = 85.f;
		int iBlueTankSprite = UG::CreateSprite("./images/BlueTank.png",iTankWidth, iTankHeight, true, UG::SColour(255, 255, 255, 255));
		int iGreenTankSprite = UG::CreateSprite("./images/GreenTank.png", iTankWidth, iTankHeight, true, UG::SColour(255, 255, 255, 255));
		int iBlueTurretSprite = UG::CreateSprite("./images/BlueTurret.png", iTurretWidth, iTurretHeight, true, UG::SColour(255, 255, 255, 255));
		int iGreenTurretSprite = UG::CreateSprite("./images/GreenTurret.png", iTurretWidth, iTurretHeight, true, UG::SColour(255, 255, 255, 255));

		Tank oPlayer1Tank(iBlueTankSprite, iTankWidth, iTankHeight, 0, Vector2(0.f, 0.f), Vector2(0.f, 0.f), Vector2(0.f, 0.f), UG::KEY_A, UG::KEY_D, UG::KEY_W, UG::KEY_S);
		Turret oPlayer1Turret(iBlueTurretSprite, iTurretWidth, iTurretHeight, 0, Vector2(0.f, 0.f), UG::KEY_C, UG::KEY_V, UG::KEY_F);
		Tank oPlayer2Tank (iGreenTankSprite, iTankWidth, iTankHeight, 0, Vector2(0.f, 0.f), Vector2(0.f, 0.f), Vector2(0.f, 0.f), UG::KEY_J, UG::KEY_L, UG::KEY_I, UG::KEY_K);
		Turret oPlayer2Turret (iGreenTurretSprite, iTurretWidth, iTurretHeight, 0, Vector2(0.f, 0.f), UG::KEY_LEFT, UG::KEY_RIGHT, UG::KEY_UP);
		//Vector2(100.f, 100.f)  Vector2(200.f, 200.f)
		Box oMapBoxArray[14]{
			//top boundary
			Box(Vector2(0.f,iScreenHeight*0.95f),Vector2(iScreenWidth,iScreenHeight)),
			//bottom boundary
			Box(Vector2(0.f,0.f),Vector2(iScreenWidth,iScreenHeight*0.05f)),
			//left boundary
			Box(Vector2(0.f,0.f),Vector2(iScreenWidth*0.05f,iScreenHeight)),
			//right boundary
			Box(Vector2(iScreenWidth*0.95f,0.f),Vector2(iScreenWidth,iScreenHeight)),
			//centre cross vertical
			Box(Vector2(iScreenWidth*0.4f,iScreenHeight*0.45f),Vector2(iScreenWidth*0.6f,iScreenHeight*0.55f)),
			//centre cross horizontal
			Box(Vector2(iScreenWidth*0.47f,iScreenHeight*0.325f),Vector2(iScreenWidth*0.53f,iScreenHeight*0.675f)),
			//top left corner vertical
			Box(Vector2(iScreenWidth*0.175f,iScreenHeight*0.575f),Vector2(iScreenWidth*0.225f,iScreenHeight*0.8f)),
			//top left corner horizontal
			Box(Vector2(iScreenWidth*0.175f,iScreenHeight*0.725f),Vector2(iScreenWidth*0.325f,iScreenHeight*0.8f)),
			//top Right corner vertical
			Box(Vector2(iScreenWidth*0.775f,iScreenHeight*0.575f),Vector2(iScreenWidth*0.825f,iScreenHeight*0.8f)),
			//top Right corner horizontal
			Box(Vector2(iScreenWidth*0.675f,iScreenHeight*0.725f),Vector2(iScreenWidth*0.825f,iScreenHeight*0.8f)),
			//bottom left corner vertical
			Box(Vector2(iScreenWidth*0.175f,iScreenHeight*0.2f),Vector2(iScreenWidth*0.225f,iScreenHeight*0.425f)),
			//bottom left corner horizontal
			Box(Vector2(iScreenWidth*0.175f,iScreenHeight*0.2f),Vector2(iScreenWidth*0.325f,iScreenHeight*0.275f)),
			//bottom Right corner vertical
			Box(Vector2(iScreenWidth*0.775f,iScreenHeight*0.2f),Vector2(iScreenWidth*0.825f,iScreenHeight*0.425f)),
			//bottom Right corner horizontal
			Box(Vector2(iScreenWidth*0.675f,iScreenHeight*0.2f),Vector2(iScreenWidth*0.825f,iScreenHeight*0.275f)) };
		
		
		
		oPlayer1Tank.setPosition(Vector2(iScreenWidth*0.25f, iScreenHeight*0.25f));
		oPlayer2Tank.setPosition(Vector2(iScreenWidth*0.75f, iScreenHeight*0.75f));

		oPlayer1Tank.draw();
		oPlayer1Turret.draw();
		oPlayer2Tank.draw();
		oPlayer2Turret.draw();
		

		do 
		{
			float fDeltaTime = UG::GetDeltaTime();
			//update
			// quit our application when escape is pressed
			if (UG::IsKeyDown(UG::KEY_ESCAPE))
				UG::Close();


			oPlayer1Tank.update(fDeltaTime);
			oPlayer2Tank.update(fDeltaTime);

			//collision handling
			//player with boxes
			for (int i = 0; i < 14; i++)
			{
				resolveCollBoxToPlayer(&oMapBoxArray[i], &oPlayer1Tank);
			}
			for (int i = 0; i < 14; i++)
			{
				resolveCollBoxToPlayer(&oMapBoxArray[i], &oPlayer2Tank);
			}

			//bullets with boxes
			//for each bullet in the turrets
			for (int i = 0; i < 5;i++)
			{
				//for each wall
				for (int j = 0; j < 14; j++)
				{
					resolveCollBoxToBullet(&oMapBoxArray[j], &oPlayer1Turret.getBullet(i));
					resolveCollBoxToBullet(&oMapBoxArray[j], &oPlayer2Turret.getBullet(i));
				}
			}
			//bullets with player
			for (int i = 0; i < 5;i++)
			{
				if (collPlayerToBullet(&oPlayer1Tank, &oPlayer1Turret.getBullet(i)))
				{
					oPlayer1Turret.getBullet(i).kill();
					oPlayer1Tank.setPosition(Vector2(iScreenWidth*0.25f, iScreenHeight*0.25f));
				}
				else if (collPlayerToBullet(&oPlayer2Tank, &oPlayer1Turret.getBullet(i)))
				{
					oPlayer1Turret.getBullet(i).kill();
					oPlayer2Tank.setPosition(Vector2(iScreenWidth*0.75f, iScreenHeight*0.75f));
				}

				if (collPlayerToBullet(&oPlayer1Tank, &oPlayer2Turret.getBullet(i)))
				{
					oPlayer2Turret.getBullet(i).kill();
					oPlayer1Tank.setPosition(Vector2(iScreenWidth*0.25f, iScreenHeight*0.25f));
				}
				else if (collPlayerToBullet(&oPlayer2Tank, &oPlayer2Turret.getBullet(i)))
				{
					oPlayer2Turret.getBullet(i).kill();
					oPlayer2Tank.setPosition(Vector2(iScreenWidth*0.75f, iScreenHeight*0.75f));
				}

			}
			//turrets do not have collision so are updated after collisions are applied
			oPlayer1Turret.update(fDeltaTime, oPlayer1Tank.getPosition());
			oPlayer2Turret.update(fDeltaTime, oPlayer2Tank.getPosition());
			//Draw
			UG::ClearScreen();

			
			for (int i = 0; i < 14; i++)
			{
				oMapBoxArray[i].draw();
			}

			

		} while (UG::Process());

		UG::DestroySprite(iBlueTankSprite);
		UG::DestroySprite(iGreenTankSprite);
		UG::DestroySprite(iBlueTurretSprite);
		UG::DestroySprite(iGreenTurretSprite);
		
		UG::Dispose();


	}
	return 0;
}

void resolveCollBoxToPlayer(Box* a_roBox, Tank* a_roPlayer)
{
	//include widths and heights?
	
	//get positions
	Vector2 v2PlayerPosition = a_roPlayer->getPosition();
	Vector2 v2PlayerSize = Vector2(a_roPlayer->getWidth(), a_roPlayer->getHeight());
	float fBoxLeft = a_roBox->getLeft();
	float fBoxRight = a_roBox->getRight();
	float fBoxTop = a_roBox->getTop();
	float fBoxBottom = a_roBox->getBottom();

	//find collisions
	bool bVerticalCollision = (v2PlayerPosition.y - v2PlayerSize.y*0.5f < fBoxTop && v2PlayerPosition.y + v2PlayerSize.y*0.5f> fBoxBottom);
	bool bHorizontalCollision = (v2PlayerPosition.x - v2PlayerSize.x*0.5f< fBoxRight && v2PlayerPosition.x + v2PlayerSize.x*0.5f> fBoxLeft);

	if (bVerticalCollision && bHorizontalCollision)
	{
		//find box centre
		Vector2 v2BoxCentre;
		v2BoxCentre.x = (fBoxLeft + fBoxRight)*0.5f;
		v2BoxCentre.y = (fBoxBottom + fBoxTop)*0.5f;
		Vector2 v2BoxCentreToPlayerPos = v2BoxCentre - v2PlayerPosition;
		bool bToRight = false;
		bool bToTop = false;
		if (v2BoxCentreToPlayerPos.x < 0)
		{
			v2BoxCentreToPlayerPos.x *= -1.f;
			bToRight = true;
		}
		if (v2BoxCentreToPlayerPos.y < 0)
		{
			v2BoxCentreToPlayerPos.y *= -1.f;
			bToTop = true;
		}
		if (v2BoxCentreToPlayerPos.x/(fBoxRight - v2BoxCentre.x) > v2BoxCentreToPlayerPos.y/(fBoxTop - v2BoxCentre.y))
		{
			if (bToRight)
			{
				//shift to right of box
				a_roPlayer->setPosition(Vector2(fBoxRight + v2PlayerSize.x*0.5 + 1.f, v2PlayerPosition.y));
			}
			else
			{
				//shift to left of box
				a_roPlayer->setPosition(Vector2(fBoxLeft - v2PlayerSize.x*0.5f - 1.f, v2PlayerPosition.y));
			}
		}
		else
		{
			if (bToTop)
			{
				//shift to top of box
				a_roPlayer->setPosition(Vector2(v2PlayerPosition.x, fBoxTop + 1.f + v2PlayerSize.y *0.5f));
			}
			else
			{
				//shift to bottom of box
				a_roPlayer->setPosition(Vector2(v2PlayerPosition.x, fBoxBottom - 1.f - v2PlayerSize.y*0.5f));
			}
		}
		a_roPlayer->setVelocity(Vector2(0.f, 0.f));
	}
	//else do nothing
}

void resolveCollBoxToBullet(Box* a_roBox, Bullet* a_roBullet)
{
	Vector2 v2BulletPosition = a_roBullet->getPosition();
	float fBulletSize = a_roBullet->getWidth();
	float fBulletHalfSize = fBulletSize*0.5f;
	float fBoxLeft = a_roBox->getLeft();
	float fBoxRight = a_roBox->getRight();
	float fBoxTop = a_roBox->getTop();
	float fBoxBottom = a_roBox->getBottom();
	bool bVerticalCollision = (v2BulletPosition.y - fBulletHalfSize < fBoxTop && v2BulletPosition.y + fBulletHalfSize > fBoxBottom);
	bool bHorizontalCollision = (v2BulletPosition.x - fBulletHalfSize < fBoxRight && v2BulletPosition.x + fBulletHalfSize > fBoxLeft);
	if (bVerticalCollision && bHorizontalCollision)
	{
		//find box centre
		Vector2 v2BoxCentre;
		v2BoxCentre.x = (fBoxLeft + fBoxRight)*0.5f;
		v2BoxCentre.y = (fBoxBottom + fBoxTop)*0.5f;
		Vector2 v2BoxCentreToBulletPos = v2BoxCentre - v2BulletPosition;
		Vector2 v2NewbulletVelocity = a_roBullet->getVelocity();
		if (v2BoxCentreToBulletPos.x < 0)
		{
			v2BoxCentreToBulletPos.x *= -1.f;
		}
		if (v2BoxCentreToBulletPos.y < 0)
		{
			v2BoxCentreToBulletPos.y *= -1.f;
		}

		if (v2BoxCentreToBulletPos.x / (fBoxRight - v2BoxCentre.x) > v2BoxCentreToBulletPos.y / (fBoxTop - v2BoxCentre.y))
		{
			v2NewbulletVelocity.x *= -1.f;
		}
		else
		{
			v2NewbulletVelocity.y *= -1.f;
		}
		a_roBullet->setVelocity(v2NewbulletVelocity);
	}

}


bool collPlayerToBullet(Tank* a_roPlayer, Bullet* a_roBullet)
{
	Vector2 v2BulletPosition = a_roBullet->getPosition();
	Vector2 v2PlayerPosition = a_roPlayer->getPosition();
	float fBulletSize = a_roBullet->getWidth();
	Vector2 v2PlayerSize = Vector2(a_roPlayer->getWidth(), a_roPlayer->getHeight());


	//test vertical collision
	if (v2BulletPosition.y - fBulletSize*0.5f < v2PlayerPosition.y + v2PlayerSize.y*0.5f && v2BulletPosition.y + fBulletSize*0.5f > v2PlayerPosition.y - v2PlayerSize.y*0.5f)
	{
		//test horizontal collision
		if (v2BulletPosition.x - fBulletSize*0.5f < v2PlayerPosition.x + v2PlayerSize.x*0.5f && v2BulletPosition.x + fBulletSize*0.5f > v2PlayerPosition.x - v2PlayerSize.x*0.5f)
		{
			return true;
		}
	}
	return false;
}