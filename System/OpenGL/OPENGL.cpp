#include "OPENGL.h"

OpenGL* OpenGL::Instance = 0;

OpenGL::OpenGL()
{
	
}

OpenGL::~OpenGL()
{

}

void OpenGL::render_scene(){

}

void OpenGL::init_scene(){

}

GLvoid OpenGL::InitGL(){
	GLfloat position[] = { 0.0f, 5.0f, 10.0f, 0.0 };

	//enable light : try without it
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHTING);
	//light 0 "on": try without it
	glEnable(GL_LIGHT0);

	//shading model : try GL_FLAT
	glShadeModel(GL_SMOOTH);

	glEnable(GL_DEPTH_TEST);

	//enable material : try without it
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	glClearColor(0, 0, 0, 1);
}

float cs_x = 0;

void OpenGL::window_display(){;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-25.0f, 25.0f, -25.0f, 25.0f, -25.0f, 25.0f);
	
	glMatrixMode(GL_MODELVIEW);
	//glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
	glLoadIdentity();
	
	 gluLookAt(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//gluPerspective(10, 800/800, 0.3, 100);
	//glTranslatef(0,0,-30);

	/*dibujar aqui*/

	//sistemaSolar();
	glTranslatef(cs_x, 0, 0);
	glutSolidTeapot(3);
	//prueba1();
	//prueba2();
	//prueba3();
	//prueba4(5);

	glutSwapBuffers();

	glFlush();
}

GLvoid OpenGL::window_reshape(GLsizei width, GLsizei height){
	glViewport(0, 0, width, height);

}


GLvoid OpenGL::window_key(unsigned char key, int x, int y){
	switch (key) {
	case ECHAP:
		exit(1);
		break;

	default:
		printf("La touche %d non active.\n", key);
		break;
	}
}

GLvoid OpenGL::window_idle(){
	glutPostRedisplay();
}


void OpenGL::Shutdown()
{

}



bool OpenGL::Initialize(int argc, char **argv, int width, int height, char* appName)
{
	
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);


	glutInitWindowSize(width, height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(appName);


	InitGL();
	init_scene();
	

	glutDisplayFunc(OpenGL::wd_Callback);
	
	glutReshapeFunc(OpenGL::wr_Callback);

	glutKeyboardFunc(OpenGL::wk_Callback);
//------------
	glutSpecialFunc(OpenGL::cs_Callback);
//------------
	//function called on each frame
	glutIdleFunc(OpenGL::wi_Callback);

	glutMainLoop();

	return true;
}


OpenGL* OpenGL::Init(){
	if (!Instance)
		Instance = new OpenGL();
	return Instance;
}

void OpenGL::wd_Callback(){
	Instance -> window_display();
}

void OpenGL::wr_Callback(GLsizei width, GLsizei height){
	Instance -> window_reshape(width, height);
}

void OpenGL::wk_Callback(unsigned char key, int x, int y){
	Instance -> window_key(key, x, y);
}

void OpenGL::wi_Callback(){
	Instance -> window_idle();
}

GLvoid OpenGL::callback_special(int key, int x, int y){
	switch (key)
	{
	case GLUT_KEY_UP:
		//ys = ys + 2;
		glutPostRedisplay();			// et on demande le réaffichage.
		break;

	case GLUT_KEY_DOWN:
		//ys = ys - 2;
		glutPostRedisplay();			// et on demande le réaffichage.
		break;

	case GLUT_KEY_LEFT:					
		cs_x = cs_x - 0.5;
		glutPostRedisplay();			// et on demande le réaffichage.
		break;

	case GLUT_KEY_RIGHT:				
		cs_x = cs_x + 0.5;
		glutPostRedisplay();			// et on demande le réaffichage.
		break;
	}
}

void OpenGL::cs_Callback(int key, int x, int y){
	Instance -> callback_special(key, x, y);
}