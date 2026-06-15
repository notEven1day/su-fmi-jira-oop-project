#include "ReviewTaskCommand.h"

ReviewTaskCommand::ReviewTaskCommand(TaskService& taskService, UserHolder& session)
	: taskService(taskService), session(session)
{
}

void ReviewTaskCommand::execute(const std::vector<std::string>& args)
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

    task->setTaskStatus(TaskStatus::InReview);
    std::cout << "Task moved to In Review.\n";
    task->print();
}

std::string ReviewTaskCommand::name() const
{
	return "review-task";
}

std::string ReviewTaskCommand::usage() const
{
	return "Usage:" + name() + "<task-id>\n";
}
