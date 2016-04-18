#include "GRAPHICS.h"

Graphics::Graphics()
{
	p_proyectil = NULL;
	p_character = NULL;

}

Graphics::~Graphics()
{

}

bool Graphics::Init()
{
	p_proyectil = new Proyectil(0,0,2);

	if (!p_proyectil)
		return false;

	p_character = new Character(5,5,5);
	if (!p_character)
		return false;

	return true;
}

void Graphics::Shutdown()
{

}

void Graphics::Render()
{
	p_proyectil -> Init();
	p_character -> Init();
}
