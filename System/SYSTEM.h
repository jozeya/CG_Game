#ifndef SYSTEM_H
#define SYSTEM_H

#include "Graphics/GRAPHICS.h"
#include "Input/INPUT.h"
#include "OpenGL/OPENGL.h"

static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 600;
static const bool FULL_SCREEN = false;

class System
{
public:
	System();
	~System();

	bool Init();
	void Shutdown();
	void MainLoop();

private:
	bool Frame();
	bool InitWindows();
	void ShutdownWindows();

private:
	int m_iWidth;
	int m_iHeight;

	OpenGL* m_pOpenGL;
	Graphics* m_pGraphics;
	Input* m_pInput;
};


#endif //SYSTEM_H