#pragma once
#include "Command.h"
#include "StageService.h"
#include "TaskService.h"
#include "UserHolder.h"

class MoveTaskToStageCommand : public Command {
private:
    StageService& stageService;
    TaskService& taskService;
    UserHolder& session;
public:
    MoveTaskToStageCommand(StageService& stageService, TaskService& taskService, UserHolder& session);
    void execute(const std::vector<std::string>& args) override;
    std::string name() const override;
    std::string usage() const override;
};