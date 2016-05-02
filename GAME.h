#ifndef GAME_H
#define GAME_H

#include "CHARACTER.h"

class Game{
public:

	Character* p_mCharacter;
	Game();
	~Game();

	void start_Game();
	void captureInput(unsigned char);
	void captureInputUP(int);
};

#endif //GAME_H