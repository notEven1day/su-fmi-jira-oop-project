#include "TaskService.h"
#include <fstream>
#include <iostream>


TaskService::TaskService() {
    fetchTasksFromFile();
}

std::vector<Task>& TaskService::getTasks() {
    return tasks;
}

const std::vector<Task>& TaskService::getTasks() const {
    return tasks;
}

void TaskService::fetchTasksFromFile() {
    
}


void TaskService::saveTasksToFile() {
    
}

void TaskService::createTask(const std::string& taskName,
    Project* project,
    Type type,
    Priority priority,
    User* maintainer)
{
    Task task(taskName, type, priority, maintainer);

    tasks.push_back(std::move(task)); 
}

Task* TaskService::findTaskById(int id)
{
    for (auto& task : tasks) {
        if (task.getId() == id) {
            return &task;
        }
    }
    return nullptr;
}
