#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include "Task.h"

int Task::TASKID = 0;
Task::Task(const std::string& title, Type type, Priority priority,
    User* maintainer) : id(TASKID++),
    title(title),
    type(type),
    priority(priority),
    status(TaskStatus::ToDo),
    maintainer(maintainer),
    points(0),
    grade(0)
{
}

int Task::getId() const
{
    return id;
}

void Task::print() const{
    std::cout << "----------------------\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "Title: " << title << "\n";
    std::cout << "Description: " << description << "\n";

    std::cout << "Type: ";
    switch (type) {
    case Type::Bug: std::cout << "Bug"; break;
    case Type::Feature: std::cout << "Feature"; break;
    case Type::Task: std::cout << "Task"; break;
    case Type::Improvement: std::cout << "Improvement"; break;
    }
    std::cout << "\n";

    std::cout << "Priority: ";
    switch (priority) {
    case Priority::Low: std::cout << "Low"; break;
    case Priority::Medium: std::cout << "Medium"; break;
    case Priority::High: std::cout << "High"; break;
    case Priority::Critical: std::cout << "Critical"; break;
    }
    std::cout << "\n";

    std::cout << "Status: ";
    switch (status) {
    case TaskStatus::ToDo: std::cout << "ToDo"; break;
    case TaskStatus::InProgress: std::cout << "InProgress"; break;
    case TaskStatus::InReview: std::cout << "InReview"; break;
    case TaskStatus::Done: std::cout << "Done"; break;
    }
    std::cout << "\n";

    std::cout << "Points: " << points << "\n";
    std::cout << "Grade: " << grade << "\n";

    if (maintainer) {
        std::cout << "Maintainer: " << maintainer->getUsername() << "\n";
    }
    else {
        std::cout << "Maintainer: none\n";
    }

    std::cout << "End Date: " << endDate << "\n";
    std::cout << "Comments: " << comments.size() << "\n";
    std::cout << "History: " << history.size() << "\n";

    std::cout << "----------------------\n";
}

TaskStatus Task::getTaskStatus() const
{
    return status;
}

void Task::setTaskStatus(TaskStatus& taskStatus)
{
    status = taskStatus;
}


void Task::addComment(const std::string& content, User* author) {
    std::time_t now = std::time(nullptr);
    std::string date = std::ctime(&now);
    date.pop_back(); 

    comments.push_back(
        std::make_unique<Comment>(
            author,
            content,
            date
        )
    );
}
