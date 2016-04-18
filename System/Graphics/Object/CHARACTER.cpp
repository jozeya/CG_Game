#include "CHARACTER.h"

Character :: Character (int posx, int posy, int la)
{
	pos_x = posx;
	pos_y = posy;
	lado = la;
	pi = 3.1416;
	ang = 0;
	nuevo_x = 0;
	nuevo_y = 0;
}

bool Character::Init()
{
	glPushMatrix();
		glColor3f(1.0,1.0,1.0);
		glTranslatef(pos_x, pos_y, 0);
			glBegin(GL_LINE_LOOP);

				glVertex2d(pos_x - (lado/2), (lado/2) + pos_y);
				glVertex2d((lado/2) + pos_x, pos_y + (lado/2));
				glVertex2d((lado/2) + pos_x, pos_y - (lado/2));
				glVertex2d(pos_x - (lado/2), pos_y - (lado/2));

			glEnd();
	glPopMatrix();


}
void Character::jump(){

	ang = ang + 0.5;
	pos_x = 5 * cos(ang);
	pos_y = 5 * sin(ang);
	glPushMatrix();
		glTranslatef(pos_x, pos_y, 0); 
	glPopMatrix();
}

Character::~Character()
{

}