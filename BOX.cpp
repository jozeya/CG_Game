#include "BOX.h"

Box::Box()
{
	texture = TextureManager::Inst()->LoadTexture("textures/woodenBox.jpg", GL_BGR_EXT, GL_RGB);	

	

}
Box::~Box(){}

GLvoid Box::Draw()
{
	//glClear(GL_COLOR_BUFFER_BIT); 
	//aglBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//funcion de transparencia
	
	glPushMatrix();
		glTranslatef(5,-5.1,0);
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);

			glTexCoord2f(0,0);
			glVertex3f(-3, -3, 0);

			glTexCoord2f(1,0);
			glVertex3f(3, -3, 0);
			
			glTexCoord2f(1,1);
			glVertex3f(3, 3, 0);

			glTexCoord2f(0,1);
			glVertex3f(-3, 3, 0);

		glEnd();	
	glPopMatrix();
	

}