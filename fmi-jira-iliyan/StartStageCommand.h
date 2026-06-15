#pragma once
#include "Command.h"
#include "StageService.h"
#include "UserHolder.h"

class StartStageCommand : public Command {
private:
    StageService& stageService;
    UserHolder& session;

    static std::string today();
public:
    StartStageCommand(StageService& stageService, UserHolder& session);
    void execute(const std::vector<std::string>& args) override;
    std::string name() const override;
    std::string usage() const override;
};