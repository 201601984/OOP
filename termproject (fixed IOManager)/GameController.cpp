#include "GameController.h"
#include "IOManager.h"
#include "Random.h"
#include "Array_2d.h"
#include "Big_Block.h"
#include "Fold_Block.h"
#include "Tree_Block.h"
#include "Cross_Block.h"
#include "Color.h"

Array_2d* array_2d;
Big_Block* big_Block;

bool canMake = true;
bool gameOver = false;

int GameController::score = 0;

GameController::GameController(){
	array_2d = new Array_2d();
	make();
	GameController::score = 0;
}
void GameController::make(){
	int r = Random::getRandomBlock();
	int c = Random::getRandomColor();
	int c1 = c % 4;
	int c2 = (c >> 2) % 4;
	int c3 = (c >> 4) % 4;
	int c4 = (c >> 6) % 4;
	int c5 = (c >> 8) % 4;
	c1++;c2++;c3++;c4++;c5++;
	if(r==0)
		big_Block = new Fold_Block(array_2d, (Color)c1, (Color)c2, (Color)c3);
	if(r==1)
		big_Block = new Tree_Block(array_2d, (Color)c1, (Color)c2, (Color)c3);
	if(r==2)
		big_Block = new Cross_Block(array_2d, (Color)c1, (Color)c2, (Color)c3, (Color)c4, (Color)c5);
	gameOver = !array_2d->canMake(big_Block);
	canMake=false;
}
bool GameController::inputMove(){
	char ch = IOManager::getInput();
	if(ch=='\n'||!(ch=='a'||ch=='d'||ch=='s'||ch=='e'||ch=='x'))
		return false;
	if(big_Block->move(ch))
		canMake=true;

	return true;
}
void GameController::showScore(){
		IOManager::output("score : ");
		IOManager::output(GameController::score);
		IOManager::output("\n");
}
void GameController::run(){
	while(true){
		if(!inputMove())
			continue;
		if(canMake){
			make();
		}
		if(gameOver)
			break;
		this->showScore();
		array_2d->show();
	}
	this->showScore();
	IOManager::output("GAMEOVER\n");
	this->showScore();
	IOManager::output("GAMEOVER\n");
	this->showScore();
	IOManager::output("GAMEOVER\n");
	this->showScore();
	IOManager::output("GAMEOVER\n");
}
