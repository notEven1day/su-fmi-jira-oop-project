#pragma once
#include<iostream>
#include<string>
#include "AuthenticationService.h"
#include "ProjectService.h"
#include "TaskService.h"
#include "UserHolder.h"

class Engine {
private:
    AuthService authService;
    ProjectService projectService;
    TaskService taskService;
    UserHolder session;

public:

    void processCommand(const std::string& line);
    void run();
};
