#include "ListMyProjectsCommand.h"

ListMyProjectsCommand::ListMyProjectsCommand(ProjectService& ps, UserHolder& sh)
	: projectService(ps), session(sh)
{
}

void ListMyProjectsCommand::execute(const std::vector<std::string>& args)
{
    User* user = session.get();

    if (!user)
    {
        std::cout << "You must be logged in to view your projects.\n";
        return;
    }

    if (args.size() != 1)
    {
        std::cout << usage();
        return;
    }

    const auto& projects = projectService.getProjects();

    bool found = false;

    for (const auto& project : projects)
    {
        for (const auto& member : project.getMembers())
        {
            if (member->getId() == user->getId())
            {
                std::cout << "- " << project.getName() << "\n";
                found = true;
            }
        }
    }

    if (!found)
    {
        std::cout << "You are not part of any projects.\n";
    }
}

std::string ListMyProjectsCommand::name() const
{
	return "list-my-projects";
}

std::string ListMyProjectsCommand::usage() const
{
	return "Usage: " + name() + "\n";
}
