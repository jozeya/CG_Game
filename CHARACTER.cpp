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
	is_keydown_pressed = false;

	x = 0.02584;
	x_jump = 0.02422; 
	x_hit = 0.04465;
	x_down = 0.0220;
	y = 0;
	tmp = 0.023;
	//is_running = true;
	//nro_scene = TIME_RUN;

	current_state = STATE_DOWN;

	p_DOWN_Scene = new Scene(TIME_DOWN);
	p_DOWN_Scene -> insert(0.1410f, 0.8375f, 0.1659f, 0.8630f);
	p_DOWN_Scene -> insert(0.1693f, 0.8375f, 0.1893f, 0.8630f);
	p_DOWN_Scene -> insert(0.1920f, 0.8375f, 0.2090f, 0.8630f);
	p_DOWN_Scene -> insert(0.2128f, 0.8375f, 0.2319f, 0.8630f);
	p_DOWN_Scene -> insert(0.2346f, 0.8375f, 0.2517f, 0.8630f);

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

	if (anim / 1000.0 > 0.07){
		nro_sec_sprite++;
		anim = 0.0;
	}

	if ( nro_sec_sprite == TIME_DOWN ){
		nro_sec_sprite = 0;
		current_state = STATE_DOWN;
		is_state_active = false;
	}
	
	glBegin(GL_QUADS);

		// escena 5 : xo = 0.2346   xf = 0.2517  	->  0.0171 +
		// escena 4 : xo = 0.2118   xf = 0.2319 	->  0.0201 *
		// escena 3 : xo = 0.1920   xf = 0.2090		->  0.0170 +
		// escena 2 : xo = 0.1693   xf = 0.1893 	->  0.0200 *
		// escena 1 : xo = 0.1410   xf = 0.1659     ->  0.0249

		//diferencias

		// dif xo  4 - 5 = 0.0228	xf = 0.0198
		// dif xo  3 - 4 = 0.0198	xf = 0.0229
		// dif xo  2 - 3 = 0.0227	xf = 0.0197
		// dif xo  1 - 2 = 0.0283	xf = 0.0234

		/*glTexCoord2f(0.1410f + a  , 0.8375f);
		glVertex3f(-10, -10, 0);

		glTexCoord2f(0.1659f + a, 0.8375f);
		glVertex3f(10, -10, 0);

		glTexCoord2f(0.1659f + a, 0.8630f);
		glVertex3f(10, 10, 0);

		glTexCoord2f(0.1410f + a, 0.8630f);
		glVertex3f(-10, 10, 0);*/

		ini_scene = p_DOWN_Scene -> get_iniPoint(nro_sec_sprite);
		end_scene = p_DOWN_Scene -> get_endPoint(nro_sec_sprite);

		//cout << "inix = " << ini_scene.first << ", iniy = " << ini_scene.second << endl;
		//cout << "finx = " << end_scene.first << ", finy = " << end_scene.second << endl;

		glTexCoord2f(ini_scene.first , ini_scene.second);
		glVertex3f(-10, -10, 0);

		glTexCoord2f(end_scene.first, ini_scene.second);
		glVertex3f(10, -10, 0);

		glTexCoord2f(end_scene.first, end_scene.second);
		glVertex3f(10, 10, 0);

		glTexCoord2f(ini_scene.first, end_scene.second);
		glVertex3f(-10, 10, 0);


	glEnd();	
}

GLvoid Character::input(unsigned char key){
	if (!is_state_active){
		//nro_sec_sprite = 0;

		switch (key){
			case KEY_JUMP:
				nro_sec_sprite = 0;
				current_state = STATE_JUMP;
				is_state_active = true;
				break;
			case KEY_HIT:
				nro_sec_sprite = 0;
				current_state = STATE_HIT;
				is_state_active = true;
				break;
			case KEY_DOWN:
				nro_sec_sprite = 0;
				current_state = STATE_DOWN;
				is_state_active = true;
				is_keydown_pressed  = true;
				break;
		}
	}
}

GLvoid Character::set_keydown_unpressed(){
	cout << "se solto" << endl;
	is_keydown_pressed = false;
}