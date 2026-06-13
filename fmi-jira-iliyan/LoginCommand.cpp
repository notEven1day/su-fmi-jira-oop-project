#include "LoginCommand.h"

LoginCommand::LoginCommand(AuthService& authService, UserHolder& session) : authService(authService), session(session)
{
}

void LoginCommand::execute(const std::vector<std::string>& args)
{
    if (args.size() != 3)
    {
        std::cout << usage();
        return;
    }

    User* user = authService.login(args[1], args[2]);

    if (user)
    {
        session.set(user);
        std::cout << "Login successful: " << user->getUsername() << "\n";
    }
    else
    {
        std::cout << "Invalid credentials\n";
    }
}

std::string LoginCommand::name() const
{
    return "login";
}

std::string LoginCommand::usage() const
{
    return "Usage:" + name() + "<username> <password>\n";
}
