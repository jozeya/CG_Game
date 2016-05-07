#ifndef BOX_H
#define BOX_H

#include <GL/glut.h>
#include "TextureManager.h"
#include "SCENE.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "RECT.h"



class Box{
public:

	GLint texture;

	Rect* rectangle;
	Box(float,float,float,float);
	~Box();

	GLvoid Draw();

};

#endif //BOX_H