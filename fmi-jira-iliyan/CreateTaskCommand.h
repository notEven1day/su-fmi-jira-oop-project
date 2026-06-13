#pragma once
#include<iostream>
#include "Command.h"
#include "ProjectService.h"
#include "TaskService.h"
#include "UserHolder.h"

class CreateTaskCommand : Command {
private:
    ProjectService& projectService;
    TaskService& taskService;
    UserHolder& session;

public:
    CreateTaskCommand(ProjectService& ps,TaskService& ts, UserHolder& sh);
    void execute(const std::vector<std::string>& args) override;
    std::string name()  const override;
    std::string usage() const override;
};