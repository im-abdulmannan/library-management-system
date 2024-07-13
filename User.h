#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum class UserType
{
    LIBRARIAN,
    MEMBER
};

class User
{
private:
    int id;
    string name;
    UserType role;

    static vector<User> users;

public:
    User(int _id, string _name, UserType _role);
    static void addUser(UserType role);
    static void removeUser(UserType role);
    static void displayAllUsers();
};
