#include "Project.h"
#include "TaskService.h"

Project::Project(const std::string& name)
    : name(name), status(ProjectStatus::Active)
{

}

const std::string& Project::getName() const
{
    return name;
}

const std::string& Project::getDescription() const
{
    return description;
}

const std::vector<std::shared_ptr<User>>& Project::getMembers() const
{
    return members;
}

const std::vector<std::unique_ptr<Task>>& Project::getTasks() const
{
    return tasks;
}


const std::vector<std::unique_ptr<Stage>>& Project::getStages() const
{
    return stages;
}

const ProjectStatus& Project::getStatus() const
{
    return status;
}

void Project::addMember(std::shared_ptr<User> user)
{
    for (const auto& m : members)
    {
        if (m->getId() == user->getId())
        {
            return;
        }
    }

    members.push_back(user);
}

void Project::addTask(std::unique_ptr<Task> task)
{
    for (const auto& t : tasks)
    {
        if (t->getId() == task->getId())
        {
            return;
        }
    }
    tasks.push_back(std::move(task));
}
