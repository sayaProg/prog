#include "Player.h"

Player::Player()
{
	current = -1;
	std::ifstream fin("users.txt");
	int id;
	std::string username, password;
	while (!fin.eof())
	{
		fin >> id >> username >> password;
		users.push_back(User(id, username, password));
	}
	fin.close();
}


Player::~Player()
{
	std::ofstream fout("players.txt");
	std::for_each(users.begin(), users.end(), [&fout](User & user)
	{
		fout << std::endl << user.getId() << ' ' << user.getUsername() << ' ' << user.getPassword();
	});
	fout.close();
}

void Player::signup(std::string username, std::string password)
{
	users.push_back(User(users.size() + 1, username, password));
	current = users.size() - 1;
}

bool Player::signin(std::string username, std::string password)
{
	for (int i = 0; i < users.size(); ++i)
	{
		if (username == users[i].getUsername() && password == users[i].getPassword())
		{
			current = i;
			return true;
		}
	}
	return false;
}