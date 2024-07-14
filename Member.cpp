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
    else
    {
        int bookId;
        cout << "Enter the book ID you want to borrow: ";
        cin >> bookId;

        Book *book = Book::getBookById(bookId);
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
}

void Member::returnBook()
{
    int id;
    cout << "Enter the book ID you want to return: ";
    cin >> id;

    Book *book = Book::getBookById(id);
    auto it = find(borrowedBooks.begin(), borrowedBooks.end(), book);

    if (it != borrowedBooks.end())
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

    int userId;
    cout << "Enter your user ID: ";
    cin >> userId;

    User *user = User::getUserById(userId);
    if (!user)
    {
        cout << "User not found." << endl;
        return;
    }
    else
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
