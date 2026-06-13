#pragma once
#pragma once
#include <vector>
#include <string>
#include "Task.h"
#include "Project.h"

class TaskService {
private:
    std::vector<Task> tasks;
    std::string fileName = "tasks.txt";

public:
    TaskService();

    std::vector<Task>& getTasks();
    const std::vector<Task>& getTasks() const;

    void fetchTasksFromFile();
    void saveTasksToFile();
    void createTask(const std::string& taskName,
        Project* project,
        Type type,
        Priority priority,
        User* maintainer);
    Task* findTaskById(int id);
};