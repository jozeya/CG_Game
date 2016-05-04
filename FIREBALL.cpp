#include "FIREBALL.h"

Fireball::Fireball(){
	sprites = TextureManager::Inst()->LoadTexture("sprites/FireBall.png", GL_BGRA_EXT, GL_RGBA);	

	_time = 0;
	timebase = 0;
	dt = 0;
	anim = 0;
	nro_sec_sprite = 0;

	p_FIREBALL_Scene = new Scene(TIME_SCENE);
	p_FIREBALL_Scene -> insert(0.0f, 0.48f, 0.32f, 0.67f);
	p_FIREBALL_Scene -> insert(0.32f, 0.48f, 0.66f, 0.67f);
	p_FIREBALL_Scene -> insert(0.67f, 0.48f, 1.0f, 0.67f);

	x_posi = rand() % 10;
	y_posi = rand() % 10;
	speed1 = 0.01;
}

Fireball::~Fireball(){}

GLvoid Fireball::Randon()
{

}

GLvoid Fireball::Draw(){

	//glClear(GL_COLOR_BUFFER_BIT); 
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//funcion de transparencia
	
	glEnable(GL_BLEND);//utilizar transparencia
	_time = glutGet(GLUT_ELAPSED_TIME); // recupera el tiempo ,que paso desde el incio de programa

	dt = _time - timebase;// delta time
	timebase = _time;
	anim += dt;//duracion de la animacion entre dos cambios de Sprite

	if (anim / 1000.0 > 0.15){
		nro_sec_sprite++;
		anim = 0.0;
	}

	if ( nro_sec_sprite == TIME_SCENE ){
		nro_sec_sprite = 0;
	}

	glPushMatrix();
		glTranslatef(x_posi,-6.9,0);
		glBindTexture(GL_TEXTURE_2D, sprites);
		glBegin(GL_QUADS);

			ini_scene = p_FIREBALL_Scene -> get_iniPoint(nro_sec_sprite);
			end_scene = p_FIREBALL_Scene -> get_endPoint(nro_sec_sprite);

			glTexCoord2f(ini_scene.first , ini_scene.second);
			glVertex3f(-3, -3, 0);

			glTexCoord2f(end_scene.first, ini_scene.second);
			glVertex3f(3, -3, 0);

			glTexCoord2f(end_scene.first, end_scene.second);
			glVertex3f(3, 3, 0);

			glTexCoord2f(ini_scene.first, end_scene.second);
			glVertex3f(-3, 3, 0);

			/*glTexCoord2f(0.67 , 0.48);
			glVertex3f(-6, -6, 0);

			glTexCoord2f(1, 0.48);
			glVertex3f(6, -6, 0);

			glTexCoord2f(1, 0.67);
			glVertex3f(6, 6, 0);

			glTexCoord2f(0.67, 0.67);
			glVertex3f(-6, 6, 0);*/
			x_posi -= speed1;	
		glEnd();	
	glPopMatrix();
	

	glDisable(GL_BLEND);
}