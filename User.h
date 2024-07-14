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
    vector<Book*> borrowedBooks;

    static vector<User> users;

public:
    User(int _id, string _name, UserType _role);
    static void addUser(UserType role);
    static void removeUser(UserType role);
    static void displayAllUsers();
    static User *getUserById(int userId);
    void addBorrowedBook(Book* book);
    void viewBorrowedBooks() const;

    int getId()
    {
        return id;
    }

    friend class Member;
};
