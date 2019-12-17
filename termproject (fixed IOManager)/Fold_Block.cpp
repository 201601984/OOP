#include "Fold_Block.h"
#include "Array_2d.h"

Fold_Block::Fold_Block(Array_2d* array_2d, Color c1, Color c2, Color c3) : Big_Block(array_2d){
	this->minX=this->x-1;
	this->maxX=this->x;
	this->minY=this->y-1;
	this->maxY=this->y;

	this->v.push_back(new Block(this->array_2d, this->x, this->y, c1));
	this->v.push_back(new Block(this->array_2d, this->minX, this->y, c2));
	this->v.push_back(new Block(this->array_2d, this->x, this->minY, c3));
}

void Fold_Block::rotate(){
	for(std::vector<Block*>::iterator it = this->v.begin(); it != this->v.end(); it++){
		if((*it)->getX()<this->x){
			if((*it)->getX()+1>array_2d->WIDTH-1) return;
			if((*it)->getY()-1<0) return;
			if(array_2d->getBlock((*it)->getX()+1, (*it)->getY()-1)->getColor() != Color::BLANK)
				return;
		}
		else if((*it)->getX()>this->x){
			if((*it)->getX()-1<0) return;
			if((*it)->getY()+1>array_2d->HEIGHT-1) return;
			if(array_2d->getBlock((*it)->getX()-1, (*it)->getY()+1)->getColor() != Color::BLANK)
				return;
		}
		else if((*it)->getY()<this->y){
			if((*it)->getX()+1>array_2d->WIDTH-1) return;
			if((*it)->getY()+1>array_2d->HEIGHT-1) return;
			if(array_2d->getBlock((*it)->getX()+1, (*it)->getY()+1)->getColor() != Color::BLANK)
				return;
		}
		else if((*it)->getY()>this->y){
			if((*it)->getX()-1<0) return;
			if((*it)->getY()-1<0) return;
			if(array_2d->getBlock((*it)->getX()-1, (*it)->getY()-1)->getColor() != Color::BLANK)
				return;
		}
	}
	for(std::vector<Block*>::iterator it = this->v.begin(); it != this->v.end(); it++){
		if((*it)->getX()<this->x)
			(*it)->setLocation((*it)->getX()+1, (*it)->getY()-1);
		else if((*it)->getX()>this->x)
			(*it)->setLocation((*it)->getX()-1, (*it)->getY()+1);
		else if((*it)->getY()<this->y)
			(*it)->setLocation((*it)->getX()+1, (*it)->getY()+1);
		else if((*it)->getY()>this->y)
			(*it)->setLocation((*it)->getX()-1, (*it)->getY()-1);
	}
	this->minX = this->x;
	this->maxX = this->x;
	this->minY = this->y;
	this->maxY = this->y;
	for(std::vector<Block*>::iterator it = this->v.begin(); it != this->v.end(); it++){
		if((*it)->getX()<this->minX)
			this->minX=(*it)->getX();
		else if((*it)->getX()>this->maxX)
			this->maxX=(*it)->getX();
		if((*it)->getY()<this->minY)
			this->minY=(*it)->getY();
		else if((*it)->getY()>this->maxY)
			this->maxY=(*it)->getY();
	}
}
