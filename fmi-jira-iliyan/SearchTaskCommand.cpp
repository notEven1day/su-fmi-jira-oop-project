#include "SearchTaskCommand.h"

SearchTaskCommand::SearchTaskCommand(TaskService& taskService, UserHolder& session)
	: taskService(taskService), session(session)
{
}

void SearchTaskCommand::execute(const std::vector<std::string>& args)
{
    if (args.size() != 2)
    {
        std::cout << usage();
        return;
    }

    std::string keyword = args[1];

    auto tasks = taskService.findTaskByKeywordInTitle(keyword);

    if (tasks.empty())
    {
        std::cout << "No tasks found.\n";
        return;
    }

    for (const auto& task : tasks)
    {
         task->print();
    }
}

std::string SearchTaskCommand::name() const
{
	return "search - tasks";
}

std::string SearchTaskCommand::usage() const
{
	return "Usage:" + name() + "<keyword>";
}
