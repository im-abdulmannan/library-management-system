#include "Member.h"
#include <algorithm>
#include "Book.h"
#include "User.h"

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
    int userId;
    cout << "Enter your user ID: ";
    cin >> userId;

    User *user = User::getUserById(userId);
    if (!user)
    {
        cout << "User not found." << endl;
        return;
    }

    int bookId;
    cout << "Enter the book ID you want to borrow: ";
    cin >> bookId;
    Book *book = Book::getBookById(bookId);
    if (!book)
    {
        cout << "Book not found." << endl;
        return;
    }

    bool isBookAvailable = book->checkIfBookAvailable();
    if (isBookAvailable)
    {
        user->addBorrowedBook(book);
        book->borrowBook();
        cout << "Book borrowed successfully." << endl;
    }
    else
    {
        cout << "Sorry, the book is not available." << endl;
    }
}

void Member::returnBook() {
    int userId;
    cout << "Enter your user ID: ";
    cin >> userId;

    User* user = User::getUserById(userId);
    if (!user) {
        cout << "User not found." << endl;
        return;
    }

    int bookId;
    cout << "Enter the book ID you want to return: ";
    cin >> bookId;

    Book* book = Book::getBookById(bookId);
    if (!book) {
        cout << "Book not found." << endl;
        return;
    }

    auto it = find(user->borrowedBooks.begin(), user->borrowedBooks.end(), book);
    if (it != user->borrowedBooks.end()) {
        user->borrowedBooks.erase(it);
        book->returnBook();
        cout << "Book returned successfully." << endl;
    } else {
        cout << "You have not borrowed this book." << endl;
    }
}

void Member::viewBorrowedBooks()
{

    int userId;
    cout << "Enter your user ID: ";
    cin >> userId;

    User *user = User::getUserById(userId);
    if (!user)
    {
        cout << "User not found." << endl;
        return;
    }
    
    user->viewBorrowedBooks();
}

void Member::searchBook()
{
    Book book;
    vector<Book> library = book.getAllBooks();

    string searchTitle, searchAuthor, searchGenre;
    cin.ignore();
    cout << "Enter title to search (or leave empty): ";
    getline(cin, searchTitle);
    cout << "Enter author to search (or leave empty): ";
    getline(cin, searchAuthor);
    cout << "Enter genre to search (or leave empty): ";
    getline(cin, searchGenre);

    vector<Book> matchingBooks = Book::searchBooks(library, searchTitle, searchAuthor, searchGenre);

    cout << "Search Result: " << matchingBooks.size() << endl;
    for (const Book &book : matchingBooks)
    {
        book.display();
    }
}
