#ifndef ROCK_H
#define ROCK_H

#include <GL/glut.h>
#include "TextureManager.h"
#include "SCENE.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "RECT.h"

class Rock{
public:

	GLint sprites;

	Rect* rectangle;
	Rock(float,float,float,float);
	~Rock();

	GLvoid Draw();
};

#endif //ROCK_H