#include <iostream>

int code(){
		int a;
		a=1;
		return a;
}
const char rodata = 'A';
int data=10;
int bss;
int* heap = new int[2];

int main(){
		code();
		int stack = 10;
		std::cout << "code\t" << (void*) &code << std::endl;
		std::cout << "Rodata\t" << (void*) &rodata << std::endl;
		std::cout << "data\t" << &data << std::endl;
		std::cout << "BSS\t" << &bss << std::endl;	
		std::cout << "HEAP\t" << heap << std::endl;
		std::cout << "Stack\t" << &stack << std::endl;
}
