#include "User.h"
#include "Librarian.h"
#include <algorithm>

// Initialize the static member
vector<User> User::users;

User::User(int _id, string _name, UserType _role) : id(_id), name(_name), role(_role) {}

void User::returnBorrowedBook(Book *book)
{
    auto it = find(borrowedBooks.begin(), borrowedBooks.end(), book);
    if (it != borrowedBooks.end())
    {
        borrowedBooks.erase(it);
    }
    else
    {
        cout << "Book not found in borrowed books." << endl;
    }
}
