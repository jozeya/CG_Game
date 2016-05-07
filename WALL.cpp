#include "WALL.h"

Wall::Wall(float x_,float y_, float h_, float w_)
{
	rectangle = new Rect();
	rectangle -> ini_Values(x_, y_, h_, w_);
	texture = TextureManager::Inst()->LoadTexture("textures/wall.jpg", GL_BGR_EXT, GL_RGB);	
	x_posi = 2;
	y_posi = 1;
}

Wall::~Wall(){}

GLvoid Wall::Draw()
{
	//glEnable(GL_BLEND);
	glPushMatrix();
		//glTranslatef(x_posi,y_posi,0);
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

	rectangle -> x -= 0.05;
	//glDisable(GL_BLEND);

}