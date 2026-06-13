#pragma once
#include<iostream>
#include<string>
#include "Command.h"
#include "AuthenticationService.h"

class SignUpCommand : public Command {
    AuthService& authService;
public:
    SignUpCommand(AuthService& authService);
    void execute(const std::vector<std::string>& args) override;
    std::string name()  const override;
    std::string usage() const override;
};