#include <iostream>
#include <string>
#include <time.h>
#include "board.h"
#include <vector>

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));


	Board vector<vector<char> >map;
	Board vector<vector<char> >mask;
	int x_dim, y_dim;
	for (int i = 0; i < x_dim; i++)
	{
		map.push_back(vector<char>(y_dim, '.'));
		mask.push_back(vector<char>(y_dim, '#'));
	}
	int mineCount = 0;

	do
	{
		if (addMine(map))
			mineCount++;
	} while (mineCount != numMines);


	int x_in, y_in;
	do
	{
		cout << "  0123456789" << endl;
		cout << "  ----------" << endl;

		for (int x = 0; x < x_dim; x++)
		{
			cout << x << "|";

			for (int y = 0; y < y_dim; y++)
			{
				if (mask[x][y] == '#')
					cout << '#';
				else
					cout << map[x][y];
			}
			cout << endl;
		}

		cin >> x_in >> y_in;

		if (Board::revealLocation(map, mask, x_in, y_in))
		{
			cout << "You set off a mine.  Game over!" << endl;
			break;
		}

		if (Board::countMask(mask) == numMines)
		{
			cout << "You have found all the mines.  Congratulations!" << endl;
			break;
		}

	} while (1);

	delete &map;
	delete &mask;

	cout << endl;

	system("pause");
	return 0;
}