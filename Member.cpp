#include "Member.h"

void Member::addMember()
{
    User::addUser(UserType::MEMBER);
}

void Member::removeMember()
{
    User::removeUser(UserType::MEMBER);
}
