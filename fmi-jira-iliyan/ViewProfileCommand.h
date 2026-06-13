#pragma once
#include "Command.h"
#include "UserHolder.h"
#include <vector>
#include <string>

class ViewProfileCommand : public Command {
private:
    UserHolder& session;

public:
    ViewProfileCommand(UserHolder& session);
    void execute(const std::vector<std::string>& args) override;
    std::string name()  const override;
    std::string usage() const override;
};