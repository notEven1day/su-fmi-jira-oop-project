#include "Comment.h"

Comment::Comment(User* author, const std::string& content,
	const std::string& date) :author(author), content(content), date(date)
{
}
