#ifndef BOX_H
#define BOX_H

#include <GL/glut.h>
#include "TextureManager.h"
#include "SCENE.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>



class Box{
public:

	GLint texture;

	
	Box();
	~Box();

	GLvoid Draw();

};

#endif //BOX_H