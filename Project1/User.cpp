#include "User.h"
using namespace std;

User::User(int id, string username, string password)
{
	this->id = id;
	this->username = username;
	this->password = password;
}


User::~User()
{
}