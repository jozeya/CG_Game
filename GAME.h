#ifndef GAME_H
#define GAME_H

#include "CHARACTER.h"
#include "FIREBALL.h"
#include "STAGE.h"

class Game{
public:

	int current_Width;
	int current_Height;

	Character* p_mCharacter;
	Fireball*  p_mFireball;
	Stage* p_mStage;

	Game();
	~Game();

	void config_Game(int, int);
	void start_Game();
	void captureInput(unsigned char);
	void captureInputUP(int);

};

#endif //GAME_H