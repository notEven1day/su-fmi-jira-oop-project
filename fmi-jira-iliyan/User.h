#pragma once
#include<iostream>
#include<string>
enum class Role {
	Student,
	TeachingAssistant,
	Lecturer,
	Administrator
};
class User {
	protected:
		int id;
		std::string username;
		std::string password;
		Role role;
		static int ID;

	public:
		User(const std::string& username, const std::string& password, Role role);

		User(int id,
			const std::string& username,
			const std::string& password,
			Role role);

		virtual ~User() = default;

		int getId() const { return id; }
		const std::string& getUsername() const { return username; }
		bool checkPassword(const std::string& pw) const;
		Role getRole() const { return role; }
		std::string getPassword() const { return password;}
	
};


static Role stringToRole(const std::string& r)
{
	if (r == "Student") return Role::Student;
	if (r == "TeachingAssistant") return Role::TeachingAssistant;
	if (r == "Lecturer") return Role::Lecturer;
	return Role::Administrator;
}

static std::string roleToString(Role r)
{
	switch (r)
	{
	case Role::Student: return "Student";
	case Role::TeachingAssistant: return "TeachingAssistant";
	case Role::Lecturer: return "Lecturer";
	case Role::Administrator: return "Administrator";
	}
	return "Student";
}