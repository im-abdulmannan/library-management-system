#pragma once
#include <string>
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

public:
    Book();
    Book(int _id, string _title, string _author, string _genre);
    void addBook();
    void updateBook();
    void removeBook(int id);
    static void displayAllBooks();
};
