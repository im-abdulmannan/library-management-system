#include <iostream>
#include "AppMain.h"
#include "User.h"
#include "Book.h"
#include "Member.h"
#include "Librarian.h"

using namespace std;

void AppMain::mainMenu()
{
    cout << "_____________________Main Menu_____________________" << endl;
    cout << "|\t                                           |" << endl;
    cout << "|\t                                           |" << endl;
    cout << "|\t0. Exit the Program                        |" << endl;
    cout << "|\t1. Create new Member                       |" << endl;
    cout << "|\t2. Add new Book (Librarian)                |" << endl;
    cout << "|\t3. Remove Book (Librarian)                 |" << endl;
    cout << "|\t4. Update Book (Librarian)                 |" << endl;
    cout << "|\t5. Borrow Book (Member)                    |" << endl;
    cout << "|\t6. Return Book (Member)                    |" << endl;
    cout << "|\t7. View Borrowed Books (Member)            |" << endl;
    cout << "|\t8. Search Book (Member)                    |" << endl;
    cout << "|\t9. Display All Users                       |" << endl;
    cout << "|\t10. Display Available Books                |" << endl;
    cout << "|\t                                           |" << endl;
    cout << "|__________________________________________________|" << endl;
}

void AppMain::init()
{
    Member member;
    Librarian librarian;
    Book book;
    while (true)
    {
        mainMenu();
        {
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 0:
                exit(0);
                break;
            case 1:
                member.addMember();
                break;
            case 2:
                librarian.addBook();
                break;
            case 3:
                librarian.removeBook();
                break;
            case 4:
                librarian.updateBook();
                break;
            case 5:
                member.borrowBook();
                break;
            case 6:
                member.returnBook();
                break;
            case 7:
                member.viewBorrowedBooks();
                break;
            case 8:
                member.searchBook();
                break;
            case 9:
                User::displayAllUsers();
                break;
            case 10:
                book.displayAllBooks();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
}