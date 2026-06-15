#include "CreateStageCommand.h"

CreateStageCommand::CreateStageCommand(StageService& stageService, UserHolder& session)
	: stageService(stageService), session(session)
{

}

void CreateStageCommand::execute(const std::vector<std::string>& args)
{

	if (args.size() != 2)
	{
		std::cout << usage();
		return;
	}

	std::string stageName = args[1];

	Stage& stage = stageService.createStage(stageName);
	std::cout << "Stage " + stage.getStageName() + " created succesfully.\n";
}

std::string CreateStageCommand::name() const
{
	return "create-stage";
}

std::string CreateStageCommand::usage() const
{
	return "Usage: " + name() + "<stage_name>\n";
}
