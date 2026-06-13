#pragma once
#include "User.h"

class UserHolder {
private:
    User* currentUser = nullptr;

public:
    void set(User* user) { currentUser = user; }
    User* get() const { return currentUser; }

    bool isLoggedIn() const { return currentUser != nullptr; }
    void clear() { currentUser = nullptr; }
};