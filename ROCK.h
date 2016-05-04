#ifndef ROCK_H
#define ROCK_H

#include <GL/glut.h>
#include "TextureManager.h"
#include "SCENE.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

class Rock{
public:

	GLint sprites;

	Rock();
	~Rock();

	GLvoid Draw();
};

#endif //ROCK_H