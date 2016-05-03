#include "GAME.h"

Game::Game(){
	p_mCharacter = new Character();
	p_mFireball = new Fireball();
	p_mStage = new Stage();
}

Game::~Game(){}

void Game::start_Game(){
	p_mStage -> Draw(current_Width, current_Height);
	p_mCharacter -> Draw();
	p_mFireball -> Draw();
}

void Game::captureInput(unsigned char key){
	p_mCharacter -> input(key);
}

void Game::captureInputUP(int key){
	
}

void Game::config_Game(int w, int h){
	current_Width = w;
	current_Height = h;
}