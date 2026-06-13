#pragma once
#include "Command.h"
#include "ProjectService.h"
#include "UserHolder.h"

class JoinProjectCommand : public Command {
private:
    ProjectService& projectService;
    UserHolder& session;

public:
    JoinProjectCommand(ProjectService& ps, UserHolder& sh);
    void execute(const std::vector<std::string>& args) override;
    std::string name()  const override;
    std::string usage() const override;
};