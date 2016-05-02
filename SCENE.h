#ifndef SCENE_H
#define SCENE_H

#include "RECT.h"
#include <vector>
#include <iostream>

using namespace std;

class Scene{
public:
	int nro_scene;
	vector <Rect* > p_mRect;

	Scene(int);
	~Scene();

	void insert(float, float, float, float);

	pair<float,float> get_iniPoint(int);
	pair<float,float> get_endPoint(int);

	// pScene[i] -> get_Rect()
};

#endif //SCENE_H