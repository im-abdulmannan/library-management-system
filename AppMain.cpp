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
    cout << "|\t2. Create new Librarian                    |" << endl;
    cout << "|\t3. Add new Book (Librarian)                |" << endl;
    cout << "|\t4. Remove Book (Librarian)                 |" << endl;
    cout << "|\t5. Update Book (Librarian)                 |" << endl;
    cout << "|\t6. Borrow Book (Member)                    |" << endl;
    cout << "|\t7. Return Book (Member)                    |" << endl;
    cout << "|\t8. View Borrowed Books (Member)            |" << endl;
    cout << "|\t9. Search Book (Member)                    |" << endl;
    cout << "|\t10. Display All Users                      |" << endl;
    cout << "|\t11. Display Available Books                |" << endl;
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
                librarian.addLibrarian();
                break;
            case 3:
                librarian.addBook();
                break;
            case 4:
                librarian.removeBook();
                break;
            case 5:
                librarian.updateBook();
                break;
            case 6:
                member.borrowBook();
                break;
            case 7:
                member.returnBook();
                break;
            case 8:
                member.viewBorrowedBooks();
                break;
            // case 9:
            //     searchBook();
            //     break;
            case 10:
                User::displayAllUsers();
                break;
            case 11:
                book.displayAllBooks();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
}