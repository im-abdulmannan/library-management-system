#pragma once

#include "Book.h"
#include <map>
#include <vector>
using namespace std;

class Member
{
private:
    int id;
    string name;
    string role;

    vector<int> borrowedBooks;
    static map<int, Member> members;

public:
    Member(){};
    Member(int _id, string _name);
    void addMember();
    bool isMemberExist(int id);
    void displayAllMembers();
    Member getMemberById(int id);
    void borrowBook();
    void returnBook();
    void viewBorrowedBooks();
    void searchBook();
};
