#include "UpcomingTaskCommand.h"

UpcomingTaskCommand::UpcomingTaskCommand(TaskService& taskService, UserHolder& session)
    : taskService(taskService), session(session) {
}

void UpcomingTaskCommand::execute(const std::vector<std::string>& elements) {
    std::vector<Task>& tasks = taskService.getTasks();

    for (const Task& task : tasks) {
        if (task.getTaskStatus() == TaskStatus::ToDo) {
            task.print();
        }
    }
}

std::string UpcomingTaskCommand::name() const
{
	return "upcoming-tasks";
}

std::string UpcomingTaskCommand::usage() const
{
	return "Usage: " + name();
}
