#include "ApproveTaskCommand.h"

ApproveTaskCommand::ApproveTaskCommand(
    TaskService& taskService,
    UserHolder& session)
    : taskService(taskService),
    session(session)
{
}

void ApproveTaskCommand::execute(const std::vector<std::string>& args)
{
    if (args.size() != 2)
    {
        std::cout << usage();
        return;
    }

    int id = std::stoi(args[1]);

    Task* task = taskService.findTaskById(id);

    if (!task)
    {
        std::cout << "Task not found.\n";
        return;
    }

    task->setTaskStatus(TaskStatus::Done);
    task->setPriority(Priority::Low);

    std::cout << "Task approved successfully.\n";
}

std::string ApproveTaskCommand::name() const
{
	return "approve-task";
}

std::string ApproveTaskCommand::usage() const
{
    return "Usage: " + name() + "<task-id>\n";
}
