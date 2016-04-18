#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Object/PROYECTIL.h"
#include "Object/CHARACTER.h"

#include <iostream>

using namespace std;

class Graphics
{
public:
	Proyectil* p_proyectil;
	Character* p_character;

	Graphics();
	~Graphics();

	bool Init();
	void Shutdown();
	bool Frame();
	void Render();
};

#endif //GRAPHICS_H