#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "Book.h"
using namespace std;

// Initialize the static member
vector<Book> Book::books;

Book::Book(int _id, string _title, string _author, string _genre)
{
    id = _id;
    title = _title;
    author = _author;
    genre = _genre;
    isAvailable = true;
}

bool Book::matchingCriteria(const string &searchTitle, const string &searchAuthor, const string &searchGenre) const
{
    return (searchTitle.empty() || title.find(searchTitle) != string::npos) &&
           (searchAuthor.empty() || author.find(searchAuthor) != string::npos) &&
           (searchGenre.empty() || genre.find(searchGenre) != string::npos);
}

Book::Book() : id(0), title(""), author(""), genre("") {}

void Book::addBook()
{
    int id;
    string title, author, genre;

    cout << "Enter book ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);
    cout << "Enter book genre: ";
    getline(cin, genre);

    books.push_back(Book(id, title, author, genre));
}

void Book::updateBook(int _id)
{
    for (auto &book : books)
    {
        if (book.id == _id)
        {
            cout << "Enter updated book title: ";
            cin.ignore();
            getline(cin, book.title);
            cout << "Enter updated book author: ";
            getline(cin, book.author);
            cout << "Enter updated book genre: ";
            getline(cin, book.genre);
            break;
        }
    }
}

void Book::removeBook(int id)
{
    books.erase(remove_if(books.begin(), books.end(), [id](const Book &book)
                          { return book.id == id; }),
                books.end());
}

vector<Book> Book::getAllBooks()
{
    return books;
}

void Book::displayAllBooks()
{
    for (const Book &book : books)
    {
        if (book.isAvailable)
        {
            book.display();
        }
    }
}

Book *Book::getBookById(int id)
{
    for (Book &book : books)
    {
        if (book.id == id)
            return &book;
    }
    return nullptr;
}

void Book::setAvailable(bool _available)
{
    isAvailable = _available;
}

bool Book::checkIfBookAvailable() const
{
    return isAvailable;
}

void Book::borrowBook()
{
    isAvailable = false;
}

string Book::getTitle()
{
    return title;
}

void Book::returnBook()
{
    isAvailable = true;
}

vector<Book> Book::searchBooks(const vector<Book> &books, const string &title, const string &author, const string &genre)
{
    vector<Book> result;
    for (const auto &book : books)
    {
        if (book.matchingCriteria(title, author, genre))
        {
            result.push_back(book);
        }
    }
    return result;
}
