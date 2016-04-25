#include "CHARACTER.h"

Character::Character(){
	sprites = 0;
	texture = 0;
	sprites = TextureManager::Inst()->LoadTexture("sprites/cc.png", GL_BGRA_EXT, GL_RGBA);	
	texture = TextureManager::Inst()->LoadTexture("textures/background.png", GL_BGR_EXT, GL_RGB);

	_time = 0;
	timebase = 0;
	dt = 0;
	anim = 0;
	nro_sec_sprite = 0;
	f_jump = true;
	x_jump = 0;

	x = 0.02584;
	x_jump = 0.02369;
	y = 0;
	tmp = 0.023;
}

Character::~Character(){}

GLvoid Character::Draw() {

	//El fondo de la escena al color initial
	glClear(GL_COLOR_BUFFER_BIT); 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//funcion de transparencia
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_CONSTANT_COLOR);//funcion de transparencia
	glEnable(GL_BLEND);//utilizar transparencia
	_time = glutGet(GLUT_ELAPSED_TIME); // recupera el tiempo ,que paso desde el incio de programa

	dt = _time - timebase;// delta time
	timebase = _time;
	anim += dt;//duracion de la animacion entre dos cambios de Sprite

	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);//coordenadas de textura
	glVertex3d(-10, -10, 0);

	glTexCoord2f(0.0, 1.0f);
	glVertex3d(10, -10, 0);

	glTexCoord2f(1.0, 1.0f);
	glVertex3d(10, 10, 0);

	glTexCoord2f(1.0, 0.0);
	glVertex3d(-10, 10, 0);
	
	glEnd();
	
	//if (anim / 1000.0 > 0.06)// si el tiempo de animacion dura mas 0.15s cambiamos de sprite
	
	if (anim / 1000.0 > .15)// si el tiempo de animacion dura mas 0.15s cambiamos de sprite
	{
		nro_sec_sprite ++;
		anim = 0.0;
	}
	
	//nro_sec_sprite  = 0;
	if (nro_sec_sprite == 7) nro_sec_sprite = 0;

	glBindTexture(GL_TEXTURE_2D, sprites);

	if  (!f_jump)
		Run();
	else
		Jump();

	glDisable(GL_BLEND);
	
}

GLvoid Character::Run(){
	glBegin(GL_QUADS);

		glTexCoord2f(0.1f + x * nro_sec_sprite , 0.96f);
		glVertex3f(-10, -10, 0);

		glTexCoord2f(0.125f + x * nro_sec_sprite, 0.96f);
		glVertex3f(10, -10, 0);

		glTexCoord2f(0.125f + x * nro_sec_sprite, .99f);
		glVertex3f(10, 10, 0);

		glTexCoord2f(0.1 + x * nro_sec_sprite, .99f);
		glVertex3f(-10, 10, 0);

	glEnd();	
}

GLvoid Character::Jump(){
	/*glBegin(GL_QUADS);

		glTexCoord2f(0.3f + x * nro_sec_sprite , 0.96f);
		glVertex3f(-5, -5, 0);

		glTexCoord2f(0.125f + x * nro_sec_sprite, 0.96f);
		glVertex3f(5, -5, 0);

		glTexCoord2f(0.125f + x * nro_sec_sprite, .90f);
		glVertex3f(5, 5, 0);

		glTexCoord2f(0.3 + x * nro_sec_sprite, .90f);
		glVertex3f(-5, 5, 0);

	glEnd();*/	
//0.02524
//0.023
	glBegin(GL_QUADS);

		glTexCoord2f(0.2875 + tmp * nro_sec_sprite+ 0.003, 0.911f);
		//glTexCoord2f(0.1 + tmp , 0.911f);
		glVertex3f(-10, -10, 0);

		glTexCoord2f(0.3105 +tmp * nro_sec_sprite + 0.007, 0.911f);
		//glTexCoord2f(0.125 + tmp , 0.911f);
		glVertex3f(10, -10, 0);

		glTexCoord2f(0.3105 +tmp * nro_sec_sprite + 0.007, .949f);
		//glTexCoord2f(0.125 + tmp , .949f);
		glVertex3f(10, 10, 0);

		glTexCoord2f(0.2875 + tmp * nro_sec_sprite+ 0.003, .949f);
		//glTexCoord2f(0.1 + tmp , .949f);
		glVertex3f(-10, 10, 0);

/*	glTexCoord2f(0.0f + x*i, y);//coordenadas de textura
	glVertex3d(-3, -5, 0);

	glTexCoord2f(0.0f + x*i, 1.0f);
	glVertex3d(-3, 5, 0);

	glTexCoord2f(x*(i + 1.0), 1.0f);
	glVertex3d(3, 5, 0);

	glTexCoord2f(x*(i + 1.0), y);
	glVertex3d(3, -5, 0);*/

	glEnd();
}