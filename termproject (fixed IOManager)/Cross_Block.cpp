#include "Cross_Block.h"
#include "Array_2d.h"

Cross_Block::Cross_Block(Array_2d* array_2d, Color c1, Color c2, Color c3, Color c4, Color c5) : Big_Block(array_2d){
	this->minX=this->x-1;
	this->maxX=this->x+1;
	this->minY=this->y-1;
	this->maxY=this->y+1;

	this->v.push_back(new Block(this->array_2d, this->x, this->maxY, c5));
	this->v.push_back(new Block(this->array_2d, this->x, this->y, c1));
	this->v.push_back(new Block(this->array_2d, this->minX, this->y, c2));
	this->v.push_back(new Block(this->array_2d, this->maxX, this->y, c4));
	this->v.push_back(new Block(this->array_2d, this->x, this->minY, c3));
}

void Cross_Block::rotate(){
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
}
