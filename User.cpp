#include "User.h"
#include "Librarian.h"
#include <algorithm>

// Initialize the static member
vector<User> User::users;

User::User(int _id, string _name, UserType _role) : id(_id), name(_name), role(_role) {}

void User::addUser(UserType role)
{
    int id;
    string name;
    cout << "Enter User Id: ";
    cin >> id;
    cin.ignore();

    for (auto user : users)
    {
        if (user.id == id)
        {
            cout << "User ID already exists" << endl;
            return;
        }
    }

    cout << "Enter User Name: ";
    getline(cin, name);

    User newUser(id, name, role);
    users.push_back(newUser);
}

void User::displayAllUsers()
{
    Librarian library;
    if (library.authenticateLibrarian())
    {
        for (const User &user : users)
        {
            cout << "User Id: " << user.id << ", Name: " << user.name << endl;
        }
    }
    else
    {
        cout << "Authentication failed" << endl;
    }
}

User *User::getUserById(int userId)
{
    for (auto& user : users)
    {
        if (user.id == userId)
        {
            return &user;
        }
    }
    return nullptr;
}

void User::addBorrowedBook(Book *book)
{
    borrowedBooks.push_back(book);
}

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

void User::viewBorrowedBooks() const
{
    if (borrowedBooks.empty())
    {
        cout << "No borrowed books." << endl;
        return;
    }

    cout << "Borrowed Books:" << endl;
    for (const auto &book : borrowedBooks)
    {
        book->display();
    }
}
