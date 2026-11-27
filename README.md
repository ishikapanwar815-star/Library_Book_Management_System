# Student Library Management System

A beginner-friendly, menu-driven Library Management System written in C. The program is intended to demonstrate basic library tasks such as adding books, displaying records, searching by book ID, issuing books to students, returning books, and viewing issued records.

## Features
- Add books to the system
- Display book records
- Search for a book by ID
- Issue a book to a student
- Return an issued book
- View issued-book records
- Handle invalid menu choices
- Check for duplicate book IDs (if implemented in the submitted code)

## Technology Used
- C programming language
- GCC / MinGW compiler
- Visual Studio Code

## Concepts Demonstrated
- Structures
- Arrays
- Functions
- Loops
- Conditional statements and `switch`
- Strings
- File handling (if enabled in the code)

## How to Compile and Run (Windows / MinGW)
1. Open the project folder in VS Code.
2. Open Terminal.
3. Compile the C source file (replace the filename if yours differs):
   ```bash
   gcc student_library_system.c -o library.exe
   ```
4. Run the program:
   ```bash
   .\library.exe
   ```

## Basic Testing Checklist
- Add two books with different IDs.
- Display all books and confirm both records appear.
- Search for an existing ID and a non-existing ID.
- Issue a book and check that its status changes.
- Try issuing an already-issued book.
- View issued books.
- Return the book and confirm the status changes back.
- Try a duplicate book ID and an invalid menu choice.

## Project Contents
- `student_library_system.c` — C source code (add your final code here)
- `README.md` — project documentation
- `Project_Screenshots/` — place screenshots showing menu, added books, issue, and return outputs here

## Limitations
This is a basic student project. Features and record persistence depend on the implementation in the C source file. It is not intended as a production library system.


## Future Scope
- Student registration and login
- Book categories and filtering
- Due dates and fine calculation
- Improved record management and interface
- Administrator login and access control

## Team
Ishika Panwar and Kriti Agarwal
