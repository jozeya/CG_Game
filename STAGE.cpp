#include "STAGE.h"

Stage::Stage(){
	texture[0] = TextureManager::Inst()->LoadTexture("textures/stage1-1.bmp", GL_BGR_EXT, GL_RGB);
	texture[1] = TextureManager::Inst()->LoadTexture("textures/stage1-2.bmp", GL_BGR_EXT, GL_RGB);
	texture[2] = TextureManager::Inst()->LoadTexture("textures/stage1-3.bmp", GL_BGR_EXT, GL_RGB);
	texture[3] = TextureManager::Inst()->LoadTexture("textures/stage1-4.bmp", GL_BGR_EXT, GL_RGB);

	_time = 0;
	timebase = 0;
	dt = 0;
	anim = 0;
	nro_sec_back = 0;
}

Stage::~Stage(){}

void Stage::Draw(int current_width, int current_height){
	width = current_width;
	height = current_height;

	glClear(GL_COLOR_BUFFER_BIT); 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//funcion de transparencia
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_CONSTANT_COLOR);//funcion de transparencia
	//glEnable(GL_BLEND);//utilizar transparencia
	_time = glutGet(GLUT_ELAPSED_TIME); // recupera el tiempo ,que paso desde el incio de programa

	dt = _time - timebase;// delta time
	timebase = _time;
	anim += dt;

	if (anim / 1000.0 > 0.06){
		nro_sec_back++;
		anim = 0.0;
	}

	if ( nro_sec_back == TIME_SCENE ){
		nro_sec_back = 0;
	}

	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, texture[nro_sec_back]);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex3d(-20, -12, 0);

			glTexCoord2f(1.0, 0.0);
			glVertex3d(20, -12, 0);

			glTexCoord2f(1.0, 1.0);
			glVertex3d(20, 12, 0);

			glTexCoord2f(0.0, 1.0);
			glVertex3d(-20, 12, 0);
		
		glEnd();
	glPopMatrix();

	glDisable(GL_BLEND);
}
