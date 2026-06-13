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
		int getId();
};
