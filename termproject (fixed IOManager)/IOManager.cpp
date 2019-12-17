#include "IOManager.h"

IOManager::IOManager(){
}
/*
char IOManager::getInput(){
	char ch;
	ch = (char)getch();

	return ch;
}
*/
char IOManager::getInput(){
		char ch;
		ch = getchar();

		return ch;
}

void IOManager::output(const char* text){
		printf(text);
}

void IOManager::output(int number){
		printf("%d", number);
}
