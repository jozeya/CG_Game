#include "OPENGL.h"
#include "CHARACTER.h"

int main(int argc, char **argv){

	OpenGL sys("Game_CG", 800, 600, 100, 100);
	sys.Run(argc, argv);

	//Character *ch;
	//ch = new Character();
	//ch -> Draw();

	return 0;
}
