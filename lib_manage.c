#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 50

struct Book {
    int id;
    char title[100];
    char author[60];
    int status;              // 0 = available, 1 = issued
    char student[60];
};

struct Book books[MAX_BOOKS];
int bookCount = 0;

int readInt(const char prompt[]) {
    char line[100];
    int value;

    while (1) {
        printf("%s", prompt);
        if (fgets(line, sizeof(line), stdin) != NULL &&
            sscanf(line, "%d", &value) == 1) {
            return value;
        }
        printf("Please enter a valid number.\n");
    }
}

void readText(const char prompt[], char text[], int size) {
    printf("%s", prompt);
    if (fgets(text, size, stdin) != NULL) {
        text[strcspn(text, "\n")] = '\0';
    }
}

int findBook(int id) {
    int i;
    for (i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addBook(void) {
    int id;

    if (bookCount >= MAX_BOOKS) {
        printf("Library storage is full.\n");
        return;
    }

    id = readInt("Enter Book ID: ");
    if (findBook(id) != -1) {
        printf("This Book ID already exists.\n");
        return;
    }

    books[bookCount].id = id;
    readText("Enter book title: ", books[bookCount].title,
             sizeof(books[bookCount].title));
    readText("Enter author name: ", books[bookCount].author,
             sizeof(books[bookCount].author));
    books[bookCount].status = 0;
    books[bookCount].student[0] = '\0';

    bookCount++;
    printf("Book added successfully!\n");
}

void displayBooks(void) {
    int i;

    if (bookCount == 0) {
        printf("No books have been added yet.\n");
        return;
    }

    printf("\n--- All Library Books ---\n");
    for (i = 0; i < bookCount; i++) {
        printf("\nBook ID: %d\n", books[i].id);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Status: %s\n",
               books[i].status == 0 ? "Available" : "Issued");
        if (books[i].status == 1) {
            printf("Issued to: %s\n", books[i].student);
        }
    }
}

void searchBook(void) {
    int id, index;

    id = readInt("Enter Book ID to search: ");
    index = findBook(id);

    if (index == -1) {
        printf("Book not found.\n");
    } else {
        printf("\nBook found!\n");
        printf("ID: %d\n", books[index].id);
        printf("Title: %s\n", books[index].title);
        printf("Author: %s\n", books[index].author);
        printf("Status: %s\n",
               books[index].status == 0 ? "Available" : "Issued");
        if (books[index].status == 1) {
            printf("Issued to: %s\n", books[index].student);
        }
    }
}

void issueBook(void) {
    int id, index;

    id = readInt("Enter Book ID to issue: ");
    index = findBook(id);

    if (index == -1) {
        printf("Book not found.\n");
    } else if (books[index].status == 1) {
        printf("This book is already issued.\n");
    } else {
        readText("Enter student name: ", books[index].student,
                 sizeof(books[index].student));
        books[index].status = 1;
        printf("Book issued successfully to %s.\n",
               books[index].student);
    }
}

void returnBook(void) {
    int id, index;

    id = readInt("Enter Book ID to return: ");
    index = findBook(id);

    if (index == -1) {
        printf("Book not found.\n");
    } else if (books[index].status == 0) {
        printf("This book was not issued.\n");
    } else {
        books[index].status = 0;
        books[index].student[0] = '\0';
        printf("Book returned successfully!\n");
    }
}

void viewIssuedBooks(void) {
    int i, found = 0;

    printf("\n--- Currently Issued Books ---\n");
    for (i = 0; i < bookCount; i++) {
        if (books[i].status == 1) {
            printf("\nBook ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Issued to: %s\n", books[i].student);
            found = 1;
        }
    }

    if (!found) {
        printf("No books are currently issued.\n");
    }
}

int main(void) {
    int choice;

    do {
        printf("\n===== STUDENT LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. View Issued Books\n");
        printf("7. Exit\n");

        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                viewIssuedBooks();
                break;
            case 7:
                printf("Thank you for using the Library System!\n");
                break;
            default:
                printf("Invalid choice. Please choose 1 to 7.\n");
        }
    } while (choice != 7);

    return 0;
}
