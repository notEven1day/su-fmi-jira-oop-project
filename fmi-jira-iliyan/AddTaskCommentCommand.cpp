#include "AddTaskCommentCommand.h"

AddTaskCommentCommand::AddTaskCommentCommand(TaskService& taskService, UserHolder& session)
    : taskService(taskService), session(session) {
}

void AddTaskCommentCommand::execute(const std::vector<std::string>& args) {
    if (args.size() != 2) {
        std::cout << usage();
    }
    int taskId = std::stoi(args[1]);

    Task* task = taskService.findTaskById(taskId);
    if (!task) {
        std::cout << "Task not found.\n";
        return;
    }

    std::string commentText;
    std::cout << "Comment: ";
    std::getline(std::cin >> std::ws, commentText);

    task->addComment(commentText, session.get());
}

std::string AddTaskCommentCommand::name() const
{
    return "add-comment";
}

std::string AddTaskCommentCommand::usage() const
{
    return "Usage: " + name() + "<task_id>";
}
