#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <math.h>

#include <GL/glut.h>

using namespace std;

class Character
{


public:
	int pos_x;
	int pos_y;
	int lado;
	float pi;
	float nuevo_x;
	float nuevo_y;
	float ang;

	Character(int, int, int);

	bool Init();
	
	void jump();

	~Character();
	
};

#endif //CHARACTER_H