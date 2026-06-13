#include "ListTasksCommand.h"

ListTasksCommand::ListTasksCommand(TaskService& ts, UserHolder& sh) : taskService(ts) , session(sh)
{
}

void ListTasksCommand::execute(const std::vector<std::string>& args)
{
	if (args.size() != 1) {
		std::cout << usage();
		return;
	}
	std::vector<Task>& tasks = taskService.getTasks();
	if (tasks.empty()) {
		std::cout << "No existing tasks\n";
	}
	else
	{
		for (const Task& task : tasks) {
			task.print();
		}
	}
	
}

std::string ListTasksCommand::name() const
{
	return "list-tasks";
}

std::string ListTasksCommand::usage() const
{
	return "Usage: " + name() +"\n";
}
