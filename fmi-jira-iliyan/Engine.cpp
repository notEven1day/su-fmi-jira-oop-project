#include "Engine.h"
#include<iostream>
#include<vector>
#include "LoginCommand.h"
#include "SignUpCommand.h"
#include "LogoutCommand.h"
#include "ViewProfileCommand.h"
#include "CreateProjectCommand.h"
#include "JoinProjectCommand.h"
#include "ListMyProjectsCommand.h"
#include "Command.h"


static std::vector<std::string> split(const std::string& line);

void Engine::processCommand(const std::string& line)
{
    std::vector<std::string> elements = split(line);

    if (elements.empty()) {
        return;
    }

    std::string command = elements[0];

    if (command == "login") {
        LoginCommand login(authService, session);
        login.execute(elements);
    }
    else if (command == "signUp") {
        SignUpCommand signUp(authService);
        signUp.execute(elements);
    }
    else if (command == "logout") {
        LogoutCommand logOutCommand(session);
        logOutCommand.execute(elements);
    }
    else if (command == "view-profile") {
        ViewProfileCommand viewProfileCommand(session);
        viewProfileCommand.execute(elements);
    }
    else if (command == "create-project") {
        CreateProjectCommand createProjectCommand(projectService, session);
        createProjectCommand.execute(elements);
    } 
    else if (command == "archive-project") {
        //TODO
    }
    else if (command == "join-project") {
        //join - project <project_name>
        JoinProjectCommand joinProjectCommand(projectService, session);
        joinProjectCommand.execute(elements);
    }
    else if (command == "list-my-projects") {
        //untested
        ListMyProjectsCommand listMyProjectsCommand(projectService, session);
        listMyProjectsCommand.execute(elements);
    }

    
}
static std::vector<std::string> split(const std::string& line) {
    std::vector<std::string> elements;
    std::string current;

    for (char c : line) {
        if (c == ' ') {
            if (!current.empty()) {
                elements.push_back(current);
                current.clear();
            }
        }
        else {
            current += c;
        }
    }
    if (!current.empty()) {
        elements.push_back(current);
    }

    return elements;
}

const std::string CLOSE = "close";
void Engine::run()
{
    std::string line;

    std::cout << "System started. Type 'help' for commands.\n";

    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, line);

        if (line == CLOSE)
        {
            std::cout << "Shutting down...\n";
            break;
        }

        processCommand(line);
    }
}