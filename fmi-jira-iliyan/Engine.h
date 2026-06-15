#pragma once
#include<iostream>
#include<string>
#include "AuthenticationService.h"
#include "ProjectService.h"
#include "TaskService.h"
#include "UserHolder.h"
#include "StageService.h"
#include "Command.h"

class Engine {
private:
    AuthService authService;
    ProjectService projectService;
    TaskService taskService;
    UserHolder session;
    StageService stageService;
    std::vector<std::unique_ptr<Command>> commands;

public:
    Engine();
    void registerCommands();
    void processCommand(const std::string& line);
    void run();
};
