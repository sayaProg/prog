#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <memory>
#include "User.h"
#include "Authenticator.h"
class Player : public Authenticator
{
private:
	int current;
	Player();
public:
	std::vector<User> users;
	static std::shared_ptr<Player> getInstance()
	{
		static std::shared_ptr<Player> instance(new Player());
		return instance;
	}
	~Player();
	void signup(std::string, std::string);
	bool signin(std::string, std::string);
	Player(const Player &) = delete;
	int getCurrent() {
		return current;
	}
	
};