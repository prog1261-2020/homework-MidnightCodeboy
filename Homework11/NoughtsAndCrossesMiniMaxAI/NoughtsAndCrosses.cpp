/**
* @file NoughtsAndCrosses.cpp
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
*	Manages a complete round of Noughts and Crosses.
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

#include "NoughtsAndCrosses.h"
#include <iostream>
#include <vector>
#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"

// 2-Arg constructor. Sets up a game and sets up the players as either human or AI.
NoughtsAndCrosses::NoughtsAndCrosses(PlayerType player1, PlayerType player2) {

    board = new Board();

    // set up player 0
    if (player1 == PlayerType::HUMAN_PLAYER)
        players.push_back(new HumanPlayer('X'));
    else
        players.push_back(new AIPlayer('X', board)); // will be AIPlayer but not implemented yet

    // set up player 1
    if (player2 == PlayerType::HUMAN_PLAYER)
        players.push_back(new HumanPlayer('O'));
    else
        players.push_back(new AIPlayer('O', board)); // will be AIPlayer but not implemented yet
}

// Gets moves from players in alternating sequence and places them on board. Stops the game when it is won or tied.
void NoughtsAndCrosses::play()
{

    // while game not over
    while (true) {
        // clear screen
        system("cls");
        std::cout << "----------- Noughts And Crosses -----------" << std::endl;
        std::cout << "\nScreen Positions for making your move.." << std::endl;

        // print moves
        std::cout << board->getBoardPlaces() << std::endl;
        std::cout << "\n-------------------------------------------" << std::endl;

        // print board
        std::cout << board->getCurrentBoard() << std::endl;

        // puting exit condition here means we will print the final board position
        if (board->isFull() || board->isWinner((*players[0]).getPiece()) || board->isWinner((*players[1]).getPiece()))
            break;

        int move;
        // get move
        while (true) {
            move = (*players[currentPlayer]).getMove();

            if (board->isValidMove(move))
                break;
            std::cout << "You must select an unoccupied square" << std::endl;
       }
        
        // make move
        board->makeMove((*players[currentPlayer]).getPiece(), move);

        // Switch current user  
        currentPlayer = ++currentPlayer % 2;
       
    }
    
    // display winner message
    bool p1Wins = board->isWinner(players[0]->getPiece());
    bool p2Wins = board->isWinner(players[1]->getPiece());

    if (p1Wins)
        std::cout << players[0]->getPiece() << "'s have vanquished " << players[1]->getPiece() << "'s" << std::endl;
    else if (p2Wins)
        std::cout << players[1]->getPiece() << "'s have humiliated " << players[0]->getPiece() << "'s" << std::endl;
    else
        std::cout << "Both sides have been weighed in the ballances and found wanting!" << std::endl;

    std::cout << "\n\nPress a letter key followed by return to continue.." << std::endl;
    char tmp;
    std::cin >> tmp;
    
}
