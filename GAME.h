#ifndef GAME_H
#define GAME_H

#include "CHARACTER.h"
#include "FIREBALL.h"
#include "BOX.h"
#include "ROCK.h"
#include "STAGE.h"
#include "COINS.h"
#include "WALL.h"
#include <iostream>

using namespace std;

#define CHARACTER_X 0
#define CHARACTER_Y 0
#define CHARACTER_H 8
#define CHARACTER_W 6

#define FIREBALL_X 20
#define FIREBALL_Y 8
#define FIREBALL_H 3
#define FIREBALL_W 3

#define ROCK_X 10
#define ROCK_Y 0
#define ROCK_H 1.5
#define ROCK_W 1.5


#define WALL_X 10
#define WALL_Y 4
#define WALL_H 10
#define WALL_W 2

#define BOX_X 12
#define BOX_Y 0
#define BOX_H 2
#define BOX_W 2

#define COINS_X 11
#define COINS_Y 10
#define COINS_H 1
#define COINS_W 1


class Game{
public:

	int current_Width;
	int current_Height;

	Character* p_mCharacter;
	Fireball*  p_mFireball;
	Box* p_mBox;
	Rock* p_mRock;

	Coins* p_mCoins;
	Wall* p_mWall;

	Stage* p_mStage;

	Game();
	~Game();

	void config_Game(int, int);
	void start_Game();
	void captureInput(unsigned char);
	void captureInputUP(int);

	bool Collition();

};

#endif //GAME_H