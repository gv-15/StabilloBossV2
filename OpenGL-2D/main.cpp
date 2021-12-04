#include "stdafx.h"
#include "GameLogic.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Player.h"
#include "World.h"
#include "Wall.h"
#include "Text.h"
#include "Projectile.h"
#include "Text.h"
#include "TextureManager.h"
#include <iostream>
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "AnimatedSprite.h"
#include "../3rd-party/SoundManager/SoundManager.h" //relative path to the main header
using namespace std;



int main(int argc, char** argv)
{

	Renderer renderer;
	TextureManager textureManager;

	

#ifdef _DEBUG
	textureManager.SetVerbose(true);
#endif

	renderer.SetFrameRate(30);
	GameLogic gameLogic(&renderer);
	renderer.Initialize(argc, argv);
	Sprite sprite = Sprite("/img/notebook", 0, 0, 10, 10);
	sprite.SetName("background");
	Sprite live1P1 = Sprite("/img/heart1", 0.7, 0.9, 0.10, 0.10);
	Sprite live2P1 = Sprite("/img/heart1", 0.8, 0.9, 0.10, 0.10);
	Sprite live3P1 = Sprite("/img/heart1", 0.9, 0.9, 0.10, 0.10);
	Sprite live1P2 = Sprite("/img/heart1", -0.7, 0.9, 0.10, 0.10);
	Sprite live2P2 = Sprite("/img/heart1", -0.8, 0.9, 0.10, 0.10);
	Sprite live3P2 = Sprite("/img/heart1", -0.9, 0.9, 0.10, 0.10);
	Player player1 = Player("/img/PLAYER1 ROSA SMALL", 0.9, 0, 0.084, 0.2);
	player1.SetName("Player1");
	Player player2 = Player("/img/PLAYER2 VERDEAZUL SMALL", -0.9, 0, 0.084, 0.2);
	player2.SetName("Player2");
	Wall wall1 = Wall("/img/wall1", 0, 0, 0.1, 1);
	wall1.SetName("wall1");
	Wall wall2 = Wall("/img/wall2", -0.6, 0.3, 0.5, 0.05);
	wall2.SetName("wall2");
	Wall wall3 = Wall("/img/wall2", 0.6, -0.3, 0.5, 0.05);
	wall3.SetName("wall3");
	gameLogic.Initialize();

	renderer.AddObject(&live1P1);
	renderer.AddObject(&live2P1);
	renderer.AddObject(&live3P1);
	renderer.AddObject(&live1P2);
	renderer.AddObject(&live2P2);
	renderer.AddObject(&live3P2);
	renderer.AddObject(&player1);
	renderer.AddObject(&player2);
	renderer.AddObject(&wall1);
	renderer.AddObject(&wall2);
	renderer.AddObject(&wall3);
	renderer.AddObject(&sprite);


	while (!gameLogic.IsGameEnded())
	{
		//UPDATE////////////////////
		////////////////////////////
		//process queued events
		glutMainLoopEvent();
		gameLogic.ProcessEvents();


		//RENDER////////////////////
		////////////////////////////
		glutPostRedisplay();
		glutSwapBuffers();
	}
	
}
