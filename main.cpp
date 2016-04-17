#include "System/SYSTEM.h"


int main(int argc, char **argv)
{
	System *p_Game =  new System();

	p_Game->Init(argc,argv);

	return 0;
}