#include "MoveTaskToStageCommand.h"

MoveTaskToStageCommand::MoveTaskToStageCommand(StageService& stageService, TaskService& taskService, UserHolder& session)
    : stageService(stageService), taskService(taskService), session(session) {
}

void MoveTaskToStageCommand::execute(const std::vector<std::string>& args) {
    if (args.size() != 3) {
        std::cout << usage();
        return;
    }

    int taskId = std::stoi(args[1]);
    std::string stageName = args[2];

    Task* task = taskService.findTaskById(taskId);
    if (!task)
        throw std::runtime_error("Task with id '" + args[1] + "' not found.");

    Stage& stage = stageService.findStageByName(stageName);
    stage.getStageTasks().push_back(std::make_unique<Task>(*task));

    std::cout << "Task '" + task->getTaskTitle() + "' moved to stage '" + stageName + "' successfully.\n";
}

std::string MoveTaskToStageCommand::name() const {
    return "move-task-to-stage"; 
}
std::string MoveTaskToStageCommand::usage() const { 
    return "Usage: " + name() +"<task_id> <stage_name>\n"; 
}