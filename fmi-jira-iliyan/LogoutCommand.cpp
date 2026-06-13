#include "LogoutCommand.h"

LogoutCommand::LogoutCommand(UserHolder& session) : session(session)
{
}

void LogoutCommand::execute(const std::vector<std::string>& args)
{
    if (args.size() != 1)
    {
        std::cout << usage();
        return;
    }
    if (session.isLoggedIn()) {
        std::cout << "Logging out user \n";
        session.clear();
    }
    else
    {
        std::cout << "User not logged in! \n";
    }
}

std::string LogoutCommand::name() const
{
    return "logout";
}

std::string LogoutCommand::usage() const
{
    return "Usage:" + name() + "\n";
}
