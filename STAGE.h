#ifndef STAGE_H
#define STAGE_H

#include <GL/glut.h>
#include "TextureManager.h"
#include "SCENE.h"
#include <iostream>

using namespace std;

#define TIME_SCENE 4

class Stage{
public:
	GLint texture[TIME_SCENE];
	GLint sprites;
	int width;
	int height;

	int _time;
	int timebase;
	int anim;
	int nro_sec_back;
	int dt;

	//Scene* p_FIREBALL_Scene;
	//pair<float,float> ini_scene;
	//pair<float,float> end_scene;

	Stage();
	~Stage();

	GLvoid Draw(int, int);
};

#endif //STAGE_H