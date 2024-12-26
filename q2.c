// Q2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    int id;
    char title[50];
    char author[50];
    struct book *next;
} *head = NULL, *temp, *newnode, *prenode;

void addBook();
void displayBooks();
void removeBookById();
void removeBookByTitle();
void searchBookById();
void searchBookByTitle();
void countBooks();

void addBook() {
    newnode = (struct book*)malloc(sizeof(struct book));
    printf("\nEnter Book ID: ");
    scanf("%d", &newnode->id);
    getchar(); // Consume the newline character left by scanf

    printf("Enter Book Title: ");
    scanf("%[^\n]", newnode->title); // Read the full line including spaces until newline
    getchar(); // Consume the newline character left by scanf

    printf("Enter Book Author: ");
    scanf("%[^\n]", newnode->author); // Read the full line including spaces until newline
    getchar(); // Consume the newline character left by scanf

    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("\nBook added successfully!\n");
}

void displayBooks() {
    if (head == NULL) {
        printf("\nNo books available.\n");
    } else {
        printf("\nBooks available:\n");
        temp = head;
        while (temp != NULL) {
            printf("ID: %d, Title: %s, Author: %s\n", temp->id, temp->title, temp->author);
            temp = temp->next;
        }
    }
}

void removeBookById() {
    int id;
    if (head == NULL) {
        printf("\nNo books to remove.\n");
        return;
    }
    printf("\nEnter Book ID to remove: ");
    scanf("%d", &id);
    getchar(); // Consume the newline character left by scanf

    temp = head;
    prenode = NULL;

    while (temp != NULL) {
        if (temp->id == id) {
            if (temp == head) {
                head = head->next;
            } else {
                prenode->next = temp->next;
            }
            free(temp);
            printf("\nBook removed successfully!\n");
            return;
        }
        prenode = temp;
        temp = temp->next;
    }
    printf("\nBook with ID %d not found.\n", id);
}

void removeBookByTitle() {
    char title[50];
    if (head == NULL) {
        printf("\nNo books to remove.\n");
        return;
    }
    printf("\nEnter Book Title to remove: ");
    scanf("%[^\n]", title);

    temp = head;
    prenode = NULL;

    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) { // Compare the titles
            if (temp == head) {
                head = head->next;
            } else {
                prenode->next = temp->next;
            }
            free(temp);
            printf("\nBook with title '%s' removed successfully!\n", title);
            return;
        }
        prenode = temp;
        temp = temp->next;
    }
    printf("\nBook with title '%s' not found.\n", title);
}

void searchBookById() {
    int id;
    if (head == NULL) {
        printf("\nNo books available to search.\n");
        return;
    }
    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);
    getchar(); // Consume the newline character left by scanf

    temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("\nBook found: ID: %d, Title: %s, Author: %s\n", temp->id, temp->title, temp->author);
            return;
        }
        temp = temp->next;
    }
    printf("\nBook with ID %d not found.\n", id);
}

void searchBookByTitle() {
    char title[50];
    if (head == NULL) {
        printf("\nNo books available to search.\n");
        return;
    }
    printf("\nEnter Book Title to search: ");
    scanf("%[^\n]", title);

    temp = head;
    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) { // Compare the titles
            printf("\nBook found: ID: %d, Title: %s, Author: %s\n", temp->id, temp->title, temp->author);
            return;
        }
        temp = temp->next;
    }
    printf("\nBook with title '%s' not found.\n", title);
}

void countBooks() {
    int count = 0;
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("\nTotal number of books: %d\n", count);
}

int main() {
    int choice;
    while (1) {
        printf("\n\nMenu:\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Remove Book by ID\n");
        printf("4. Search Book by ID\n");
        printf("5. Count Books\n");
        printf("6. Remove Book by Title\n");
        printf("7. Search Book by Title\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume the newline character left by scanf

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                removeBookById();
                break;
            case 4:
                searchBookById();
                break;
            case 5:
                countBooks();
                break;
            case 6:
                removeBookByTitle();
                break;
            case 7:
                searchBookByTitle();
                break;
            case 8:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}


/*

OUTPUT::

Menu:
1. Add Book
2. Display Books
3. Remove Book by ID
4. Search Book by ID
5. Count Books
6. Remove Book by Title
7. Search Book by Title
8. Exit
Enter your choice: 1

Enter Book ID: 11
Enter Book Title: Sweet Heart
Enter Book Author: G R Mali

Book added successfully!


Menu:
1. Add Book
2. Display Books
3. Remove Book by ID
4. Search Book by ID
5. Count Books
6. Remove Book by Title
7. Search Book by Title
8. Exit
Enter your choice: 2

Books available:
ID: 11, Title: Sweet Heart, Author: G R Mali


Menu:
1. Add Book
2. Display Books
3. Remove Book by ID
4. Search Book by ID
5. Count Books
6. Remove Book by Title
7. Search Book by Title
8. Exit
Enter your choice: 1

Enter Book ID: 22
Enter Book Title: My Life
Enter Book Author: M D Mahajan

Book added successfully!


Menu:
1. Add Book
2. Display Books
3. Remove Book by ID
4. Search Book by ID
5. Count Books
6. Remove Book by Title
7. Search Book by Title
8. Exit
Enter your choice: 1

Enter Book ID: 55
Enter Book Title: Mera Laal
Enter Book Author: G Mali

Book added successfully!


Menu:
1. Add Book
2. Display Books
3. Remove Book by ID
4. Search Book by ID
5. Count Books
6. Remove Book by Title
7. Search Book by Title
8. Exit
Enter your choice: 2

Books available:
ID: 11, Title: Sweet Heart, Author: G R Mali
ID: 22, Title: My Life, Author: M D Mahajan
ID: 55, Title: Mera Laal, Author: G Mali


Menu:
1. Add Book
2. Display Books
3. Remove Book by ID
4. Search Book by ID
5. Count Books
6. Remove Book by Title
7. Search Book by Title
8. Exit
Enter your choice: 4

Enter Book ID to search: 22

Book found: ID: 22, Title: My Life, Author: M D Mahajan


Menu:
1. Add Book
2. Display Books
3. Remove Book by ID
4. Search Book by ID
5. Count Books
6. Remove Book by Title
7. Search Book by Title
8. Exit
Enter your choice: 7

Enter Book Title to search: Mera Laal

Book found: ID: 55, Title: Mera Laal, Author: G Mali


Menu:
1. Add Book
2. Display Books
3. Remove Book by ID
4. Search Book by ID
5. Count Books
6. Remove Book by Title
7. Search Book by Title
8. Exit
Enter your choice: 5

Total number of books: 3


Menu:
1. Add Book
2. Display Books
3. Remove Book by ID
4. Search Book by ID
5. Count Books
6. Remove Book by Title
7. Search Book by Title
8. Exit
Enter your choice: 2

Books available:
ID: 11, Title: Sweet Heart, Author: G R Mali
ID: 22, Title: My Life, Author: M D Mahajan
ID: 55, Title: Mera Laal, Author: G Mali


Menu:
1. Add Book
2. Display Books
3. Remove Book by ID
4. Search Book by ID
5. Count Books
6. Remove Book by Title
7. Search Book by Title
8. Exit
Enter your choice: 3

Enter Book ID to remove: 22

Book removed successfully!


Menu:
1. Add Book
2. Display Books
3. Remove Book by ID
4. Search Book by ID
5. Count Books
6. Remove Book by Title
7. Search Book by Title
8. Exit
Enter your choice: 2

Books available:
ID: 11, Title: Sweet Heart, Author: G R Mali
ID: 55, Title: Mera Laal, Author: G Mali


Menu:
1. Add Book
2. Display Books
3. Remove Book by ID
4. Search Book by ID
5. Count Books
6. Remove Book by Title
7. Search Book by Title
8. Exit
Enter your choice: 5

Total number of books: 2


Menu:
1. Add Book
2. Display Books
3. Remove Book by ID
4. Search Book by ID
5. Count Books
6. Remove Book by Title
7. Search Book by Title
8. Exit
Enter your choice: 7

Enter Book Title to search: h

Book with title 'h' not found.


Menu:
1. Add Book
2. Display Books
3. Remove Book by ID
4. Search Book by ID
5. Count Books
6. Remove Book by Title
7. Search Book by Title
8. Exit
Enter your choice: 6

Enter Book Title to remove: Mera Laal

Book with title 'Mera Laal' removed successfully!


Menu:
1. Add Book
2. Display Books
3. Remove Book by ID
4. Search Book by ID
5. Count Books
6. Remove Book by Title
7. Search Book by Title
8. Exit
Enter your choice: 8
*/
