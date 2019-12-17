#include "Big_Block.h"
#include "Array_2d.h"
#include "GameController.h"

Big_Block::Big_Block(Array_2d* array_2d): Block(array_2d){
	this->x = 3;
	this->y = 1;
}
bool Big_Block::find(Block* b){
	for(std::vector<Block*>::iterator it = this->v.begin(); it != this->v.end(); it++){
		if((*it)==b)
			return true;
	}
	return false;
}
bool Big_Block::canRight(){
	if(this->maxX<Array_2d::WIDTH-1){
		for(std::vector<Block*>::iterator it = this->v.begin(); it != this->v.end(); it++){
			Block* aaa = array_2d->getBlock((*it)->getX()+1,(*it)->getY());
			if(aaa->getColor() != Color::BLANK){
				if(!find(aaa))
					return false;
			}
		}
		return true;
	}
	return false;
}
bool Big_Block::canLeft(){
	if(this->minX>0){
		for(std::vector<Block*>::iterator it = this->v.begin(); it != this->v.end(); it++){
			Block* aaa = array_2d->getBlock((*it)->getX()-1,(*it)->getY());
			if(aaa->getColor() != Color::BLANK){
				if(!find(aaa))
					return false;
			}
		}
		return true;
	}
	return false;
}
bool Big_Block::canDown(){
	if(this->maxY<Array_2d::HEIGHT-1){
		for(std::vector<Block*>::iterator it = this->v.begin(); it != this->v.end(); it++){
			Block* aaa = array_2d->getBlock((*it)->getX(),(*it)->getY()+1);
			if(aaa->getColor() != Color::BLANK){
				if(!find(aaa))
					return false;
			}
		}
		return true;
	}
	return false;
}

void Big_Block::right(){
	if(canRight()){
		for(std::vector<Block*>::iterator it = this->v.begin(); it != this->v.end(); it++){
			(*it)->setLocation((*it)->getX()+1,(*it)->getY());
		}
		this->setLocation(this->x+1, this->y);
		this->minX++;
		this->maxX++;
	}
}

void Big_Block::left(){
	if(canLeft()){
		for(std::vector<Block*>::iterator it = this->v.begin(); it != this->v.end(); it++){
			(*it)->setLocation((*it)->getX()-1,(*it)->getY());
		}
		this->setLocation(this->x-1, this->y);
		this->minX--;
		this->maxX--;
	}
}

bool Big_Block::down(){
	if(canDown()){
		for(std::vector<Block*>::iterator it = this->v.begin(); it != this->v.end(); it++){
			(*it)->setLocation((*it)->getX(),(*it)->getY()+1);
		}
		this->setLocation(this->x, this->y+1);
		this->minY++;
		this->maxY++;
	array_2d->spawn(this);
		return false;
	}
	down_All();
	return true;
}

bool Big_Block::down_All(){
	//높이 순으로 벡터 정리
	std::vector<Block*> v2;
	for(std::vector<Block*>::iterator it = this->v.begin(); it != this->v.end(); it++){
		if((*it)->getY()==this->y+1)
			v2.push_back(*it);
	}
	for(std::vector<Block*>::iterator it = this->v.begin(); it != this->v.end(); it++){
		if((*it)->getY()==this->y)
			v2.push_back(*it);
	}
	for(std::vector<Block*>::iterator it = this->v.begin(); it != this->v.end(); it++){
		if((*it)->getY()==this->y-1)
			v2.push_back(*it);
	}
	//블럭 내리기
	array_2d->spawn(this);
	for(std::vector<Block*>::iterator it = v2.begin(); it != v2.end(); it++){
		if((*it)->getY()>=Array_2d::HEIGHT-1)
			continue;
		(*it)->down_All();
	}
	array_2d->spawn(this);
	//블럭 터짐
	for(int i = 0; i < Array_2d::HEIGHT; i++){
		for(int j = 0; j < Array_2d::WIDTH; j++){
			if(array_2d->getBlock(j, i)->getGroup()->getSetSize()>=4){
				Color_Block::explosionS.insert(array_2d->getBlock(j,i)->getGroup());
				array_2d->getBlock(j,i)->getGroup()->explosion();
				GameController::score++;//동시 터져도 1점
			}
		}
	}
	return true;
}

bool Big_Block::move(char key){
	bool a = false;
	array_2d->clean(this);
	if(key=='a'){
		left();
	array_2d->spawn(this);
	}
	else if(key=='d'){
		right();
	array_2d->spawn(this);
	}
	else if(key=='s'){
		a = down();
	}
	else if(key=='x'){
		a = down_All();
	}
	else if(key=='e'){
		rotate();
	array_2d->spawn(this);
	}

	return a;
}
