#pragma once
#include <string>
#include <iostream>
using namespace std;
class Book
{
private:
    int id;
    string title;
    string author;
    string genre;
    bool isAvailable;

    static vector<Book> books;
    bool matchingCriteria(const string &searchTitle, const string &searchAuthor, const string &searchGenre) const;

public:
    Book();
    Book(int _id, string _title, string _author, string _genre);
    void addBook();
    void updateBook(int _id);
    void removeBook(int id);
    vector<Book> getAllBooks();
    static void displayAllAvailableBooks();
    static Book *getBookById(int id);
    void setAvailable(bool _available);
    bool checkIfBookAvailable() const;
    void borrowBook();
    string getTitle();
    void returnBook();
    static vector<Book> searchBooks(const vector<Book> &books, const string &title, const string &author, const string &genre);

    void display() const;
};
