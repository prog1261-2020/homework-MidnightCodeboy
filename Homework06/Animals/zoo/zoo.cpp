
/**
* @file zoo.cpp
*
* @author  Joseph Roy-Plommer
* @version <1.0>
* @date 2020-02-08
*
* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*
* @section DESCRIPTION
*	Creates a collections of Animals of various kinds and calls their polymorphic function, move().
*
* @section LICENSE
*  <any necessary attributions>
*
*  Copyright 2019
*  Permission to use, copy, modify, and/or distribute this software for
*  any purpose with or without fee is hereby granted, provided that the
*  above copyright notice and this permission notice appear in all copies.
*
*  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
*/

#include <iostream>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Duck.h"
#include "Platypus.h"
#include "Capybara.h"
#include <vector>

/**
* Entry point into program.
*/
int main()
{
    std::vector<Animal*> zoo;
    zoo.push_back(new Cat("Sylvester"));
    zoo.push_back(new Dog("Pluto"));
    zoo.push_back(new Duck("Daffy"));
    zoo.push_back(new Platypus("Bruce"));
    zoo.push_back(new Capybara("Jaun"));

    for (int i = 0; i < zoo.size(); i++) {
        zoo[i]->speak();
    }

    std::cout << "\nAfter polymorphic function, move() is called on all animals in zoo vector:" << std::endl << std::endl;

    for (int i = 0; i < zoo.size(); i++) {
        zoo[i]->move();
    }

    // All animals speak again so we can see that they have moved in different ways.
    for (int i = 0; i < zoo.size(); i++) {
        zoo[i]->speak();
    }
}
