#pragma once
#include <vector>
#include <string>
#include "Project.h"

class User;

class ProjectService {
private:
    std::vector<Project> projects;
    std::string fileName = "projects.txt";

public:
    ProjectService();
    void createProject(const std::string& name);
    void saveProjectToFile(const std::string& name);
    Project* findProjectByName(const std::string& name);
    void fetchProjectsFromFile();
    const std::vector<Project>& getProjects() const;
};
