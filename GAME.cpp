#include "GAME.h"

Game::Game(){
	p_mCharacter = new Character();
}

Game::~Game(){}

void Game::start_Game(){
	p_mCharacter -> Draw();
}

void Game::captureInput(unsigned char key){
	p_mCharacter -> input(key);
}

void Game::captureInputUP(int key){
	p_mCharacter -> set_keydown_unpressed();
}