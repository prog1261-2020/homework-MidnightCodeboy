#include <string>
#include <iostream>
#pragma once
class Animal
{
public:
	Animal();
	Animal(const std::string& name, const std::string& type, const std::string& sound);

	const std::string& getName() const;
	const std::string& getType() const;
	const std::string& getSound() const;

	void speak();

protected:
	std::string name;
	std::string type;
	std::string sound;
};

