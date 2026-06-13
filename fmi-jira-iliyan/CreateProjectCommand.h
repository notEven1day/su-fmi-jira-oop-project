#pragma once
#include "Command.h"
#include "ProjectService.h"
#include "UserHolder.h"
#include <vector>
#include <string>

class CreateProjectCommand : public Command {
private:
    ProjectService& projectService;
    UserHolder& session;

public:
    CreateProjectCommand(ProjectService& projectService, UserHolder& session);
    void execute(const std::vector<std::string>& args) override;
    std::string name()  const override;
    std::string usage() const override;
};