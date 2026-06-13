#pragma once
#include<iostream>
#include<vector>

class Command {
public:
    virtual ~Command() = default;
    virtual void execute(const std::vector<std::string>& args) = 0;
    virtual std::string name()  const = 0;
    virtual std::string usage() const = 0;
};