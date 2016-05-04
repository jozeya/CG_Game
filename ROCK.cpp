#include "ROCK.h"

Rock::Rock()
{
	sprites = TextureManager::Inst()->LoadTexture("sprites/Rock1.png", GL_BGRA_EXT, GL_RGBA);	
}

Rock::~Rock(){}

GLvoid Rock::Draw()
{

	glEnable(GL_BLEND);//utilizar transparencia

	glPushMatrix();
		glTranslatef(12,-6.1,0);
		glBindTexture(GL_TEXTURE_2D, sprites);
		glBegin(GL_QUADS);

			glTexCoord2f(0,0);
			glVertex3f(-2, -2, 0);

			glTexCoord2f(1,0);
			glVertex3f(2, -2, 0);
			
			glTexCoord2f(1,1);
			glVertex3f(2, 2, 0);

			glTexCoord2f(0,1);
			glVertex3f(-2, 2, 0);

		glEnd();	
	glPopMatrix();
	

	glDisable(GL_BLEND);
}
