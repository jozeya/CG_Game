#include "SCENE.h"

Scene::Scene(int nro){
	nro_scene = nro;	
}

Scene::~Scene(){}

void Scene::insert(float coord_ini_x, float coord_ini_y, float coord_end_x, float coord_end_y){
	Rect* tmp = new Rect();
	tmp -> set_Rect(coord_ini_x, coord_ini_y, coord_end_x, coord_end_y);
	p_mRect.push_back(tmp);
}

pair<float,float> Scene::get_iniPoint(int pos){
	return (p_mRect[pos] -> get_iniPoint());
}

pair<float,float> Scene::get_endPoint(int pos){
	return (p_mRect[pos] -> get_endPoint());
}