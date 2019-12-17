#include "Array_2d.h"
#include "IOManager.h"
#include "Color.h"

Array_2d::Array_2d(){
	init();
}

Block* Array_2d::getBlock(int x, int y){
	return block_Array[x][y];
}
void Array_2d::clean(Block* block){
	block_Array[block->getX()][block->getY()] = new Block(this, block->getX(), block->getY(), Color::BLANK);
}
void Array_2d::clean(Big_Block* big_Block){
	for(std::vector<Block*>::iterator it = big_Block->v.begin(); it != big_Block->v.end(); it++){
		block_Array[(*it)->getX()][(*it)->getY()] = new Block(this, (*it)->getX(), (*it)->getY(), Color::BLANK);
	}
}
void Array_2d::spawn(Block* block){
	block_Array[block->getX()][block->getY()] = block;
}
void Array_2d::spawn(Big_Block* big_Block){
	for(std::vector<Block*>::iterator it = big_Block->v.begin(); it != big_Block->v.end(); it++){
		block_Array[(*it)->getX()][(*it)->getY()] = *it;
	}
}

void Array_2d::init(){
	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j < WIDTH; j++){
			block_Array[j][i] = new Block(this);
			block_Array[j][i]->setLocation(j, i);
		}
	}
}

void Array_2d::show(){
	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j < WIDTH; j++){
			IOManager::output("   ");
			int a = static_cast<int>(block_Array[j][i]->getColor());

			if(a == 0)
				IOManager::output("\"");
			else if(a == 1)
				IOManager::output("X");
			else if(a == 2)
				IOManager::output("#");
			else if(a == 3)
				IOManager::output("@");
			else if(a == 4)
				IOManager::output("/");
				
			//IOManager::output(static_cast<int>(block_Array[j][i]->getColor()));
			IOManager::output("   ");
		}
			IOManager::output("\n");
			IOManager::output("\n");
	}
}
bool Array_2d::canMake(Big_Block* big_Block){
	for(std::vector<Block*>::iterator it = big_Block->v.begin(); it != big_Block->v.end(); it++){
		if(block_Array[(*it)->getX()][(*it)->getY()]->getColor() != Color::BLANK){
			return false;
		}
	}
	this->spawn(big_Block);
	return true;
}
