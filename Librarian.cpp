#include "Librarian.h"
#include "Book.h"

bool Librarian::authenticateLibrarian()
{
    string _password;
    cout << "Enter password: ";
    cin >> _password;

    return password == _password;
}

void Librarian::addBook()
{
    if (authenticateLibrarian())
    {
        Book newBook;
        newBook.addBook();
    }
    else
    {
        cout << "Authentication failed" << endl;
    }
}

void Librarian::updateBook()
{
    if (authenticateLibrarian())
    {
        Book book;
        int id;
        cout << "Book ID you want to update: ";
        cin >> id;
        book.updateBook(id);
    }
    else
    {
        cout << "Authentication failed" << endl;
    }
}

void Librarian::removeBook()
{
    if (authenticateLibrarian())
    {
        Book book;
        int id;
        cout << "Book ID you want to remove: ";
        cin >> id;
        book.removeBook(id);
    }
    else
    {
        cout << "Authentication failed" << endl;
    }
}
