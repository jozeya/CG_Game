#include "INPUT.h"

Input::Input()
{

}

Input::~Input()
{

}

bool Input::Init()
{
	for(unsigned int i = 0; i < 256; i++)
	{
		m_bKeys[i] = false;
	}

	return true;
}

void Input::KeyDown(unsigned int key)
{
	m_bKeys[key] = true;
}

void Input::KeyUp(unsigned int key)
{
	m_bKeys[key] = false;
}

bool Input::IsKeyDown(unsigned int key)
{
	return m_bKeys[key];
}