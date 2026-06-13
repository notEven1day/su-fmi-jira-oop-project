#include "AuthenticationService.h"
#include <fstream>
#include <sstream>
#include <iostream>

void AuthService::createDefaultAdmin()
{
   
        std::cout << "Creating default administrator account...\n";

        User admin("admin", "admin", Role::Administrator);

        users.push_back(admin);
        saveToFile(admin);
   
}

AuthService::AuthService()
{
    fetchUsersFromFile();
    if (users.empty()) {
        createDefaultAdmin();
    }
    
    
}

void AuthService::fetchUsersFromFile()
{
    users.clear();

    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "No users file found.\n";
        return;
    }

    int id;
    std::string username, password, roleStr;

    while (file >> id >> username >> password >> roleStr)
    {
        users.emplace_back(id, username, password, stringToRole(roleStr));
    }

    file.close();
}

void AuthService::saveToFile(const User& user)
{
    std::ofstream file(fileName, std::ios::app);

    if (!file.is_open()) {
        std::cout << "Cannot open file for writing.\n";
        return;
    }
    
    file << user.getId() << " "
        << user.getUsername() << " "
        << user.getPassword()<< " "   
        << roleToString(user.getRole())
        << "\n";

    file.close();
}

void AuthService::signUp(const std::vector<std::string>& args)
{
    std::string username = args[1];
    std::string password = args[2];
    Role role = stringToRole(args[3]);
    if (role == Role::Administrator) {
        std::cout << "Admin can be only one and is automatically created on start. \n";
        return;
    }
    
    for (const auto& u : users)
    {
        if (u.getUsername() == username)
        {
            std::cout << "User already exists.\n";
            return;
        }
    }

    User newUser(username, password, role);

    users.push_back(newUser);
    saveToFile(newUser);

    std::cout << "User created successfully.\n";
}

User* AuthService::login(const std::string& username, const std::string& password)
{

    for (auto& user : users)
    {
        if (user.getUsername() == username &&
            user.checkPassword(password))
        {
            return &user;
        }
    }

    return nullptr;
}


