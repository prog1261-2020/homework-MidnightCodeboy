#pragma once
#include <string>
#include <vector>
 
class Board
{
public:
	Board();
	void reset();
	bool isFull() const;
	bool isWinner(char playerPiece) const;
	bool isValidMove(int move) const;
	std::string getBoardPlaces() const;
	std::string getCurrentBoard() const;
	void makeMove(char playerPiece, int move);
 

private: 
	bool checkCombo(int combo, char piece) const;

	static const int NUM_SQUARES = 9;
	static const char EMPTY = ' ';
	static const int NUM_WINNING_COMBOS = 8;
	static const int NUM_IN_COMBO = 3;
	static const int WINNING_COMBOS[NUM_WINNING_COMBOS][NUM_IN_COMBO];

	std::vector<char> board;    // 'X', 'O', or ' '
};

