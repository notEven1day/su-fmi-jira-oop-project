#pragma once
#include<iostream>
#include<string>
#include "Command.h"
#include "AuthenticationService.h"
#include "UserHolder.h"

class LoginCommand : public Command {
private:
    AuthService& authService;
    UserHolder& session;

public:
    LoginCommand(AuthService& authService, UserHolder& session);

    void execute(const std::vector<std::string>& args) override;
    std::string name()  const override;
    std::string usage() const override;
};