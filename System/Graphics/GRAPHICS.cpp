#include "GRAPHICS.h"

Graphics::Graphics()
{

}

Graphics::~Graphics()
{

}

bool Graphics::Init()
{
	return true;
}

void Graphics::Shutdown()
{

}

bool Graphics::Frame()
{
	if(!Render())
		return false;

	return true;
}

bool Graphics::Render()
{
	return true;
}
