#define GLUT_DISABLE_ATEXIT_HACK
#ifndef CHARACTER_H
#define CHARACTER_H

#include <GL/glut.h>
#include "TextureManager.h"
#include <math.h>

#include <iostream>
#define RUN 8
#define JUMP 7
#define HIT 3
#define DOWN 3

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
	double x_hit;
	double x_down;
	int nro_scene;
	bool f_jump;
	bool f_hit;
	bool f_down;
	double tmp;
	bool is_running;



	Character();
	~Character();

	GLvoid input(unsigned char);

	GLvoid Draw();
	GLvoid Jump();
	GLvoid Run();
	GLvoid Hit();
	GLvoid Down();
	
};


#endif //CHARACTER_H