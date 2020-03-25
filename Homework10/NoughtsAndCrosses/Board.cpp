#include "Board.h"
#include <sstream>
#include <algorithm>


// winning patterns 
const int Board::WINNING_COMBOS[NUM_WINNING_COMBOS][NUM_IN_COMBO] =
{ {0, 1, 2},
  {3, 4, 5},
  {6, 7, 8},
  {0, 3, 6},
  {1, 4, 7},
  {2, 5, 8},
  {0, 4, 8},
  {2, 4, 6} };


Board::Board()
{
	reset();
}

void Board::reset()
{
	board = std::vector<char>(9, ' ');
}

bool Board::isFull() const
{
	//for (char c : board) {
	//	if (c == ' ')
	//		return false;
	//}

	return std::none_of(
		board.begin(), 
		board.end(),
		[](char e) {return e == ' ';});

}


bool Board::isValidMove(int move) const
{
	if (move >= 0 && move < NUM_SQUARES) {
		return board[move] == ' ';
	}
	else {
		return false;
	}
}

bool Board::checkCombo(int combo, char piece) const
{
	int piecesInCombo = 0;
	for (int i = 0; i < NUM_IN_COMBO; ++i) {
		if (board[WINNING_COMBOS[combo][i]] == piece) {
			++piecesInCombo;
		}
	}

	if (piecesInCombo == NUM_IN_COMBO)
		return true;
	else
		return false;
}

bool Board::isWinner(char piece) const
{
	// check all winning combinations 
	bool winner = false;
	int combo = 0;
	while (!winner && combo < NUM_WINNING_COMBOS) {
		winner = checkCombo(combo, piece);
		++combo; // try next combination
	}
	return winner;
}

std::string Board::getBoardPlaces() const
{
	std::stringstream ss;

	ss << "\n\t0 | 1 | 2";
	ss << "\n\t---------";
	ss << "\n\t3 | 4 | 5";
	ss << "\n\t---------";
	ss << "\n\t6 | 7 | 8";

	return ss.str();
}

std::string Board::getCurrentBoard() const
{
	std::stringstream ss;
	ss << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	ss << "\n\t---------";

	ss << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	ss << "\n\t---------";

	ss << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	ss << "\n";

	return ss.str();
}

void Board::makeMove(char playerPiece, int move)
{
	board[move] = playerPiece;
}
