#ifndef WALL_H
#define WALL_H

#include <GL/glut.h>
#include "TextureManager.h"
#include "SCENE.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "RECT.h"


class Wall{

public:

	GLint texture;
	float x_posi;
	float y_posi;


	Rect* rectangle;
	Wall(float, float, float, float);
	~Wall();

	GLvoid Draw();

};

#endif //WALL_H