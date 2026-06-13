#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Stage.h"
#include "User.h"
#include "Task.h"


enum class ProjectStatus {
    Active,
    Finished
};

class Project {
private:
    std::string name;
    std::string description;

    std::vector<std::shared_ptr<User>> members;  
    std::vector<std::unique_ptr<Task>> tasks;
    std::vector<std::unique_ptr<Stage>> stages;

    ProjectStatus status;

public:
   /* Project(Project&&) = default;
    Project& operator=(Project&&) = default;
    Project(const Project&) = delete;
    Project& operator=(const Project&) = delete;*/

    Project(const std::string& name);
    const std::string& getName() const;
    const std::string& getDescription() const;
    const std::vector<std::shared_ptr<User>>& getMembers() const;
    const std::vector<std::unique_ptr<Task>>& getTasks() const;
    const std::vector<std::unique_ptr<Stage>>& getStages() const;
    const ProjectStatus& getStatus() const;
    void addMember(std::shared_ptr<User> user);
    void addTask(std::unique_ptr<Task> task);
};