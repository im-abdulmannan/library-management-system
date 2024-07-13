#include "Librarian.h"
#include "Book.h"

void Librarian::addLibrarian()
{
    User::addUser(UserType::LIBRARIAN);
}

void Librarian::removeLibrarian()
{
    User::removeUser(UserType::LIBRARIAN);
}

void Librarian::addBook()
{
    Book newBook;
    newBook.addBook();
}

void Librarian::updateBook()
{
    Book book;
    book.updateBook();
}

void Librarian::removeBook()
{
    Book book;
    int id;
    cout << "Book ID you want to remove: ";
    cin >> id;
    book.removeBook(id);
}
