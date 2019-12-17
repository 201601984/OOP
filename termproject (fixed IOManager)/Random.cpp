#include "Random.h"

Random::Random(){
}

int Random::getRandomBlock(){
	srand((unsigned int)time(0));
	int r = rand() % 3;

	return r;
}
int Random::getRandomColor(){
	srand((unsigned int)time(0));
	int r = rand() % (4*4*4*4*4);

	return r;
}
