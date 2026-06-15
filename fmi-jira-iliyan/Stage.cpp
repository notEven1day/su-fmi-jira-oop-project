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

StageStatus Stage::getStageStatus() const
{
    return status;
}

std::vector<std::unique_ptr<Task>>& Stage::getStageTasks()
{
    return tasks;
}

void Stage::setStartDate(const std::string& date)
{
    startDate = date;
}

void Stage::setStageStatus(StageStatus s)
{
    status = s;
}

void Stage::setEndDate(const std::string& date)
{
    endDate = date;
}
