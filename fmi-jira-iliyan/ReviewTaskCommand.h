#pragma once
#include <iostream>
#include "Command.h"
#include "TaskService.h"
#include "UserHolder.h"

class ReviewTaskCommand : public Command
{
private:
    TaskService& taskService;
    UserHolder& session;

public:
    ReviewTaskCommand(TaskService& taskService, UserHolder& session);
    void execute(const std::vector<std::string>& args) override;
    std::string name() const override;
    std::string usage() const override;
};