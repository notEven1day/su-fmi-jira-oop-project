#pragma once
#include "Stage.h"
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>

class StageService {
private:
    std::vector<std::unique_ptr<Stage>> stages;
    int nextId = 1;

public:
    Stage& createStage(const std::string& name) {
        for (const auto& s : stages)
            if (s->getStageName() == name)
                throw std::runtime_error("Stage with name '" + name + "' already exists.");

        stages.push_back(std::make_unique<Stage>(nextId++, name));
        return *stages.back();
    }

    Stage& findStageByName(const std::string& name) {
        for (const auto& s : stages)
            if (s->getStageName() == name)
                return *s;

        throw std::runtime_error("Stage '" + name + "' not found.");
    }
};