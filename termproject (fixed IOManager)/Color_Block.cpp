#include "Color_Block.h"
#include "Block.h"
#include "Array_2d.h"
#include "GameController.h"

std::set<Color_Block*> Color_Block::explosionS;

Color_Block::Color_Block(Array_2d* array_2d, Block* b){
	this->array_2d = array_2d;
	this->s.insert(b);
}

void Color_Block::insert(std::set<Block*> s2){
	for(std::set<Block*>::iterator it = s2.begin(); it != s2.end(); it++){
		if(this->s.find(*it)==s.end())
			this->s.insert(*it);
	}
}

std::set<Block*> Color_Block::getSet(){
	return this->s;
}

int Color_Block::getSetSize(){
	return this->s.size();
}

void Color_Block::explosion(){
	array_2d->show();
	//GameController::score++;//터질때마다 점수
	for(std::set<Block*>::iterator it = s.begin(); it != s.end(); it++){
		if((*it)->getColor() == Color::GREY)
			continue;
		Block* a = const_cast<Block*>(*it);
		array_2d->clean(a);

		if(a->getX()!=0){//주위 GREY색 제거
			Block* b = array_2d->getBlock(a->getX()-1, a->getY());
			if(b->getColor() == Color::GREY){
				array_2d->clean(b);
				insert(b->getGroup()->getSet());
			}
		}
		if(a->getX()!=Array_2d::WIDTH-1){
			Block* b = array_2d->getBlock(a->getX()+1, a->getY());
			if(b->getColor() == Color::GREY){
				array_2d->clean(b);
				insert(b->getGroup()->getSet());
			}
		}
		if(a->getY()!=0){
			Block* b = array_2d->getBlock(a->getX(), a->getY()-1);
			if(b->getColor() == Color::GREY){
				array_2d->clean(b);
				insert(b->getGroup()->getSet());
			}
		}
		if(a->getY()!=Array_2d::HEIGHT-1){
			Block* b = array_2d->getBlock(a->getX(), a->getY()+1);
			if(b->getColor() == Color::GREY){
				array_2d->clean(b);
				insert(b->getGroup()->getSet());
			}
		}
	}
	//터진후 블럭들 내리기
	for(std::set<Block*>::iterator it = s.begin(); it != s.end(); it++){
		Block* aaa;
		for(int i = Array_2d::HEIGHT-2; i >= 0; i--){
			aaa = array_2d->getBlock((*it)->getX(), i);
			if(aaa->getColor() != Color::BLANK){
				aaa->down_All();
			}
		}
	}
	Color_Block::explosionS.erase(Color_Block::explosionS.find(this));
	//다음 터질 블럭 찾기
	for(int i = 0; i < Array_2d::HEIGHT; i++){
		for(int j = 0; j < Array_2d::WIDTH; j++){
			if(array_2d->getBlock(j, i)->getGroup()->getSetSize()>=4){
				Color_Block::explosionS.insert(array_2d->getBlock(j, i)->getGroup());
				array_2d->getBlock(j, i)->getGroup()->explosion();
			}
		}
	}
}
void Color_Block::er(Block* b){//블럭 연결 끊기
	if(this->s.find(b)!=this->s.end()){
		this->s.erase(this->s.find(b));
		if(this->getSetSize()<4){
			if(Color_Block::explosionS.find(this)!=Color_Block::explosionS.end())
				Color_Block::explosionS.erase(Color_Block::explosionS.find(this));
		}
	}
}
