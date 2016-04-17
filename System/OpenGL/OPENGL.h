#ifndef OPENGL_H
#define OPENGL_H

#include <GL/glut.h>
#include <stdio.h>

#define GLUT_DISABLE_ATEXIT_HACK
#define ECHAP 27

class OpenGL
{
public:
	OpenGL();
	~OpenGL();

	bool Initialize(int, char**, int , int, char*);

	static OpenGL *Init();

	static void wd_Callback();
	static void wr_Callback(GLsizei,GLsizei);
	static void wk_Callback(unsigned char, int , int);
	static void wi_Callback();


	void render_scene();
	void init_scene();
	GLvoid InitGL();
	void window_display();
	GLvoid window_reshape(GLsizei, GLsizei);
	GLvoid window_key(unsigned char, int, int);
	GLvoid window_idle();


	void Shutdown();
private:
	static OpenGL* Instance;
	
};

#endif //OPENGL_H