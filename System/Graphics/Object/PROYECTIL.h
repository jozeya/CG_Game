#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <iostream>

#include <GL/glut.h>

using namespace std;

class Proyectil
{
public:
	int pos_x;
	int pos_y;
	int radio;

	Proyectil(int, int, int);

	bool Init();
	void Print();

	~Proyectil();
	
};

#endif //PROYECTIL_H