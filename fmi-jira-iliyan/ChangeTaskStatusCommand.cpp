#include "ChangeTaskStatusCommand.h"

ChangeTaskStatusCommand::ChangeTaskStatusCommand(TaskService& taskService, UserHolder& session)
    : taskService(taskService), session(session) {
}

void ChangeTaskStatusCommand::execute(const std::vector<std::string>& args) {
    if (args.size() != 3) {
        std::cout << usage();
    }
    int taskId = std::stoi(args[1]);
    std::string statusStr = args[2];

    Task* task = taskService.findTaskById(taskId);
    if (!task) return;

    TaskStatus status = taskStatusFromString(statusStr);

    task->setTaskStatus(status);
}

std::string ChangeTaskStatusCommand::name() const
{
    return "change-status";
}

std::string ChangeTaskStatusCommand::usage() const
{
    return "Usage: "+ name() +"<task_id> <status>";
}
