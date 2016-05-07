#ifndef FIREBALL_H
#define FIREBALL_H

#include <GL/glut.h>
#include "TextureManager.h"
#include "SCENE.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "RECT.h"

using namespace std; 
#define TIME_SCENE 3

class Fireball{
public:

	GLint sprites;

	float _time;
	float timebase;
	int anim;
	int nro_sec_sprite;
	float dt;

	Scene* p_FIREBALL_Scene;
	pair<float,float> ini_scene;
	pair<float,float> end_scene;

	float x_posi;
	float y_posi;
	float speed1;

	Rect* rectangle;
	Fireball(float,float,float,float);
	~Fireball();

	GLvoid Draw();
	GLvoid Randon();
	GLvoid In_scene();

};

#endif //FIREBALL_H