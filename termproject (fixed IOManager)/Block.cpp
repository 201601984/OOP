#include "Block.h"
#include "Array_2d.h"

Block::Block(Array_2d* array_2d){
	this->array_2d = array_2d;
	this->group = new Color_Block(array_2d, this);

}
Block::Block(Array_2d* array_2d, Color color): Block(array_2d){
	this->color = color;
}
Block::Block(Array_2d* array_2d, int x, int y, Color color): Block(array_2d, color){
	this->x = x;
	this->y = y;
}

Color Block::getColor(){
	return this->color;
}

int Block::getX(){
	return this->x;
}
int Block::getY(){
	return this->y;
}

void Block::setLocation(int x, int y){
	this->x = x;
	this->y = y;
}

Color_Block* Block::getGroup(){
	return this->group;
}
void Block::setGroup(Color_Block* group){
	for(std::set<Block*>::iterator it = group->getSet().begin(); it != group->getSet().end(); it++){
		(*it)->group = group;
	}
	this->group = group;
}
void Block::down_All(){
	if(this->getGroup()->getSetSize()>1){
		this->getGroup()->er(this);//연결된 블럭 끊기
	}
	this->group = new Color_Block(array_2d, this);
	while(array_2d->getBlock(this->x, this->y+1)->getColor() == Color::BLANK){
		array_2d->clean(this);
		this->y++;
		array_2d->spawn(this);
		if(this->y==Array_2d::HEIGHT-1)
			break;
	}
	findMerge();
}

bool Block::canMerge(Block* b){
	return (this->getColor() == b->getColor())&&(this->getColor()!=Color::GREY);
}

void Block::merge(Block* b){
		b->getGroup()->insert(this->getGroup()->getSet());
		this->setGroup(b->getGroup());
		b->setGroup(b->getGroup());

		this->getGroup()->insert(b->getGroup()->getSet());
		b->setGroup(this->getGroup());
		this->setGroup(this->getGroup());
}

void Block::findMerge(){
	if(this->x!=0){
		Block* b = array_2d->getBlock(this->x-1, this->y);
		if(canMerge(b))
			merge(b);
	}
	if(this->x!=Array_2d::WIDTH-1){
		Block* b = array_2d->getBlock(this->x+1, this->y);
		if(canMerge(b))
			merge(b);
	}
	if(this->y!=0){
		Block* b = array_2d->getBlock(this->x, this->y-1);
		if(canMerge(b))
			merge(b);
	}
	if(this->y!=Array_2d::HEIGHT-1){
		Block* b = array_2d->getBlock(this->x, this->y+1);
		if(canMerge(b))
			merge(b);
	}
}

