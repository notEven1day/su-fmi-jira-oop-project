#include "Stage.h"

int Stage::getStageId()
{
    return id;
}

Stage::Stage(int id, const std::string& name)
    : id(id), name(name), status(StageStatus::Planned)
{
}

std::string& Stage::getStageName() 
{
    return name;
}
