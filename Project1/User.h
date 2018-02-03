#pragma once
#include <string>
#include <iostream>
using namespace std;
class User
{
private:
	int id;
	string username, password;
public:
	User(int, string, string);
	~User();
	int getId() {
		return id;
	}
	void setId(int id) {
		this->id = id;
	}
	std::string getUsername() {
		return username;
	}
	void setUsername(string username) {
		this->username = username;
	}
	std::string getPassword() {
		return password;
	}
	void setPassword(string password) {
		this->password = password;
	}
};

