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
#include "ListTasksCommand.h"
#include "CreateTaskCommand.h"
#include "ChangeTaskStatusCommand.h"
#include "AddTaskCommentCommand.h"
#include "UpcomingTaskCommand.h"
#include "SearchTaskCommand.h"
#include "ApproveTaskCommand.h"
#include "ReviewTaskCommand.h"
#include "CreateStageCommand.h"
#include "StartStageCommand.h"
#include "FinishStageCommand.h"
#include "MoveTaskToStageCommand.h"
#include "Command.h"


static std::vector<std::string> split(const std::string& line);

Engine::Engine()
{
    registerCommands();
}

void Engine::registerCommands()
{
    commands.push_back(std::make_unique<LoginCommand>(authService, session));
    commands.push_back(std::make_unique<SignUpCommand>(authService));
    commands.push_back(std::make_unique<LogoutCommand>(session));
    commands.push_back(std::make_unique<ViewProfileCommand>(session));
    commands.push_back(std::make_unique<CreateProjectCommand>(projectService, session));
    commands.push_back(std::make_unique<JoinProjectCommand>(projectService, session));
    commands.push_back(std::make_unique<ListMyProjectsCommand>(projectService, session));
    commands.push_back(std::make_unique<ListTasksCommand>(taskService, session));
    commands.push_back(std::make_unique<CreateTaskCommand>(projectService, taskService, session));
    commands.push_back(std::make_unique<ChangeTaskStatusCommand>(taskService, session));
    commands.push_back(std::make_unique<AddTaskCommentCommand>(taskService, session));
    commands.push_back(std::make_unique<UpcomingTaskCommand>(taskService, session));
    commands.push_back(std::make_unique<SearchTaskCommand>(taskService, session));
    commands.push_back(std::make_unique<ApproveTaskCommand>(taskService, session));
    commands.push_back(std::make_unique<ReviewTaskCommand>(taskService, session));
    commands.push_back(std::make_unique<CreateStageCommand>(stageService, session));
    commands.push_back(std::make_unique<StartStageCommand>(stageService, session));
    commands.push_back(std::make_unique<FinishStageCommand>(stageService, session));
    commands.push_back(std::make_unique<MoveTaskToStageCommand>(stageService, taskService, session));


    //    stage - report
    //    list - all - projects
    //    grade - task <task_id> <grade>
    //    student - report <student_name>
    //    finalize - project <project_name>
    //    remaining commands
}

void Engine::processCommand(const std::string& line) {
    std::vector<std::string> elements = split(line);

    if (elements.empty()) return;

    std::string command = elements[0];

    try {
        if (command == "help") {
            for (const auto& cmd : commands)
                std::cout << cmd->usage() << "\n";
            return;
        }

        for (const auto& cmd : commands) {
            if (cmd->name() == command) {
                cmd->execute(elements);
                return;
            }
        }

        std::cout << "Unknown command. Type 'help' for available commands.\n";

    }
    catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }
    catch (...) {
        std::cout << "An unknown error occurred.\n";
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