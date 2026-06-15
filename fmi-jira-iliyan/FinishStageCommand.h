#pragma once
#include "Command.h"
#include "StageService.h"
#include "UserHolder.h"

class FinishStageCommand : public Command {
private:
    StageService& stageService;
    UserHolder& session;

    static std::string today();
public:
    FinishStageCommand(StageService& stageService, UserHolder& session);
    void execute(const std::vector<std::string>& args) override;
    std::string name() const override;
    std::string usage() const override;
};