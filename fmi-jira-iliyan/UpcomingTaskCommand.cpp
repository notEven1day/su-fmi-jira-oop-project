#include "UpcomingTaskCommand.h"

UpcomingTaskCommand::UpcomingTaskCommand(TaskService& taskService, UserHolder& session)
    : taskService(taskService), session(session) {
}

void UpcomingTaskCommand::execute(const std::vector<std::string>& elements) {
    std::vector<Task>& tasks = taskService.getTasks();
    int upcomingTasksCount = 0;
    for (const Task& task : tasks) {
        if (task.getTaskStatus() == TaskStatus::ToDo) {
            task.print();
            upcomingTasksCount++;
        }
    }
    std::cout << "There are " << upcomingTasksCount << "upcoming tasks. \n";
}

std::string UpcomingTaskCommand::name() const
{
	return "upcoming-tasks";
}

std::string UpcomingTaskCommand::usage() const
{
	return "Usage: " + name();
}
