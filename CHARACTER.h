#define GLUT_DISABLE_ATEXIT_HACK
#ifndef CHARACTER_H
#define CHARACTER_H

#include <GL/glut.h>
#include "TextureManager.h"
#include <math.h>

#include <iostream>

using namespace std;

class Character{
public:
	GLint sprites;
	GLint texture;

	int _time;
	int timebase;
	int anim;
	int nro_sec_sprite;
	int dt;
	double x;
	double y;
	double x_jump;
	bool f_jump;
	double tmp;


	Character();
	virtual ~Character();

	GLvoid Draw();
	GLvoid Jump();
	GLvoid Run();
	
};


#endif //CHARACTER_H