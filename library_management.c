#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int issued;
};

struct Book books[100];
int count = 0;

void addBook() {
    if (count >= 100) {
        printf("\nLibrary is full!\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &books[count].id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", books[count].title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", books[count].author);

    books[count].issued = 0;
    count++;

    printf("\nBook added successfully!\n");
}

void displayBooks() {
    int i;

    if (count == 0) {
        printf("\nNo books available!\n");
        return;
    }

    printf("\n--- Book List ---\n");

    for (i = 0; i < count; i++) {
        printf("\nBook ID: %d\n", books[i].id);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Status: %s\n",
               books[i].issued ? "Issued" : "Available");
    }
}

void searchBook() {
    int id, i, found = 0;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("\nBook Found!\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Status: %s\n",
                   books[i].issued ? "Issued" : "Available");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nBook not found!\n");
    }
}

void issueBook() {
    int id, i;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].issued == 0) {
                books[i].issued = 1;
                printf("\nBook issued successfully!\n");
            } else {
                printf("\nBook is already issued!\n");
            }
            return;
        }
    }

    printf("\nBook not found!\n");
}

void returnBook() {
    int id, i;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].issued == 1) {
                books[i].issued = 0;
                printf("\nBook returned successfully!\n");
            } else {
                printf("\nThis book was not issued!\n");
            }
            return;
        }
    }

    printf("\nBook not found!\n");
}

int main() {
    int choice;

    do {
        printf("\n===== LIBRARY BOOK MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

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
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
