#include "CHARACTER.h"

Character::Character(float x_, float y_, float h_, float w_){
	
	rectangle = new Rect();
	rectangle -> ini_Values(x_, y_, h_, w_);
	sprites = 0;
	texture = 0;
	sprites = TextureManager::Inst()->LoadTexture("sprites/cc.png", GL_BGRA_EXT, GL_RGBA);	
	//texture = TextureManager::Inst()->LoadTexture("textures/background.png", GL_BGR_EXT, GL_RGB);

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
	
	is_running = true;
	nro_scene = TIME_RUN;

	current_state = STATE_RUN;

	p_DOWN_Scene = new Scene(TIME_DOWN);
	p_DOWN_Scene -> insert(0.1410f, 0.8375f, 0.1659f, 0.8630f);
	p_DOWN_Scene -> insert(0.1693f, 0.8375f, 0.1893f, 0.8630f);
	p_DOWN_Scene -> insert(0.1920f, 0.8375f, 0.2090f, 0.8630f);
	p_DOWN_Scene -> insert(0.2128f, 0.8375f, 0.2319f, 0.8630f);
	p_DOWN_Scene -> insert(0.2346f, 0.8375f, 0.2517f, 0.8630f);
	p_DOWN_Scene -> insert(0.1693f, 0.8375f, 0.1893f, 0.8630f);
	p_DOWN_Scene -> insert(0.1920f, 0.8375f, 0.2090f, 0.8630f);


	p_JUMP_Scene = new Scene(TIME_JUMP);
	p_JUMP_Scene -> insert(0.2655f, 0.9143f, 0.2845f, 0.9495f);
	p_JUMP_Scene -> insert(0.2880f, 0.9143f, 0.3103f, 0.9495f);
	p_JUMP_Scene -> insert(0.3135f, 0.9143f, 0.3352f, 0.9495f);
	p_JUMP_Scene -> insert(0.3385f, 0.9143f, 0.3599f, 0.9495f);
	p_JUMP_Scene -> insert(0.3632f, 0.9143f, 0.3852f, 0.9495f);
	p_JUMP_Scene -> insert(0.2655f, 0.9143f, 0.2845f, 0.9495f);
	p_JUMP_Scene -> insert(0.3885f, 0.9143f, 0.4075f, 0.9495f);

	p_HIT_Scene = new Scene(TIME_HIT);
	p_HIT_Scene -> insert(0.0928f, 0.5895f, 0.1325f, 0.6175f);
	p_HIT_Scene -> insert(0.13515f, 0.5895f, 0.1761f, 0.6220f);
	p_HIT_Scene -> insert(0.1788f, 0.5895f, 0.2248f, 0.6193f);

	p_FALL_Scene = new Scene(TIME_FALL);
	p_FALL_Scene -> insert(0.1252f, 0.8631f, 0.1520f, 0.8931f);
	p_FALL_Scene -> insert(0.1524f, 0.8725f, 0.1802f, 0.8981f);
	p_FALL_Scene -> insert(0.3057f, 0.8725f, 0.3442f, 0.8981f);
	p_FALL_Scene -> insert(0.3440f, 0.8725f, 0.3710f, 0.8981f);
	p_FALL_Scene -> insert(0.3728f, 0.8725f, 0.3968f, 0.8981f);
	p_FALL_Scene -> insert(0.3966f, 0.8725f, 0.4190f, 0.8981f);
	p_FALL_Scene -> insert(0.4182f, 0.8725f, 0.4448f, 0.8981f);	



}

Character::~Character(){}

GLvoid Character::Draw() {

	//El fondo de la escena al color initial
	//glClear(GL_COLOR_BUFFER_BIT); 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//funcion de transparencia
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_CONSTANT_COLOR);//funcion de transparencia
	glEnable(GL_BLEND);//utilizar transparencia
	_time = glutGet(GLUT_ELAPSED_TIME); // recupera el tiempo ,que paso desde el incio de programa

	dt = _time - timebase;// delta time
	timebase = _time;
	anim += dt;//duracion de la animacion entre dos cambios de Sprite

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
	//glTranslatef(rectangle->x,rectangle->y,0);
	glBegin(GL_QUADS);

		glTexCoord2f(0.1f + x * nro_sec_sprite , 0.96f);
		//glVertex3f(-5, -5, 0);
		glVertex3f(rectangle->x,rectangle->y,0);

		glTexCoord2f(0.125f + x * nro_sec_sprite, 0.96f);
		//glVertex3f(5, -5, 0);
		glVertex3f(rectangle-> x + rectangle-> w,rectangle-> y, 0);

		glTexCoord2f(0.125f + x * nro_sec_sprite, .99f);
		//glVertex3f(5, 5, 0);
		glVertex3f(rectangle-> x + rectangle-> w, rectangle-> y + rectangle-> h, 0);

		glTexCoord2f(0.1 + x * nro_sec_sprite, .99f);
		//glVertex3f(-5, 5, 0);
		glVertex3f(rectangle-> x, rectangle-> y + rectangle-> h, 0);


	glEnd();
	glPopMatrix();
}

GLvoid Character::Fall(){

	if (anim / 1000.0 > 0.05){
		nro_sec_sprite++;
		anim = 0.0;
	}

	if ( nro_sec_sprite == TIME_FALL ){
		nro_sec_sprite = 0;
		current_state = STATE_RUN;
		is_state_active = false;
	}


	ini_scene = p_FALL_Scene -> get_iniPoint(nro_sec_sprite);
	end_scene = p_FALL_Scene -> get_endPoint(nro_sec_sprite);
	
	glPushMatrix();
	glTranslatef(-10,-4,0);
	glBegin(GL_QUADS);


		glTexCoord2f(ini_scene.first , ini_scene.second);
		glVertex3f(-5, -5, 0);

		glTexCoord2f(end_scene.first, ini_scene.second);
		glVertex3f(5, -5, 0);

		glTexCoord2f(end_scene.first, end_scene.second);
		glVertex3f(5, 5, 0);

		glTexCoord2f(ini_scene.first, end_scene.second);
		glVertex3f(-5, 5, 0);
	glEnd();

	glPopMatrix();

//ffmpeg
}

GLvoid Character::Jump(){

	if (anim / 1000.0 > 0.07){
		nro_sec_sprite++;
		anim = 0.0;
	}

	if ( nro_sec_sprite == TIME_JUMP ){
		nro_sec_sprite = 0;
		current_state = STATE_RUN;
		is_state_active = false;
	}

	

	ini_scene = p_JUMP_Scene -> get_iniPoint(nro_sec_sprite);
	end_scene = p_JUMP_Scene -> get_endPoint(nro_sec_sprite);
	
	glPushMatrix();
	//glTranslatef(-10,-4,0);
	glBegin(GL_QUADS);


		glTexCoord2f(ini_scene.first , ini_scene.second);
		glVertex3f(rectangle->x,rectangle->y,0);

		glTexCoord2f(end_scene.first, ini_scene.second);
		glVertex3f(rectangle-> x + rectangle-> w,rectangle-> y, 0);

		glTexCoord2f(end_scene.first, end_scene.second);
		glVertex3f(rectangle-> x + rectangle-> w, rectangle-> y + rectangle-> h, 0);

		glTexCoord2f(ini_scene.first, end_scene.second);
		glVertex3f(rectangle-> x, rectangle-> y + rectangle-> h, 0);
	glEnd();

	glPopMatrix();
}

GLvoid Character::Hit(){

	if (anim / 1000.0 > 0.08){
		nro_sec_sprite++;
		anim = 0.0;
	}

	if ( nro_sec_sprite == TIME_HIT ){
		nro_sec_sprite = 0;
		current_state = STATE_RUN;
		is_state_active = false;
	}

	ini_scene = p_HIT_Scene -> get_iniPoint(nro_sec_sprite);
	end_scene = p_HIT_Scene -> get_endPoint(nro_sec_sprite);

	glPushMatrix();
		//glTranslatef(-10,-3,0);
		glBegin(GL_QUADS);



		glTexCoord2f(ini_scene.first , ini_scene.second);
		glVertex3f(rectangle->x,rectangle->y,0);

		glTexCoord2f(end_scene.first, ini_scene.second);
		glVertex3f(rectangle-> x + rectangle-> w,rectangle-> y, 0);

		glTexCoord2f(end_scene.first, end_scene.second);
		glVertex3f(rectangle-> x + rectangle-> w, rectangle-> y + rectangle-> h, 0);

		glTexCoord2f(ini_scene.first, end_scene.second);
		glVertex3f(rectangle-> x, rectangle-> y + rectangle-> h, 0);

		glEnd();
	glPopMatrix();
}


GLvoid Character::Down(){

	if (anim / 1000.0 > 0.06){
		nro_sec_sprite++;
		anim = 0.0;
	}

	if ( nro_sec_sprite == TIME_DOWN ){
		nro_sec_sprite = 0;
		current_state = STATE_RUN;
		is_state_active = false;
	}
	glPushMatrix();
		//glTranslatef(-10,-4.9,0);
		glBegin(GL_QUADS);

			ini_scene = p_DOWN_Scene -> get_iniPoint(nro_sec_sprite);
			end_scene = p_DOWN_Scene -> get_endPoint(nro_sec_sprite);

		glTexCoord2f(ini_scene.first , ini_scene.second);
		glVertex3f(rectangle->x,rectangle->y,0);

		glTexCoord2f(end_scene.first, ini_scene.second);
		glVertex3f(rectangle-> x + rectangle-> w,rectangle-> y, 0);

		glTexCoord2f(end_scene.first, end_scene.second);
		glVertex3f(rectangle-> x + rectangle-> w, rectangle-> y + rectangle-> h, 0);

		glTexCoord2f(ini_scene.first, end_scene.second);
		glVertex3f(rectangle-> x, rectangle-> y + rectangle-> h, 0);
		glEnd();	
	glPopMatrix();

	
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
				current_state = STATE_FALL;
				is_state_active = true;
				break;
		}
	}
}