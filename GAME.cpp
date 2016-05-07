#include "GAME.h"

Game::Game(){
	p_mCharacter = new Character(CHARACTER_X, CHARACTER_Y, CHARACTER_H, CHARACTER_W);
	p_mFireball = new Fireball(FIREBALL_X, FIREBALL_Y, FIREBALL_H, FIREBALL_W);
	p_mStage = new Stage();
	p_mBox = new Box(BOX_X, BOX_Y, BOX_H, BOX_W);
	p_mRock = new Rock(ROCK_X,ROCK_Y,ROCK_H,ROCK_W);
	p_mCoins = new Coins(COINS_X, COINS_Y, COINS_H, COINS_W);
	p_mWall= new Wall(WALL_X, WALL_Y, WALL_H, WALL_W);
}

Game::~Game(){}

void Game::start_Game(){

	p_mStage -> Draw(current_Width, current_Height);
	p_mCharacter -> Draw();
	p_mFireball -> Draw();
	p_mBox -> Draw();
	p_mRock -> Draw();
	p_mCoins -> Draw();
	p_mWall -> Draw();
	Collition();
}

bool Game::Collition()
{
	if(p_mCharacter->rectangle -> collide(p_mFireball-> rectangle))
		{
			cout<<"colisiono con fireball"<<endl;
			p_mFireball -> rectangle ->x = 15;
		}

	if(p_mCharacter->rectangle -> collide(p_mRock-> rectangle))
		{
			cout<<"colisiono con piedra"<<endl;
			p_mRock -> rectangle ->x = 10;
		}
	if(p_mCharacter->rectangle -> collide(p_mWall-> rectangle))
		{
			cout<<"colisiono con la pared de mierda"<<endl;
			p_mWall -> rectangle ->x = 10;
		}
	if(p_mCharacter->rectangle -> collide(p_mBox-> rectangle))
		{
			cout<<"colisiono con la CAJITA DE MADERA"<<endl;
			p_mBox -> rectangle ->x = 10;
		}
	if(p_mCharacter->rectangle -> collide(p_mCoins-> rectangle))
		{
			cout<<"colisiono con la moneda"<<endl;
			p_mCoins -> rectangle ->x = 10;
		}
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
