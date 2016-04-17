#ifndef SYSTEM_H
#define SYSTEM_H

#include "Graphics/GRAPHICS.h"
#include "Input/INPUT.h"
#include "OpenGL/OPENGL.h"

static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 600;
static const bool FULL_SCREEN = false;

using namespace std;

class System{

public:

	int m_iWidth;
	int m_iHeight;
	char *appName;

	OpenGL* m_pOpenGL;
	Graphics* m_pGraphics;
	Input* m_pInput;


	System();
	~System();

	bool Init(int, char**);
	void Shutdown();
	void MainLoop();

private:
	bool Frame();
	bool InitWindows();
	void ShutdownWindows();

};


#endif //SYSTEM_H