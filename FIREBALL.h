#ifndef FIREBALL_H
#define FIREBALL_H

#include <GL/glut.h>
#include "TextureManager.h"
#include "SCENE.h"

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

	Fireball();
	~Fireball();

	GLvoid Draw();
};

#endif //FIREBALL_H