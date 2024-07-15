#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Book.h"
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
    vector<Book *> borrowedBooks;

    static vector<User> users;

public:
    User(int _id, string _name, UserType _role);
    void returnBorrowedBook(Book *book);
};
