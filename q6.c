// Q.6
/*
Write a program that reads a list of names and telephone numbers from user and insert into a BST tree. Once the tree has been built, 
present the user with a menu that allows him to search the list for a specified name, insert new name, delete an existing name or print the entire phone list.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[50];
    char phone[15];
    struct node* left;
    struct node* right;
};

// Global root node of the tree
struct node* root = NULL;
struct node* minNode = NULL; // Global variable to store the minimum node

// Insert a new name and phone number into the BST (without returning the root)
void insert(char name[], char phone[]) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->left = newNode->right = NULL;

    if (root == NULL) {
        root = newNode;  // If tree is empty, set root to new node
        return;
    }

    struct node* temp = root;
    struct node* parent = NULL;

    while (temp != NULL) {
        parent = temp;
        if (strcmp(name, temp->name) < 0) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    // Insert the new node at the correct position
    if (strcmp(name, parent->name) < 0) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

// Search for a name in the BST and print the result directly
void search(char name[]) {
    struct node* temp = root;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Found contact: %s, Phone: %s\n", temp->name, temp->phone);
            return;
        } else if (strcmp(name, temp->name) < 0) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    printf("Contact not found.\n");
}

// In-order traversal to print the entire phone list
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Name: %s, Phone: %s\n", root->name, root->phone);
        inorder(root->right);
    }
}

// Find the minimum node in the tree (without returning it, instead use a global variable)
void findMin(struct node* root) {
    minNode = root;
    while (minNode != NULL && minNode->left != NULL) {
        minNode = minNode->left;
    }
}

// Delete a name from the BST
void delete(char name[]) {
    struct node* temp = root;
    struct node* parent = NULL;
    
    // Find the node to delete and its parent
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        parent = temp;
        if (strcmp(name, temp->name) < 0) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    
    // If the node was not found
    if (temp == NULL) {
        printf("Contact not found.\n");
        return;
    }

    // Node has no children (leaf node)
    if (temp->left == NULL && temp->right == NULL) {
        if (parent == NULL) {
            root = NULL;  // Root node is being deleted
        } else if (parent->left == temp) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(temp);
    }
    // Node has only one child
    else if (temp->left == NULL || temp->right == NULL) {
        struct node* child = (temp->left) ? temp->left : temp->right;
        if (parent == NULL) {
            root = child;  // Root node is being deleted
        } else if (parent->left == temp) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        free(temp);
    }
    // Node has two children
    else {
        findMin(temp->right); // Use the global `minNode`
        strcpy(temp->name, minNode->name);
        strcpy(temp->phone, minNode->phone);
        delete(minNode->name); // Delete the minimum node (which has been swapped)
    }
}

// Main function to execute the program
int main() {
    char name[50], phone[15];
    int choice;

    // Build the tree with initial names and numbers
    printf("Enter the number of contacts: ");
    int n;
    scanf("%d", &n);
    getchar(); // To consume the newline character after number input
    for (int i = 0; i < n; i++) {
        printf("Enter name: ");
        scanf("%49s", name); // Read the name without spaces
        printf("Enter phone number: ");
        scanf("%14s", phone); // Read the phone number
        insert(name, phone);
    }

    do {
        // Menu for user to interact with the phone list
        printf("\nMenu:\n");
        printf("1. Search for a contact\n");
        printf("2. Insert a new contact\n");
        printf("3. Delete a contact\n");
        printf("4. Print all contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after choice input

        switch (choice) {
            case 1:
                printf("Enter name to search: ");
                scanf("%49s", name); // Read the name to search
                search(name); // Directly print the result from search function
                break;
            case 2:
                printf("Enter name to insert: ");
                scanf("%49s", name); // Read the name to insert
                printf("Enter phone number: ");
                scanf("%14s", phone); // Read the phone number
                insert(name, phone);
                printf("Contact added successfully.\n");
                break;
            case 3:
                printf("Enter name to delete: ");
                scanf("%49s", name); // Read the name to delete
                delete(name);
                printf("Contact deleted successfully.\n");
                break;
            case 4:
                printf("Phone List:\n");
                inorder(root);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[50];
    char phone[15];
    struct node* left;
    struct node* right;
};

// Global root node of the tree
struct node* root = NULL;
struct node* minNode = NULL; // Global variable to store the minimum node

// Insert a new name and phone number into the BST (without returning the root)
void insert(char name[], char phone[]) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->left = newNode->right = NULL;

    if (root == NULL) {
        root = newNode;  // If tree is empty, set root to new node
        return;
    }

    struct node* temp = root;
    struct node* parent = NULL;

    while (temp != NULL) {
        parent = temp;
        if (strcmp(name, temp->name) < 0) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    // Insert the new node at the correct position
    if (strcmp(name, parent->name) < 0) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

// Search for a name in the BST and print the result directly
void search(char name[]) {
    struct node* temp = root;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Found contact: %s, Phone: %s\n", temp->name, temp->phone);
            return;
        } else if (strcmp(name, temp->name) < 0) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    printf("Contact not found.\n");
}

// In-order traversal to print the entire phone list
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Name: %s, Phone: %s\n", root->name, root->phone);
        inorder(root->right);
    }
}

// Find the minimum node in the tree (without returning it, instead use a global variable)
void findMin(struct node* root) {
    minNode = root;
    while (minNode != NULL && minNode->left != NULL) {
        minNode = minNode->left;
    }
}

// Delete a name from the BST
void delete(char name[]) {
    struct node* temp = root;
    struct node* parent = NULL;
    
    // Find the node to delete and its parent
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        parent = temp;
        if (strcmp(name, temp->name) < 0) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    
    // If the node was not found
    if (temp == NULL) {
        printf("Contact not found.\n");
        return;
    }

    // Node has no children (leaf node)
    if (temp->left == NULL && temp->right == NULL) {
        if (parent == NULL) {
            root = NULL;  // Root node is being deleted
        } else if (parent->left == temp) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(temp);
    }
    // Node has only one child
    else if (temp->left == NULL || temp->right == NULL) {
        struct node* child = (temp->left) ? temp->left : temp->right;
        if (parent == NULL) {
            root = child;  // Root node is being deleted
        } else if (parent->left == temp) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        free(temp);
    }
    // Node has two children
    else {
        findMin(temp->right); // Use the global `minNode`
        strcpy(temp->name, minNode->name);
        strcpy(temp->phone, minNode->phone);
        delete(minNode->name); // Delete the minimum node (which has been swapped)
    }
}

// Main function to execute the program
int main() {
    char name[50], phone[15];
    int choice;

    // Build the tree with initial names and numbers
    printf("Enter the number of contacts: ");
    int n;
    scanf("%d", &n);
    getchar(); // To consume the newline character after number input
    for (int i = 0; i < n; i++) {
        printf("Enter name: ");
        scanf("%49s", name); // Read the name without spaces
        printf("Enter phone number: ");
        scanf("%14s", phone); // Read the phone number
        insert(name, phone);
    }

    do {
        // Menu for user to interact with the phone list
        printf("\nMenu:\n");
        printf("1. Search for a contact\n");
        printf("2. Insert a new contact\n");
        printf("3. Delete a contact\n");
        printf("4. Print all contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after choice input

        switch (choice) {
            case 1:
                printf("Enter name to search: ");
                scanf("%49s", name); // Read the name to search
                search(name); // Directly print the result from search function
                break;
            case 2:
                printf("Enter name to insert: ");
                scanf("%49s", name); // Read the name to insert
                printf("Enter phone number: ");
                scanf("%14s", phone); // Read the phone number
                insert(name, phone);
                printf("Contact added successfully.\n");
                break;
            case 3:
                printf("Enter name to delete: ");
                scanf("%49s", name); // Read the name to delete
                delete(name);
                printf("Contact deleted successfully.\n");
                break;
            case 4:
                printf("Phone List:\n");
                inorder(root);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

*/
