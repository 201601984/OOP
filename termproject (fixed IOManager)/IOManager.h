#ifndef IOMANAGER_H
#define IOMANAGER_H

//#include <conio.h>
#include<stdio.h>
#include<string>
class IOManager {
private:
    IOManager();
public:
    static char getInput();
    static void output(const char* text);
    static void output(int number);
};

#endif
