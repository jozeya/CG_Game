#include "CHARACTER.h"

Character::Character(){
	sprites = 0;
	texture = 0;
	sprites = TextureManager::Inst()->LoadTexture("sprites/character.png", GL_BGRA_EXT, GL_RGBA);	
	texture = TextureManager::Inst()->LoadTexture("tesxtures/background.png", GL_BGR_EXT, GL_RGB);

	_time = 0;
	timebase = 0;
	dt = 0;
	anim = 0;
	nro_sec_sprite = 0;
	x = 0.1678;
	y = 0.665;
}

Character::~Character(){}

GLvoid Character::Draw() {

	//El fondo de la escena al color initial
	glClear(GL_COLOR_BUFFER_BIT); 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//funcion de transparencia
	glEnable(GL_BLEND);//utilizar transparencia
	_time = glutGet(GLUT_ELAPSED_TIME); // recupera el tiempo ,que paso desde el incio de programa

	dt = _time - timebase;// delta time
	timebase = _time;
	anim += dt;//duracion de la animacion entre dos cambios de Sprite
	
	if (anim / 1000.0 > 0.15)// si el tiempo de animacion dura mas 0.15s cambiamos de sprite
	{
		nro_sec_sprite ++;
		anim = 0.0;
	}
	
	if (nro_sec_sprite == 6) nro_sec_sprite = 0;
	
	glBindTexture(GL_TEXTURE_2D, sprites);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f + x * nro_sec_sprite, y);//coordenadas de textura
	glVertex3d(-3, -5, 0);

	glTexCoord2f(0.0f + x * nro_sec_sprite, 1.0f);
	glVertex3d(-3, 5, 0);

	glTexCoord2f(x * ( nro_sec_sprite + 1.0), 1.0f);
	glVertex3d(3, 5, 0);

	glTexCoord2f(x * ( nro_sec_sprite + 1.0), y);
	glVertex3d(3, -5, 0);
	glEnd();

	glDisable(GL_BLEND);

	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);//coordenadas de textura
	glVertex3d(8, -2, 0);

	glTexCoord2f(0.0, 1.0f);
	glVertex3d(8, 2, 0);

	glTexCoord2f(1.0, 1.0f);
	glVertex3d(16, 2, 0);

	glTexCoord2f(1.0, 0.0);
	glVertex3d(16, -2, 0);
	glEnd();
}
