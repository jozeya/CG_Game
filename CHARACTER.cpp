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

	f_jump = false;
	f_hit = false;
	f_down = false;

	x = 0.02584;
	//x_jump = 0.02369;
	x_jump = 0.02422; 
	x_hit = 0.04465;
	y = 0;
	tmp = 0.023;
	is_running = true;

	nro_scene = RUN;
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
	
	if (anim / 1000.0 > .05)// si el tiempo de animacion dura mas 0.15s cambiamos de sprite
	{
		nro_sec_sprite ++;
		anim = 0.0;
	}
	
	//nro_sec_sprite  = 0;
	if (nro_sec_sprite == nro_scene){
		nro_sec_sprite = 0;

		nro_scene = RUN;
		f_jump = false;
		f_hit = false;
		is_running = true;
	}

	glBindTexture(GL_TEXTURE_2D, sprites);

	if  (is_running)
		Run();
	else{
		if(f_jump){
			Jump();
		}else{
			if (f_hit)
				Hit();
			else
				Down();
		}
	}

	glDisable(GL_BLEND);
	
}

GLvoid Character::Run(){

	glPushMatrix();
	glTranslatef(0,-2,0);
	glBegin(GL_QUADS);

		glTexCoord2f(0.1f + x * nro_sec_sprite , 0.96f);
		glVertex3f(-8, -8, 0);

		glTexCoord2f(0.125f + x * nro_sec_sprite, 0.96f);
		glVertex3f(8, -8, 0);

		glTexCoord2f(0.125f + x * nro_sec_sprite, .99f);
		glVertex3f(8, 8, 0);

		glTexCoord2f(0.1 + x * nro_sec_sprite, .99f);
		glVertex3f(-8, 8, 0);

	glEnd();
	glPopMatrix();
}

GLvoid Character::Jump(){
	
	nro_scene = JUMP;

	// 8 escenas = 0.45		dif con 7 = 0.02300
	// 7 escenas = 0.427	dif con 6 = 0.01900
	// 6 escenas = 0.408	dif con 5 = 0.02250
	// 5 escenas = 0.3855	dif con 4 = 0.02500
	// 4 escenas = 0.3605	dif con 3 = 0.02500
	// 3 escenas = 0.3355	dif con 2 = 0.02520
	// 2 escenas = 0.3103   dif con 1 = 0.02565
	// 1 escena  = 0.28465

	
	glPushMatrix();
	glTranslatef(0,-2,0);
	glBegin(GL_QUADS);

		glTexCoord2f(0.264 + x_jump * nro_sec_sprite, 0.9143);
		glVertex3f(-8, -8, 0);

		glTexCoord2f(0.28465 + x_jump * nro_sec_sprite, 0.9143);
		glVertex3f(8, -8, 0);

		glTexCoord2f(0.28465 + x_jump * nro_sec_sprite, 0.949);
		glVertex3f(8, 8, 0);

		glTexCoord2f(0.264 + x_jump * nro_sec_sprite, 0.949);
		glVertex3f(-8, 8, 0);

	glEnd();
	glPopMatrix();

}

GLvoid Character::Hit(){
	nro_scene = HIT;

	glBegin(GL_QUADS);

		glTexCoord2f(0.092f  + x_hit * nro_sec_sprite, 0.5895f);
		glVertex3f(-10, -10, 0);

		glTexCoord2f(0.133f + x_hit * nro_sec_sprite, 0.5895f);
		glVertex3f(10, -10, 0);

		glTexCoord2f(0.133f + x_hit * nro_sec_sprite, 0.6235f);
		glVertex3f(10, 10, 0);

		glTexCoord2f(0.092f + x_hit * nro_sec_sprite, 0.6235f);
		glVertex3f(-10, 10, 0);

	glEnd();
}

GLvoid Character::Down(){
	nro_scene = DOWN;

	glBegin(GL_QUADS);

		glTexCoord2f(0.33, 0.5);
		glVertex3f(-10, -10, 0);

		glTexCoord2f(0.5, 0.5);
		glVertex3f(10, -10, 0);

		glTexCoord2f(0.5, 1);
		glVertex3f(10, 10, 0);

		glTexCoord2f(0.33, 1);
		glVertex3f(-10, 10, 0);

	glEnd();	
}

GLvoid Character::input(unsigned char key){
	switch (key){
		case 32:
			if (!f_jump){
				f_jump = true;
				nro_sec_sprite = 0;
				f_hit = false;
				is_running = false;
			}
			break;
		case 113:
			if (!f_jump){
				f_jump = true;
				nro_sec_sprite = 0;
				f_jump = false;
				is_running = false;
			}
			break;
	}
}