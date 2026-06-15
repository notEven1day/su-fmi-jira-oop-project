#include "StartStageCommand.h"
#include "FinishStageCommand.h"

StartStageCommand::StartStageCommand(StageService& stageService, UserHolder& session)
    : stageService(stageService), session(session) {
}

void StartStageCommand::execute(const std::vector<std::string>& args) {
    if (args.size() != 2) {
        std::cout << usage();
        return;
    }
    std::string stageName = args[1];
    Stage& stage = stageService.findStageByName(stageName);

    if (stage.getStageStatus() == StageStatus::Active)
        throw std::runtime_error("Stage '" + stageName + "' is already active.");
    if (stage.getStageStatus() == StageStatus::Finished)
        throw std::runtime_error("Stage '" + stageName + "' has already finished.");

    stage.setStartDate(today());
    stage.setStageStatus(StageStatus::Active);

    std::cout << "Stage '" + stageName + "' started successfully.\n";
}

std::string StartStageCommand::name() const {
    return "start-stage"; 
}
std::string StartStageCommand::usage() const { 
    return "Usage: " + name() +"<stage_name>\n";
}

std::string StartStageCommand::today() { return "2026-06-15"; }


