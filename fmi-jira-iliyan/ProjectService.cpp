#include "ProjectService.h"
#include <fstream>
#include <sstream>
#include <iostream>

ProjectService::ProjectService()
{
    fetchProjectsFromFile();
}

void ProjectService::createProject(const std::string& name)
{
    
    for (const auto& p : projects)
    {
        if (p.getName() == name)
        {
            std::cout << "Project already exists.\n";
            return;
        }
    }

    projects.emplace_back(name);

    std::cout << "Project created: " << name << "\n";
}

Project* ProjectService::findProjectByName(const std::string& name)
{
    for (auto& p : projects)
    {
        if (p.getName() == name)
        {
            return &p;
        }
    }
    return nullptr;
}

void ProjectService::saveProjectToFile(const std::string& name)
{
    //since it is saving a single project we can make dublicates
    //wont bother to search and fix it
    Project* p = findProjectByName(name);

    if (!p)
    {
        std::cout << "Project not found.\n";
        return;
    }

    std::ofstream file(fileName, std::ios::app); 

    if (!file.is_open())
    {
        std::cout << "Cannot open projects file.\n";
        return;
    }

    file << p->getName() << " ";
    file << p->getDescription() << " ";
    file << static_cast<int>(p->getStatus()) << " ";

    // MEMBERS
    auto& members = p->getMembers();
    for (size_t i = 0; i < members.size(); i++)
    {
        file << members[i]->getId();
        if (i + 1 < members.size()) file << ",";
    }
    file << " ";

    // TASKS
    auto& tasks = p->getTasks();
    for (size_t i = 0; i < tasks.size(); i++)
    {
        file << tasks[i]->getId();
        if (i + 1 < tasks.size()) file << ",";
    }
    file << " ";

    // STAGES
    auto& stages = p->getStages();
    for (size_t i = 0; i < stages.size(); i++)
    {
        file << stages[i]->getStageId();   
        if (i + 1 < stages.size()) file << ",";
    }

    file << "\n";
    file.close();
}


void ProjectService::fetchProjectsFromFile()
{
    projects.clear();

    std::ifstream file(fileName);

    if (!file.is_open())
    {
        std::cout << "No projects file found.\n";
        return;
    }

    std::string name;

    while (std::getline(file, name))
    {
        if (!name.empty())
        {
            projects.emplace_back(name);

        }
    }

    file.close();
}

const std::vector<Project>& ProjectService::getProjects() const
{
    return projects;
}
