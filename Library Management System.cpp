#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
};

int main() {
    struct Book books[100];
    int count = 0, choice, id, i, found;

    while (1) {
        printf("\n====== Library Menu ======\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Book ID: ");
                scanf("%d", &books[count].id);
                getchar();  // clear input buffer
                printf("Enter Book Title: ");
                fgets(books[count].title, 50, stdin);
                printf("Enter Author Name: ");
                fgets(books[count].author, 50, stdin);
                count++;
                printf("Book added successfully!\n");
                break;

            case 2:
                printf("\n--- Book List ---\n");
                for (i = 0; i < count; i++) {
                    printf("ID: %d\nTitle: %sAuthor: %s\n", books[i].id, books[i].title, books[i].author);
                }
                if (count == 0) {
                    printf("No books available.\n");
                }
                break;

            case 3:
                printf("\nEnter Book ID to search: ");
                scanf("%d", &id);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (books[i].id == id) {
                        printf("Book Found:\nID: %d\nTitle: %sAuthor: %s\n", books[i].id, books[i].title, books[i].author);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Book not found.\n");
                }
                break;

            case 4:
                printf("Exiting program. Thank you!\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
