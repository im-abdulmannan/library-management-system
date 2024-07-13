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
    cout << "|\t2. Remove Member                           |" << endl;
    cout << "|\t3. Create new Librarian                    |" << endl;
    cout << "|\t4. Remove Librarian                        |" << endl;
    cout << "|\t5. Add Book (Librarian)                    |" << endl;
    cout << "|\t6. Remove Book (Librarian)                 |" << endl;
    cout << "|\t7. Update Book (Librarian)                 |" << endl;
    cout << "|\t8. Borrow Book (Member)                    |" << endl;
    cout << "|\t9. Return Book (Member)                    |" << endl;
    cout << "|\t10. View Borrowed Books (Member)           |" << endl;
    cout << "|\t11. Search Book (Member)                   |" << endl;
    cout << "|\t12. Display All Users                      |" << endl;
    cout << "|\t13. Display Available Books                |" << endl;
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
                member.removeMember();
                break;
            case 3:
                librarian.addLibrarian();
                break;
            case 4:
                librarian.removeLibrarian();
                break;
            case 5:
                librarian.addBook();
                break;
            case 6:
                librarian.removeBook();
                break;
            case 7:
                librarian.updateBook();
                break;
            // case 8:
            //     borrowBook();
            //     break;
            // case 9:
            //     returnBook();
            //     break;
            // case 10:
            //     viewBorrowedBooks();
            //     break;
            // case 11:
            //     searchBook();
            //     break;
            case 12:
                User::displayAllUsers();
                break;
            case 13:
                book.displayAllBooks();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
}