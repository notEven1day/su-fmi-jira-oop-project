#pragma once
#include<iostream>
#include "User.h"
#include<vector>
#include "Project.h"

//class CommandContext {
//public:
//    // Nullable — nullptr means no one is logged in
//    User* currentUser = nullptr;
//
//    // Application owns all users and projects
//    std::vector<std::unique_ptr<User>>    users;
//    std::vector<std::unique_ptr<Project>> projects;
//
//    // Helpers
//    User* findUser(const std::string& username);
//    Project* findProject(const std::string& name);
//    Task* findTaskGlobally(int id);   // searches all projects
//    Stage* findStageGlobally(const std::string& stageName);
//};