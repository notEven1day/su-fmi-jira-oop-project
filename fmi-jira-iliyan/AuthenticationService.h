#pragma once
#include<iostream>
#include<vector>
#include<string>

#include "User.h"

class AuthService {
private:
    std::vector<User> users;
    std::string fileName = "users.txt";
    void createDefaultAdmin();

public:
    AuthService();
    void signUp(const std::vector<std::string>& args);
    void saveToFile(const User& user);
    void fetchUsersFromFile();
    User* login(const std::string& username,
        const std::string& password);
    
};