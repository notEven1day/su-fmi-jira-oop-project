#pragma once
#include <vector>
#include <string>
#include "TaskService.h"
#include "UserHolder.h"
#include "Command.h"
#include "Task.h"


class ChangeTaskStatusCommand : public Command{
private:
    TaskService& taskService;
    UserHolder& session;

public:
    ChangeTaskStatusCommand(TaskService& taskService, UserHolder& session);
    void execute(const std::vector<std::string>& args) override;
    std::string name()  const override;
    std::string usage() const override;
};