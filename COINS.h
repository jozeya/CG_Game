#ifndef COINS_H
#define COINS_H

#include <GL/glut.h>
#include "TextureManager.h"
#include "SCENE.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "RECT.h"


class Coins{

public:

	GLint texture;
	

	Rect* rectangle;

	Coins(float,float,float,float);
	~Coins();

	GLvoid Draw();

};

#endif //COINS_H