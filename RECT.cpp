#include "RECT.h"

Rect::Rect(){}

Rect::~Rect(){}

void Rect::set_Rect(float inix, float iniy, float endx, float endy){
	ini_Point.first = inix;
	ini_Point.second = iniy;

	end_Point.first = endx;
	end_Point.second = endy;
}

pair<float,float> Rect::get_iniPoint(){
	return ini_Point;
}

pair<float,float> Rect::get_endPoint(){
	return end_Point;
}
