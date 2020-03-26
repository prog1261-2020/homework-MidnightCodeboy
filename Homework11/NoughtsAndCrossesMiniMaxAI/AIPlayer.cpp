/**
* @file AIPlayer.cpp
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
*	AI - non human player in a game of Noughts and Crosses (Tic Tac Toe).
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

#include "AIPlayer.h"
#include <algorithm>
#include <iostream>

AIPlayer::AIPlayer(char p, Board* b) : Player(p){
	board = b;
}

int AIPlayer::getMove() {
	std::vector<int> moves = getValidMoves();
	std::vector<int> scores;
	int maxEval = -1;

	
	// generate scores corrisponding to every valid move. and figure out highest score.
	for (int i = 0; i < moves.size(); i++) {
		board->makeMove(this->getPiece(), moves[i]);
		int eval = minimax(board, flipPlayer(this->getPiece()));
		maxEval = std::max(maxEval, eval);
		board->makeMove(' ', moves[i]); // reset board position (i.e. unmake move)
		scores.push_back(eval);
	}

	// find the first move whos score matches the highest value.
	for (int i = 0; i < moves.size(); i++) {
		if (scores[i] == maxEval)
			return moves[i];
	}

}

// Produces a list of all available moves for this configuration.
std::vector<int> AIPlayer::getValidMoves() {
	std::vector<int> moves;

	for (int i = 0; i < 9; i++) {
		if (board->isValidMove(i))
			moves.push_back(i);
	}

	return moves;
}

int AIPlayer::minimax(Board* board, char playerChar) {

	// Terminating cases

	if (board->isWinner(this->getPiece()))
		return 1;
	else if (board->isWinner(flipPlayer(this->getPiece())))
		return -1;
	else if (board->isFull())
		return 0;
		

	// Else Our move - maximize score
	else if (playerChar == this->getPiece()) {
		std::vector<int> moves = getValidMoves();

		int maxEval = -1;
		for (int i = 0; i < moves.size(); i++) {
			board->makeMove(playerChar, moves[i]);
			int eval = minimax(board, flipPlayer(playerChar));
			maxEval = std::max(maxEval, eval);
			board->makeMove(' ', moves[i]); // reset board position (i.e. unmake move)
		}

		return maxEval;
	}

	// Else oponents move - minimize score
	else{
		std::vector<int> moves = getValidMoves();

		int minEval = 1;
		for (int i = 0; i < moves.size(); i++) {
			board->makeMove(playerChar, moves[i]);
			int eval = minimax(board, flipPlayer(playerChar));
			minEval = std::min(minEval, eval);
			board->makeMove(' ', moves[i]); // reset board position (i.e. unmake move)
		}

		return minEval;
	}

}

char AIPlayer::flipPlayer(char playerChar) {
	if (playerChar == 'X')
		return 'O';
	else
		return 'X';
}