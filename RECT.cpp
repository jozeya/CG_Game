#include "RECT.h"

Rect::Rect()
{

}

Rect::~Rect(){}

void Rect::set_Rect(float inix, float iniy, float endx, float endy){
	ini_Point.first = inix;
	ini_Point.second = iniy;

	end_Point.first = endx;
	end_Point.second = endy;
}

void Rect::ini_Values(float xs, float ys, float hs, float ws)
{
	x = xs;
	y = ys;
	h = hs;
	w = ws;
}

bool Rect::collide(Rect* pro)
{
	float left = x;
	float right = y + w;
	float top = y + h;
	float bottom = y;

	float r_left = pro-> x;
	float r_right = pro-> x + pro-> w;
	float r_top = pro-> y + pro-> h;
	float r_bottom = pro-> y;

	return ((right >= r_left) && (left <= r_right) && (top >= r_bottom) && (bottom <= r_top)); 
}

pair<float,float> Rect::get_iniPoint(){
	return ini_Point;
}

pair<float,float> Rect::get_endPoint(){
	return end_Point;
}
