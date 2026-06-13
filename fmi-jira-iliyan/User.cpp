#include "User.h"

int User::ID = 0;

User::User(const std::string& username,
    const std::string& password,
    Role role)
    : id(ID++), username(username), password(password), role(role) {
}


User::User(int id,
    const std::string& username,
    const std::string& password,
    Role role)
    : id(id), username(username), password(password), role(role)
{
    if (id >= ID)
        ID = id + 1;
}

bool User::checkPassword(const std::string& pw) const
{
    return password == pw;
}

