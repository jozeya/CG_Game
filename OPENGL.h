#define GLUT_DISABLE_ATEXIT_HACK	
#ifndef OPENGL_H
#define OPENGL_H	

#include <GL/glut.h>
#include <iostream>
//#include "CHARACTER.h"
#include "GAME.h"
#include "TextureManager.h"

using namespace std;

class OpenGL{
public:
	char* appName;
	int width;
	int height;
	int ini_window_x;
	int ini_window_y;

	//Character *p_mCharacter;
	Game* p_mGame;

	OpenGL(char*, int, int, int, int);
	OpenGL();
	~OpenGL();

	GLvoid config_Window();
	GLvoid Run(int, char**);
	GLvoid initGL();
	void window_display(void);
	GLvoid window_idle();
	GLvoid window_keys(unsigned char, int, int);
	GLvoid window_redraw(GLsizei, GLsizei);
	GLvoid window_keyUP(unsigned char, int, int);
	static OpenGL *Init();

private:
	static OpenGL* Instance;
	static void wd_Callback(void);
	static GLvoid wk_Callback(unsigned char, int , int);
	static GLvoid wkUP_Callback(unsigned char, int , int);
	static GLvoid wi_Callback();
	static GLvoid wr_Callback(GLsizei,GLsizei);
	//static GLvoid Draw_Character();
	static GLvoid run_Game();
};

#endif //OPENGL_H