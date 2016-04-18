#include "PROYECTIL.h"

Proyectil::Proyectil(int posx, int posy, int ra){
	pos_x = posx;
	pos_y = posy;
	radio = ra;


	cout << "Creado el proyectil" << endl;
}

Proyectil::~Proyectil(){

}

bool Proyectil::Init(){
	glPushMatrix();
		glColor3f(1.0,1.0,0.0);
		glTranslatef(pos_x, pos_y, 0);
		glutSolidSphere(radio,36,36);
	glPopMatrix();

	//cout << "Inicializado el Proyectil" << endl;
}

void Proyectil::Print(){
	cout << " Existe el Proyectil" << endl;
}