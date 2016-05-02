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

	is_state_active = false;

	x = 0.02584;
	x_jump = 0.02422; 
	x_hit = 0.04465;
	x_down = 0.0220;
	y = 0;
	tmp = 0.023;
	//is_running = true;
	//nro_scene = TIME_RUN;

	current_state = STATE_RUN;
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
	
	/*if (anim / 1000.0 > .06) // si el tiempo de animacion dura mas 0.15s cambiamos de sprite
	{
		nro_sec_sprite ++;
		anim = 0.0;
	}
	
	if (nro_sec_sprite == nro_scene){
		nro_sec_sprite = 0;

		nro_scene = TIME_RUN;
		f_jump = false;
		f_hit = false;
		is_running = false;
	}*/

	glBindTexture(GL_TEXTURE_2D, sprites);

	switch (current_state){
		case STATE_JUMP:
			Jump();
			break;

		case STATE_HIT:
			Hit();
			break;

		case STATE_DOWN:
			Down();
			break;

		default:
			Run();
			break;
	}

	/*if  (is_running)
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
	}*/

	glDisable(GL_BLEND);
	
}

GLvoid Character::Run(){

	if (anim / 1000.0 > 0.05){
		nro_sec_sprite++;
		anim = 0.0;
	}

	if ( nro_sec_sprite == TIME_RUN ){
		nro_sec_sprite = 0;
	}

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

	if (anim / 1000.0 > 0.15){
		nro_sec_sprite++;
		anim = 0.0;
	}

	if ( nro_sec_sprite == TIME_JUMP ){
		nro_sec_sprite = 0;
		current_state = TIME_RUN;
		is_state_active = false;
	}

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

	if (anim / 1000.0 > 0.15){
		nro_sec_sprite++;
		anim = 0.0;
	}

	if ( nro_sec_sprite == TIME_HIT ){
		nro_sec_sprite = 0;
		current_state = TIME_RUN;
		is_state_active = false;
	}

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

	if (anim / 1000.0 > 0.1){
		nro_sec_sprite++;
		anim = 0.0;
	}

	if ( nro_sec_sprite == TIME_DOWN ){
		nro_sec_sprite = 0;
		current_state = TIME_RUN;
		is_state_active = false;
	}
	
	glBegin(GL_QUADS);

		glTexCoord2f(0.3244f + x_down * nro_sec_sprite, 0.7285f);
		glVertex3f(-10, -10, 0);

		glTexCoord2f(0.3477f + x_down * nro_sec_sprite, 0.7285f);
		glVertex3f(10, -10, 0);

		glTexCoord2f(0.3477f + x_down * nro_sec_sprite, 0.7510f);
		glVertex3f(10, 10, 0);

		glTexCoord2f(0.3244f + x_down * nro_sec_sprite, 0.7510f);
		glVertex3f(-10, 10, 0);

	glEnd();	
}

GLvoid Character::input(unsigned char key){
	if (!is_state_active){
		nro_sec_sprite = 0;

		switch (key){
			case KEY_JUMP:
				current_state = STATE_JUMP;
				is_state_active = true;
				break;
			case KEY_HIT:
				current_state = STATE_HIT;
				is_state_active = true;
				break;
			case KEY_DOWN:
				current_state = STATE_DOWN;
				is_state_active = true;
				break;
		}
	}
}