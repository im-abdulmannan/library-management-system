#include "User.h"

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

    cout << "Enter User Name: ";
    getline(cin, name);

    User newUser(id, name, role);
    users.push_back(newUser);
}

void User::removeUser(UserType role)
{
    int userId;
    cout << "Enter User Id to remove: ";
    cin >> userId;
}

void User::displayAllUsers()
{
    for (const User &user : users)
    {
        string roleStr = (user.role == UserType::LIBRARIAN) ? "LIBRARIAN" : "MEMBER";
        cout << "User Id: " << user.id << ", Name: " << user.name << ", Role: " << roleStr << endl;
    }
}

User *User::getUserById(int userId)
{
    for (User &user : users)
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
