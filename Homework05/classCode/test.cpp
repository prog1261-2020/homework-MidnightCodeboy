/*
Alena Selezneva
*/
#include "gtest/gtest.h"
#include "Animal.h"
#include "Cat.h"
#include <iostream>


TEST(TestCaseName, TestName) {
	//Animal cat("Sabrina", "cat", "meow");
	Animal dog("Fido", "dog", "Gav");
	Animal duck("Donald J Duck", "duck", "Quack");

	Cat cat("Sabrina");

	std::cout << "\n\n";
	cat.speak();
	dog.speak();
	duck.speak();

	std::cout << "\n\n";

  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}