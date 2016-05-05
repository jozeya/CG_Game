#define GLUT_DISABLE_ATEXIT_HACK
#ifndef CHARACTER_H
#define CHARACTER_H

#include <GL/glut.h>
#include "TextureManager.h"
#include "SCENE.h"
#include <math.h>

#include <iostream>

#define KEY_JUMP 32
#define KEY_HIT 113
#define KEY_DOWN 103

#define TIME_RUN 8
#define TIME_JUMP 7
#define TIME_HIT 3
#define TIME_DOWN 7

#define STATE_RUN 0
#define STATE_JUMP 1
#define STATE_HIT 2
#define STATE_DOWN 3

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
	double tmp;
	bool is_running;
	int current_state;
	bool is_state_active;
	bool is_keydown_pressed;

	Scene* p_DOWN_Scene;
	Scene* p_JUMP_Scene;
	Scene* p_HIT_Scene;

	pair<float,float> ini_scene;
	pair<float,float> end_scene;


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