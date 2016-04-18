#include "SYSTEM.h"

System::System()
{
	m_pOpenGL = NULL;
	m_pGraphics = NULL;
	m_pInput = NULL;
	appName = "";

	cout << "Creado el Sistema" << endl;
}


bool System::Init(int argc, char **argv)
{

	//if(!InitWindows())
	//	return false;

	m_pOpenGL = new OpenGL();
	m_pOpenGL->Init();

	m_pGraphics = new Graphics();
	if(!m_pGraphics)
		return false;

	if(!m_pGraphics->Init())
		return false;
	
	if(!m_pOpenGL){
		return false;
	}

	appName = "G_G gaming";
	if(!m_pOpenGL->Initialize(argc, argv, SCREEN_WIDTH, SCREEN_HEIGHT, appName)){
		return false;
	}
	
	/*
	//INPUT
	m_pInput = new Input();
	if(!m_pInput)
		return false;

	if(!m_pInput->Init())
		return false;
	*/
	//GRAPHICS

	//inicializa los valores de Graphics

	return true;
}

void System::Shutdown()
{
	if(m_pGraphics)
	{
		m_pGraphics->Shutdown();
		delete m_pGraphics;
		m_pGraphics = NULL;
	}
	if(m_pInput)
	{
		delete m_pInput;
		m_pInput = NULL; 
	}
	if(m_pOpenGL)
	{
		m_pOpenGL->Shutdown();
		delete m_pOpenGL;
		m_pOpenGL = NULL;
	}
}

void System::MainLoop()
{
	
}

bool System::Frame()
{
	/*if(m_pInput -> IsKeyDown(1))
		return false;

	if(!m_pGraphics -> Frame())
		return false;
	*/
	return true;
}

bool System::InitWindows()
{
	
	return true;
}

void System::ShutdownWindows()
{
	
}
