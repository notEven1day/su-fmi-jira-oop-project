#include "JoinProjectCommand.h"

JoinProjectCommand::JoinProjectCommand(ProjectService& ps, UserHolder& sh) : projectService(ps),session(sh)
{
}

void JoinProjectCommand::execute(const std::vector<std::string>& args)
{
    if (args.size() != 2)
    {
        std::cout << usage();
        return;
    }

    User* user = session.get();

    if (!user)
    {
        std::cout << "You must be logged in.\n";
        return;
    }

    Project* project = projectService.findProjectByName(args[1]);

    if (!project)
    {
        std::cout << "Project not found.\n";
        return;
    }

    project->addMember(std::shared_ptr<User>(user, [](User*) {}));

    std::cout << "Joined project: " << project->getName() << "\n";
}

std::string JoinProjectCommand::name() const
{
    return "join-project";
}

std::string JoinProjectCommand::usage() const
{
    return "Usage:" + name() + "<project_name>";
}
