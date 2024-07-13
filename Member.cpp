#include "Member.h"
#include <algorithm>
#include "Book.h"

void Member::addMember()
{
    User::addUser(UserType::MEMBER);
}

void Member::removeMember()
{
    User::removeUser(UserType::MEMBER);
}

void Member::borrowBook()
{
    int id;
    cout << "Enter the book ID you want to borrow: ";
    cin >> id;

    Book *book = Book::getBookById(id);
    bool isBookAvailable = book->checkIfBookAvailable();

    if (isBookAvailable)
    {
        borrowedBooks.push_back(book);
        book->borrowBook();
        cout << "Book borrowed successfully." << endl;
    }
    else
    {
        cout << "Sorry, the book is not available." << endl;
    }
}

void Member::returnBook()
{
    int id;
    cout << "Enter the book ID you want to return: ";
    cin >> id;

    Book *book = Book::getBookById(id);
    auto it = find(borrowedBooks.begin(), borrowedBooks.end(), book);

    if (it!= borrowedBooks.end())
    {
        borrowedBooks.erase(it);
        book->returnBook();
        cout << "Book returned successfully." << endl;
    }
    else
    {
        cout << "You have not borrowed this book." << endl;
    }
}

void Member::viewBorrowedBooks()
{
    if (borrowedBooks.empty())
    {
        cout << "You have not borrowed any books yet." << endl;
        return;
    }

    cout << "Borrowed Books:" << endl;
    for (auto &book : borrowedBooks)
    {
        cout << book->getTitle() << endl;
    }
}
