#pragma once
#include<iostream>
#include <memory>
#include<string>
#include<vector>
#include "Task.h"

enum class StageStatus {
	Planned,
	Active,
	Finished
};

class Stage {
private:
	int id;
	std::string name;
	std::string startDate;
	std::string endDate;
	std::vector<std::unique_ptr<Task>> tasks;
	StageStatus status;
public:
	int getStageId();
	Stage(int id, const std::string& name);
	std::string& getStageName();
	StageStatus getStageStatus() const;
	std::vector<std::unique_ptr<Task>>& getStageTasks();
	void setStartDate(const std::string& date);
	void setStageStatus(StageStatus s);
	void setEndDate(const std::string& date);
};