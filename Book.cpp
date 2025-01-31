#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "Book.h"
using namespace std;

// Initialize the static member
vector<Book> Book::books;

Book::Book() : id(0), title(""), author(""), genre("") {}

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

void Book::addBook()
{
    int id;
    string title, author, genre;

    cout << "Enter book ID: ";
    cin >> id;
    cin.ignore();

    for (Book &book : books)
    {
        if (book.id == id)
        {
            cout << "Book ID already exists" << endl;
            return;
        }
    }

    cout << "Enter book title: ";
    getline(cin, title);

    for (Book &book : books)
    {
        if (book.title == title)
        {
            cout << "Book with the same Title is already exists" << endl;
            return;
        }
    }

    cout << "Enter book author: ";
    getline(cin, author);
    cout << "Enter book genre: ";
    getline(cin, genre);

    books.push_back(Book(id, title, author, genre));
    cout << "Book Added Successfully" << endl;
}

void Book::updateBook(int _id)
{
    auto it = find_if(books.begin(), books.end(), [_id](const Book &book)
                      { return book.id == _id; });
    if (it != books.end())
    {
        if (it->checkIfBookAvailable())
        {
            cout << "Enter updated book title: ";
            cin.ignore();
            getline(cin, it->title);
            cout << "Enter updated book author: ";
            getline(cin, it->author);
            cout << "Enter updated book genre: ";
            getline(cin, it->genre);
        }
        else
        {
            cout << "Book is currently borrowed, cannot update." << endl;
            return;
        }
    }
}

void Book::removeBook(int id)
{

    auto it = find_if(books.begin(), books.end(), [id](const Book &book)
                      { return book.id == id; });

    if (it != books.end())
    {
        if (it->checkIfBookAvailable())
        {
            books.erase(it);
            cout << "Book removed successfully" << endl;
        }
        else
        {
            cout << "Book is currently borrowed, cannot remove." << endl;
        }
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

vector<Book> Book::getAllBooks()
{
    return books;
}

void Book::displayAllAvailableBooks()
{
    for (const Book &book : books)
    {
        if (book.checkIfBookAvailable())
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

vector<Book> Book::searchBooks(const string &title, const string &author, const string &genre)
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

void Book::display() const
{
    cout << "ID: " << id << ", Title: " << title << ", Author: " << author << ", Genre: " << genre << endl;
}
