#ifndef BOARD_H
#define BOARD_H
#include <vector>

class Board
{
public:
	Board();
	~Board();
	bool addMine(vector<vector<char> >);
	bool revealLocation(vector<vector<char> >, vector<vector<char> >, int x, int y);
	int countMask(vector<vector<char> > mask);
private:
	const int x_dim = 10, y_dim = 10, numMines = 10;
	typedef std::vector<std::vector<char> > board;
};

#endif
