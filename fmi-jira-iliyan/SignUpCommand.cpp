#include "SignUpCommand.h"

SignUpCommand::SignUpCommand(AuthService& authService) : authService(authService)
{
}

void SignUpCommand::execute(const std::vector<std::string>& args)
{
    if (args.size() != 4)
    {
        std::cout << usage();
        return;
    }
    authService.signUp(args);
}

std::string SignUpCommand::name() const
{
    return "signUp";
}

std::string SignUpCommand::usage() const
{
    return "Usage:" + name() + "<username> <password> <role>\n";
}
