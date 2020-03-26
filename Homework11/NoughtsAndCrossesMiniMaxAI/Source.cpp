/**
* @file Source.cpp
*
* @author  Joseph Roy-Plommer
* @version <1.0>
* @date 2020-03-25
*
* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*
* @section DESCRIPTION
*	Interacts with user. Gets choices about player types and starts the game(s).
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
#include "Utility.h"
#include "Player.h"
#include "AIPlayer.h"
#include "HumanPlayer.h"
#include "NoughtsAndCrosses.h"

// Entry point to program.
int main() {

	while (true) {
		// clear screen
		system("cls");

		// print main menu
		std::cout <<	"***********      Noughts And Crosses      **********\n" << 
						"*                                                  *\n" <<
						"*    (1) - Play The Game                           *\n" << 
						"*    (2) - Quit Game                               *\n" <<
						"*                                                  *\n" <<
						"****************************************************" << std::endl;
	
		// play or quit
		int userChoice;
		while (true) {
			userChoice = Utility::getValidInput();

			if (userChoice > 0 && userChoice < 3)
				break;

			std::cout << "You must enter 1 to play or 2 to quit!" << std::endl;
		}

		if (userChoice == 1) { // User choses to play game
			system("cls");
			std::cout << "***********      Select Player Type       **********\n" <<
				"*                                                  *\n" <<
				"*    (1) - Human Player                            *\n" <<
				"*    (2) - AI Player                               *\n" <<
				"*                                                  *\n" <<
				"****************************************************" << std::endl;
			// get type for player 1
			std::cout << "Select player type for x's" << std::endl;
			int p1Type;
			while (true) {
				p1Type = Utility::getValidInput();

				if (p1Type == 1 || p1Type == 2)
					break;
				std::cout << "Select 1 for Human Player or 2 for AI Player!" << std::endl;
			}

			// get type for player 2
			std::cout << "Select player type for o's" << std::endl;
			int p2Type;
			while (true) {
				p2Type = Utility::getValidInput();

				if (p2Type == 1 || p2Type == 2)
					break;
				std::cout << "Select 1 for Human Player or 2 for AI Player!" << std::endl;
			}
			
			// Play Game
			NoughtsAndCrosses game(p1Type == 1 ? NoughtsAndCrosses::PlayerType::HUMAN_PLAYER : NoughtsAndCrosses::PlayerType::AI_PLAYER, 
									p2Type == 1 ? NoughtsAndCrosses::PlayerType::HUMAN_PLAYER : NoughtsAndCrosses::PlayerType::AI_PLAYER);
			game.play();
		}
		else
			break;
	}

	// thanks for playing
	std::cout << "Thanks for playing Noughts and Crosses" << std::endl;
}
