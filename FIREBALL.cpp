#include "FIREBALL.h"

Fireball::Fireball(float x_, float y_, float h_, float w_){
	x_posi = x_;
	y_posi = y_;
	rectangle = new Rect();
	rectangle -> ini_Values(x_, y_, h_, w_);

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


}

Fireball::~Fireball(){}

GLvoid Fireball::Randon()
{

}

GLvoid Fireball::In_scene()
{
	if(x_posi <-18)
	{
		x_posi = 18;
		
	}
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
	//In_scene();

	glPushMatrix();
		//glTranslatef(x_posi,y_posi,0);
		glBindTexture(GL_TEXTURE_2D, sprites);
		glBegin(GL_QUADS);

			ini_scene = p_FIREBALL_Scene -> get_iniPoint(nro_sec_sprite);
			end_scene = p_FIREBALL_Scene -> get_endPoint(nro_sec_sprite);

			glTexCoord2f(ini_scene.first , ini_scene.second);
			glVertex3f(rectangle->x,rectangle->y,0);

			glTexCoord2f(end_scene.first, ini_scene.second);
			glVertex3f(rectangle-> x + rectangle-> w,rectangle-> y, 0);

			glTexCoord2f(end_scene.first, end_scene.second);
			glVertex3f(rectangle-> x + rectangle-> w, rectangle-> y + rectangle-> h, 0);

			glTexCoord2f(ini_scene.first, end_scene.second);
			glVertex3f(rectangle-> x, rectangle-> y + rectangle-> h, 0);

			/*glTexCoord2f(0.67 , 0.48);
			glVertex3f(-6, -6, 0);

			glTexCoord2f(1, 0.48);
			glVertex3f(6, -6, 0);

			glTexCoord2f(1, 0.67);
			glVertex3f(6, 6, 0);

			glTexCoord2f(0.67, 0.67);
			glVertex3f(-6, 6, 0);*/
			rectangle->x -= dt/100;	
		glEnd();
	glPopMatrix();
	

	glDisable(GL_BLEND);
}
