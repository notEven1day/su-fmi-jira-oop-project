#pragma once
#include<iostream>
#include "Command.h"
#include "StageService.h"
#include "UserHolder.h"

class CreateStageCommand : public Command {
private:
    StageService& stageService;
    UserHolder& session;

public:
    CreateStageCommand(StageService& stageService, UserHolder& session);
    void execute(const std::vector<std::string>& args) override;
    std::string name() const override;
    std::string usage() const override;
};