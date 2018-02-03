#pragma once
#include <string>
#include <vector>
using namespace std;
class Authenticator
{
public:
	//vector<User> users;
	virtual void signup(std::string, std::string) = 0;
	virtual bool signin(std::string, std::string) = 0;
	virtual int getCurrent() = 0;
	Authenticator();
	virtual ~Authenticator();
};