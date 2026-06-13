#include "CreateProjectCommand.h"

CreateProjectCommand::CreateProjectCommand(ProjectService& projectService,
	UserHolder& session) : projectService(projectService), session(session)
{
}

void CreateProjectCommand::execute(const std::vector<std::string>& args)
{
    if (args.size() != 2)
    {
        std::cout << usage();
        return;
    }

    if (!session.get())
    {
        std::cout << "You must be logged in.\n";
        return;
    }

    if (session.get()->getRole() != Role::Administrator) {
        std::cout << "Command only for admins\n";
        return;
    }

    std::string name = args[1];

    projectService.createProject(name);

}

std::string CreateProjectCommand::name() const
{
	return "create-project";
}

std::string CreateProjectCommand::usage() const
{
	return "Usage:" + name() + "<name>\n";
}
