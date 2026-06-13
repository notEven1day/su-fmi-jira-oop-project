#pragma once
#include<iostream>
#include<string>
#include "User.h"

class Comment {
	private:
		User* author;
		std::string content;
		std::string date;

	public: 
		Comment(User* author, const std::string& content, const std::string& date);
};
