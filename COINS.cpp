#include "COINS.h"

Coins::Coins(float x_, float y_, float h_, float w_)
{
	rectangle = new Rect();
	rectangle -> ini_Values(x_, y_, h_, w_);
	texture = TextureManager::Inst()->LoadTexture("textures/coins2.png", GL_BGRA_EXT, GL_RGBA);	
	
}

Coins::~Coins(){}

GLvoid Coins::Draw()
{
	//glClear(GL_COLOR_BUFFER_BIT); 
	//aglBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//funcion de transparencia
	glEnable(GL_BLEND);
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);

			glTexCoord2f(0,0);
			glVertex3f(rectangle-> x, rectangle-> y, 0);

			glTexCoord2f(1,0);
			glVertex3f(rectangle-> x + rectangle-> w,rectangle-> y, 0);
			
			glTexCoord2f(1,1);
			glVertex3f(rectangle-> x + rectangle-> w, rectangle-> y + rectangle-> h, 0);

			glTexCoord2f(0,1);
			glVertex3f(rectangle-> x, rectangle-> y + rectangle-> h, 0);

		glEnd();	
	glPopMatrix();
	rectangle -> x -= 0.005;

	glDisable(GL_BLEND);


}