#include "Cat.h"
#include <iostream>

Cat::Cat(std::string n) : Animal(n, "cat", "meaw") {}

void Cat::speak() {
	//std::cout << "My name is " << name << " I like mice\n";
	Animal::speak();
	std::cout << " and I like mice\n";
}