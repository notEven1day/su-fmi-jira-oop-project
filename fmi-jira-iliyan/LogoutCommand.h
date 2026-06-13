#pragma once
#include<iostream>
#include<string>
#include "Command.h"
#include "AuthenticationService.h"
#include "UserHolder.h"
class LogoutCommand : public Command {

private:
    UserHolder& session;

public:
    LogoutCommand(UserHolder& session);

    void execute(const std::vector<std::string>& args) override;
    std::string name()  const override;
    std::string usage() const override;
};