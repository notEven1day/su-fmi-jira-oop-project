#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "User.h"
#include "Comment.h"

enum class Type {
	Bug,
	Feature, 
	Task, 
	Improvement
};

enum class Priority {
	Low, 
	Medium, 
	High,
	Critical
};

enum class TaskStatus {
	ToDo, 
	InProgress, 
	InReview, 
	Done
};

class Change {
	private:
		User* changedBy;
		std::string timestamp;

		std::string fieldChanged;
		std::string oldValue;
		std::string newValue;
	public:
		Change(User* changedBy, const std::string& timestamp, const std::string& fieldChanged, const std::string& oldValue, const std::string& newValue);

};
class Task {
	private:
		static int TASKID;
		int id;
		std::string title;
		std::string description;
		Type type;
		Priority priority;
		TaskStatus status;
		std::shared_ptr<User> maintainer;
		std::string endDate;
		double points;
		double grade;
		std::vector<std::unique_ptr<Comment>> comments;
		std::vector<std::unique_ptr<Change>> history;
	public:
		Task(const std::string& title,
			Type type,
			Priority priority,
			User* maintainer);
		int getId() const;
		void print() const;
		TaskStatus getTaskStatus() const;
		void setTaskStatus(TaskStatus& taskStatus);
		void addComment(const std::string& content, User* author);
};




static Type typeFromString(const std::string& s) {
	if (s == "Bug") return Type::Bug;
	if (s == "Feature") return Type::Feature;
	if (s == "Task") return Type::Task;
	return Type::Improvement;
}

static std::string typeToString(Type t) {
	switch (t) {
	case Type::Bug: return "Bug";
	case Type::Feature: return "Feature";
	case Type::Task: return "Task";
	case Type::Improvement: return "Improvement";
	}
	return "Improvement";
}



static Priority priorityFromString(const std::string& s) {
	if (s == "Low") return Priority::Low;
	if (s == "Medium") return Priority::Medium;
	if (s == "High") return Priority::High;
	return Priority::Critical;
}

static std::string priorityToString(Priority p) {
	switch (p) {
	case Priority::Low: return "Low";
	case Priority::Medium: return "Medium";
	case Priority::High: return "High";
	case Priority::Critical: return "Critical";
	}
	return "Low";
}

static TaskStatus taskStatusFromString(const std::string& s) {
	if (s == "ToDo") return TaskStatus::ToDo;
	if (s == "InProgress") return TaskStatus::InProgress;
	if (s == "InReview") return TaskStatus::InReview;
	return TaskStatus::Done;
}

static std::string taskStatusToString(TaskStatus status) {
	switch (status) {
	case TaskStatus::ToDo: return "ToDo";
	case TaskStatus::InProgress: return "InProgress";
	case TaskStatus::InReview: return "InReview";
	case TaskStatus::Done: return "Done";
	}
	return "ToDo";
}
