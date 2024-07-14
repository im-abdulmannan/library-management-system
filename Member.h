#pragma once

#include "User.h"
#include "Book.h"
#include <vector>
using namespace std;

class Member
{
private:
    // vector<Book*> borrowedBooks;

public:
    void addMember();
    void removeMember();
    void borrowBook();
    void returnBook();
    void viewBorrowedBooks();
    void searchBook();
};
