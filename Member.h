#pragma once

#include "User.h"
#include "Book.h"
#include <vector>
using namespace std;

class Member
{
public:
    void addMember();
    void borrowBook();
    void returnBook();
    void viewBorrowedBooks();
    void searchBook();
};
