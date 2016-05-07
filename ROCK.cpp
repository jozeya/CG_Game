#include "ROCK.h"

Rock::Rock(float x_, float y_, float h_, float w_)
{
	rectangle = new Rect();
	rectangle -> ini_Values(x_, y_, h_, w_);

	sprites = TextureManager::Inst()->LoadTexture("sprites/Rock1.png", GL_BGRA_EXT, GL_RGBA);	
}

Rock::~Rock(){}

GLvoid Rock::Draw()
{

	glEnable(GL_BLEND);//utilizar transparencia

	glPushMatrix();
		//glTranslatef(12,-6.1,0);
		glBindTexture(GL_TEXTURE_2D, sprites);
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

	rectangle -> x -= 0.01;
	

	glDisable(GL_BLEND);
}
