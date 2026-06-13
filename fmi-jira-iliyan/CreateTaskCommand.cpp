#include "CreateTaskCommand.h"

CreateTaskCommand::CreateTaskCommand(ProjectService& ps, TaskService& ts, UserHolder& sh)
	:projectService(ps), taskService(ts), session(sh)
{
}

void CreateTaskCommand::execute(const std::vector<std::string>& args)
{
    if (args.size() != 5) {
        std::cout << usage();
        return;
    }

    std::string taskName = args[1];
    std::string projectName = args[2];
    std::string typeStr = args[3];
    std::string priorityStr = args[4];

    Project* project = projectService.findProjectByName(projectName);
    if (!project) {
        std::cout << "No such project exists";
        return;
    }
        
   
    Type type = typeFromString(typeStr);
    Priority priority = priorityFromString(priorityStr);

    taskService.createTask(taskName, project, type, priority, session.get());
}

std::string CreateTaskCommand::name() const
{
	return "create-task";
}

std::string CreateTaskCommand::usage() const
{
	return "Usage: " + name() + "<task-name> <project> <type> <priority>\n";
}
