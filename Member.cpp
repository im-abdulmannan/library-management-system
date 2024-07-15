#include "Member.h"
#include <algorithm>
#include "Book.h"

map<int, Member> Member::members;

Member::Member(int _id, string _name)
{
    id = _id;
    name = _name;
    role = "Member";
    vector<int> borrowedBooks(0);
}

void Member::addMember()
{
    cout << "\n\n==========Creating Member==========" << endl;
    int id;
    string name;
    cout << "Enter member id: ";
    cin >> id;
    cin.ignore();

    if (isMemberExist(id))
    {
        cout << "Member with ID " << id << " is already exist" << endl;
        return;
    }

    cout << "Enter name: ";
    getline(cin, name);

    members[id] = Member(id, name);
    cout << "Member added successfully!" << endl;
}

bool Member::isMemberExist(int id)
{
    return members.find(id) != members.end();
}

void Member::displayAllMembers()
{
    cout << "\n\n==========Display All Members==========" << endl;
    for (auto member : members)
    {
        cout << "ID: " << member.first << ", Name: " << member.second.name << ", Role: " << member.second.role << endl;
    }
}

Member Member::getMemberById(int id)
{
    if (members.count(id))
    {
        return members[id];
    }
    return Member();
}

void Member::borrowBook()
{
    int memberId;
    cout << "Enter your user ID: ";
    cin >> memberId;

    if (!isMemberExist(memberId))
    {
        cout << "Member not found!!!" << endl;
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

    if (book->checkIfBookAvailable())
    {
        members[memberId].borrowedBooks.push_back(bookId);
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
    int memberId;
    cout << "Enter your user ID: ";
    cin >> memberId;

    if (!isMemberExist(memberId))
    {
        cout << "Member not found!!!" << endl;
        return;
    }

    Member &member = members[memberId];
    if (member.borrowedBooks.empty())
    {
        cout << "You have not borrowed any books yet." << endl;
        return;
    }

    int bookId;
    cout << "Enter the book ID you want to return: ";
    cin >> bookId;

    Book *book = Book::getBookById(bookId);
    if (!book)
    {
        cout << "Book not found." << endl;
        return;
    }

    auto it = find(member.borrowedBooks.begin(), member.borrowedBooks.end(), bookId);
    if (it != member.borrowedBooks.end())
    {
        member.borrowedBooks.erase(it);
        book->returnBook();
        cout << "Book returned successfully!!!" << endl;
    }
    else
    {
        cout << "Book not found in borrowed books." << endl;
    }
}

void Member::viewBorrowedBooks()
{
    int memberId;
    cout << "Enter your user ID: ";
    cin >> memberId;

    if (!isMemberExist(memberId))
    {
        cout << "Member not found!!!" << endl;
        return;
    }

    Member &member = members[memberId];

    if (member.borrowedBooks.empty())
    {
        cout << "You have not borrowed any books yet." << endl;
        return;
    }

    cout << "\n\n==========Borrowed Books==========" << endl;
    for (int bookId : member.borrowedBooks)
    {
        Book *book = Book::getBookById(bookId);
        if (book)
        {
            book->display();
        }
    }
}

void Member::searchBook()
{
    string searchTitle, searchAuthor, searchGenre;
    cin.ignore();
    cout << "Enter title to search (or leave empty): ";
    getline(cin, searchTitle);
    cout << "Enter author to search (or leave empty): ";
    getline(cin, searchAuthor);
    cout << "Enter genre to search (or leave empty): ";
    getline(cin, searchGenre);

    vector<Book> matchingBooks = Book::searchBooks(searchTitle, searchAuthor, searchGenre);

    cout << "Search Result: " << matchingBooks.size() << endl;
    for (const Book &book : matchingBooks)
    {
        book.display();
    }
}
