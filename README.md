### 1. Introduction

The Library Management System (LMS) is designed to manage the daily operations of a library. The system will allow librarians to manage the inventory of books and enable members to borrow and return books. This MVP focuses on essential functionalities required for basic library management.

### 2. Objectives

- To provide a system for librarians to manage library inventory.
- To allow members to borrow and return books efficiently.
- To ensure that book borrowing and returning is tracked accurately.

### 3. Scope

The MVP of the Library Management System will include the following features:

#### 3.1 User Roles
1. *Librarian*:
    - Manages book inventory (add, remove, update books).
    - Searches for books in the library.
2. *Member*:
    - Borrows books from the library.
    - Returns books to the library.
    - Views a list of borrowed books.

#### 3.2 Core Functionalities

1. *Book Management (Librarian)*
    - *Add Book*:
        - Input: Book ID, Title, Author, Genre.
        - Action: Adds the book to the library inventory with status set to available.
    - *Remove Book*:
        - Input: Book ID.
        - Action: Removes the book from the library inventory.
    - *Update Book*:
        - Input: Book ID, New Details (Title, Author, Genre).
        - Action: Updates the book details in the library inventory.

2. *Member Services (Member)*
    - *Borrow Book*:
        - Input: Book ID.
        - Action: Changes the book status to borrowed and adds the book to the member's borrowed books list.
    - *Return Book*:
        - Input: Book ID.
        - Action: Changes the book status to available and removes the book from the member's borrowed books list.
    - *View Borrowed Books*:
        - Action: Displays a list of books currently borrowed by the member.

3. *Search Functionality*
    - *Search Book*:
        - Input: Search criteria (Title, Author, Genre).
        - Action: Displays a list of books matching the search criteria.
    - *Display Available Books*:
        - Action: Displays a list of all books that are currently available for borrowing.

### 4. Technical Requirements

- *Programming Language*: C++
- *Object-Oriented Design*: Utilize OOP principles such as classes, inheritance, polymorphism, and encapsulation.