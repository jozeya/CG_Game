#ifndef FIREBALL_H
#define FIREBALL_H

#include <GL/glut.h>
#include "TextureManager.h"
#include "SCENE.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define TIME_SCENE 3

class Fireball{
public:

	GLint sprites;

	int _time;
	int timebase;
	int anim;
	int nro_sec_sprite;
	int dt;

	Scene* p_FIREBALL_Scene;
	pair<float,float> ini_scene;
	pair<float,float> end_scene;

	float x_posi;
	float y_posi;
	float speed1;


	Fireball();
	~Fireball();

	GLvoid Draw();
	GLvoid Randon();
};

#endif //FIREBALL_H