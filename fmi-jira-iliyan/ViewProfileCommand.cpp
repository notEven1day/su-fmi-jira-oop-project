#include "ViewProfileCommand.h"

ViewProfileCommand::ViewProfileCommand(UserHolder& session)
    : session(session) {

}

void ViewProfileCommand::execute(const std::vector<std::string>& args)
{
    if (args.size() != 1)
    {
        std::cout << usage();
        return;
    }

    User* user = session.get();

    if (!user)
    {
        std::cout << "No user is currently logged in.\n";
        return;
    }

    std::cout << "=== Profile ===\n";
    std::cout << "ID: " << user->getId() << "\n";
    std::cout << "Username: " << user->getUsername() << "\n";
}

std::string ViewProfileCommand::name() const
{
    return "view-profile";
}

std::string ViewProfileCommand::usage() const
{
    return "Usage:" + name() + "\n";
}
