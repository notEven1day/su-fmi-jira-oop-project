#pragma once
#include<iostream>
#include "User.h"

class Student : public User {
public:
    Student(int id, const std::string& username, const std::string& password);

private:
    int totalPoints = 0;
};