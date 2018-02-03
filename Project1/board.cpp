#include "board.h"
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <random>
#include <ctime>

using namespace std;

bool Board::addMine(vector<vector<char> > map)
{

	int x = rand() % x_dim, y = rand() % y_dim;


	if (map[x][y] != '*')
	{
		map[x][y] = '*';

		for (int dx = x - 1; dx <= x + 1; dx++)
			for (int dy = y - 1; dy <= y + 1; dy++)
				if (dx >= 0 && dx < x_dim && dy >= 0 && dy < y_dim)
					if (map[dx][dy] != '*')
						if (map[dx][dy] == '.')
							map[dx][dy] = '1';
						else
							map[dx][dy]++;
		return true;
	}

	return false;
}

bool Board::revealLocation(vector<vector<char> > map, vector<vector<char> > mask, int x, int y)
{

	mask[x][y] = '.';


	if (map[x][y] == '*')
		return true;


	if (map[x][y] == '.')
	{

		queue<pair<int, int> > openLocations;//вы€вл€ет места где р€дом нет мин
		openLocations.push(make_pair(x, y));

		while (!openLocations.empty())
		{

			pair<int, int> next = openLocations.front();


			for (int dx = next.first - 1; dx <= next.first + 1; dx++)
			{
				for (int dy = next.second - 1; dy <= next.second + 1; dy++)
				{
					if (dx >= 0 && dx < x_dim && dy >= 0 && dy < y_dim)
					{
						if (map[dx][dy] == '.' && mask[dx][dy] == '#')
							openLocations.push(make_pair(dx, dy));

						mask[dx][dy] = '.';

					}
				}
			}

			openLocations.pop();
		}
	}

	return false;
}

int Board::countMask(vector<vector<char> > mask)
{
	int count = 0;
	for (int x = 0; x < x_dim; x++)
		for (int y = 0; y < y_dim; y++)
			if (mask[x][y] == '#') count++;

	return count;
}

