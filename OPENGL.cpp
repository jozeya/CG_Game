#include "OPENGL.h"

OpenGL* OpenGL::Instance = 0;

OpenGL::OpenGL(char* _appName, int _width, int _height, int posx_ini, int posy_ini):appName(_appName), width(_width), height(_height), ini_window_x(posx_ini), ini_window_y(posy_ini){
	//p_mCharacter = 0;
	p_mGame = 0;
}

OpenGL::OpenGL(){
	p_mGame = 0;
	//p_mCharacter = 0 ;
}

OpenGL::~OpenGL(){}

GLvoid OpenGL::config_Window(){

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(ini_window_x, ini_window_y);
	glutCreateWindow(appName);

}

GLvoid OpenGL::initGL(){

	/*GLfloat position[] = { 0.0f, 5.0f, 10.0f, 0.0 };

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

	glClearColor(0, 0, 0, 1);*/

	//Color del fondo de la escena
	glClearColor(0.4f, 0.4f, 0.4f, 0.2f); //(R, G, B, transparencia) en este caso un fondo negro
	glEnable(GL_TEXTURE_2D);
	//modo projeccion 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Get a handle for our "myTextureSampler" uniform

}

GLvoid OpenGL::Run(int argc, char** argv){

	glutInit(&argc, argv);
	config_Window();
	initGL();

	Init();
	Instance -> p_mGame -> config_Game(width, height);

	glutDisplayFunc(OpenGL::wd_Callback);
	glutReshapeFunc(OpenGL::wr_Callback);
	glutKeyboardFunc(OpenGL::wk_Callback);
	glutSpecialUpFunc(OpenGL::wkUP_Callback);

	glutSpecialFunc(OpenGL::cs_Callback);
	glutIdleFunc(OpenGL::wi_Callback);

	glutMainLoop();

}

void OpenGL::window_display(void){
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glOrtho(-25.0f, 25.0f, -25.0f, 25.0f, -25.0f, 25.0f);
	
	//Draw_Character();
	run_Game();

	glutSwapBuffers();

	glFlush();
}

GLvoid OpenGL::window_redraw(GLsizei width, GLsizei height) {

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-width / 50.0f, width / 50.0f, -height / 50.0f, height / 50.0f, -1.0f, 1.0f);

	// todas la informaciones previas se aplican al la matrice del ModelView
	glMatrixMode(GL_MODELVIEW);

}

GLvoid OpenGL::window_keys(unsigned char key, int x, int y){
	switch(key){
		case 27:
			exit(1);
			break;

		default:
			p_mGame -> captureInput(key);
			break;
	}
}

GLvoid OpenGL::window_keyUP(int key, int x, int y){
	
}

GLvoid OpenGL::window_idle(){
	glutPostRedisplay();
}

GLvoid OpenGL::callback_special(int key, int x, int y){
	if (key == GLUT_KEY_DOWN){
		p_mGame -> captureInput((char)key);
		glutPostRedisplay();			// et on demande le réaffichage.
	}
}

OpenGL* OpenGL::Init(){
	if (!Instance)
		Instance = new OpenGL();

	Instance -> p_mGame = new Game();

	return Instance;
}

void OpenGL::wd_Callback(void){
	Instance -> window_display();
}

GLvoid OpenGL::wk_Callback(unsigned char key, int x, int y){
	Instance -> window_keys(key, x, y);
}

GLvoid OpenGL::wi_Callback(){
	Instance -> window_idle();
}

GLvoid OpenGL::wr_Callback(GLsizei width, GLsizei height){
	Instance -> window_redraw(width, height);
}

GLvoid OpenGL::wkUP_Callback(int key, int x, int y){
	Instance -> window_keyUP(key,x,y);
}

GLvoid OpenGL::run_Game(){
	Instance -> p_mGame -> start_Game();
}

GLvoid OpenGL::cs_Callback(int key, int x, int y){
	Instance -> callback_special(key, x, y);
}