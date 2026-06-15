#include "FinishStageCommand.h"

FinishStageCommand::FinishStageCommand(StageService& stageService, UserHolder& session)
    : stageService(stageService), session(session) {
}

void FinishStageCommand::execute(const std::vector<std::string>& args) {
    if (args.size() != 2) {
        std::cout << usage();
        return;
    }
    std::string stageName = args[1];
    Stage& stage = stageService.findStageByName(stageName);

    if (stage.getStageStatus() == StageStatus::Planned)
        throw std::runtime_error("Stage '" + stageName + "' has not been started yet.");
    if (stage.getStageStatus() == StageStatus::Finished)
        throw std::runtime_error("Stage '" + stageName + "' is already finished.");

    stage.setEndDate(today());
    stage.setStageStatus(StageStatus::Finished);

    std::cout << "Stage '" + stageName + "' finished successfully.\n";
}

std::string FinishStageCommand::name() const { 
    return "finish-stage"; 
}
std::string FinishStageCommand::usage() const { 
    return "Usage: " + name() +  "<stage_name>\n"; 
}

std::string FinishStageCommand::today() { return "2026-06-15"; }