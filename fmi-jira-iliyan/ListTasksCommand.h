#pragma once
#include<iostream>
#include<string>
#include "Command.h"
#include "TaskService.h"
#include "UserHolder.h"

class ListTasksCommand: public Command {
private:
    TaskService& taskService;
    UserHolder& session;

public:
    ListTasksCommand(TaskService& ts, UserHolder& sh);
    void execute(const std::vector<std::string>& args) override;
    std::string name()  const override;
    std::string usage() const override;
};