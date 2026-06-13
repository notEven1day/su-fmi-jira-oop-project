#pragma once
#include <vector>
#include <string>
#include "Command.h"
#include "TaskService.h"
#include "UserHolder.h"

class UpcomingTaskCommand : public Command{
private:
    TaskService& taskService;
    UserHolder& session;

public:
    UpcomingTaskCommand(TaskService& taskService, UserHolder& session);
    void execute(const std::vector<std::string>& args) override;
    std::string name()  const override;
    std::string usage() const override;
};
