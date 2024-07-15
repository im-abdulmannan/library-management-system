#pragma once

#include <string>
#include <iostream>
#include <vector>
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
    /// @brief Searches for books based on the specified criteria: title, author, or genre.
    /// @param title Partial or complete title of the book to search for. Pass an empty string to ignore this criterion.
    /// @param author Partial or complete author name of the book to search for. Pass an empty string to ignore this criterion.
    /// @param genre Partial or complete genre of the book to search for. Pass an empty string to ignore this criterion.
    /// @return A vector containing the details of books that match the specified search criteria.
    static vector<Book> searchBooks(const string &title, const string &author, const string &genre);

    void display() const;
};
