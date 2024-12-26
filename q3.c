// Q3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Car {
    char model[50];
    char manufacturer[50];
    float price;
    float engine_capacity;
    struct Car *prev;
    struct Car *next;
};

struct Car *head = NULL;

void insertCar();
void deleteCar();
void updateCarPrice();
void listCarsInPriceRange();
void searchCarByModel();
void displayCars();
void menu();

void insertCar() {
    struct Car *newCar = (struct Car *)malloc(sizeof(struct Car));
    
    // Reading Car Model with spaces
    printf("\nEnter Car Model: ");
    getchar();  // Consume any leftover newline character from previous input
    scanf("%[^\n]", newCar->model);
    
    // Reading Manufacturer with spaces
    printf("Enter Manufacturer: ");
    getchar();  // Consume any leftover newline character from previous input
    scanf("%[^\n]", newCar->manufacturer);
    
    // Reading price
    printf("Enter Price: ");
    scanf("%f", &newCar->price);
    
    // Reading engine capacity
    printf("Enter Engine Capacity (in liters): ");
    scanf("%f", &newCar->engine_capacity);
    
    // Set the new car's pointers to NULL initially
    newCar->prev = NULL;
    newCar->next = NULL;

    // Insert the new car into the doubly linked list
    if (head == NULL) {
        head = newCar;
    } else {
        struct Car *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newCar;
        newCar->prev = temp;
    }
    printf("\nCar model added successfully!\n");
}



void deleteCar() {
    char model[50];
    getchar();
    printf("\nEnter the Car model to delete: ");
    scanf("%[^\n]", model);
    
    struct Car *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->model, model) == 0) {
            if (temp == head) {
                head = temp->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            } else {
                temp->prev->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }
            }
            free(temp);
            printf("\nCar model '%s' deleted successfully!\n", model);
            return;
        }
        temp = temp->next;
    }
    printf("\nCar model '%s' not found!\n", model);
}

void updateCarPrice() {
    char model[50];
    printf("\nEnter the Car model to update price: ");
    getchar();
    scanf("%[^\n]", model);
    
    struct Car *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->model, model) == 0) {
            printf("Enter new price: ");
            scanf("%f", &temp->price);
            printf("\nPrice updated successfully for '%s'.\n", model);
            return;
        }
        temp = temp->next;
    }
    printf("\nCar model '%s' not found!\n", model);
}

void listCarsInPriceRange() {
    float lower, upper;
    printf("\nEnter the price range (lower upper): ");
    scanf("%f %f", &lower, &upper);
    
    struct Car *temp = head;
    int found = 0;
    printf("\nCars in the price range %.2f - %.2f:\n", lower, upper);
    while (temp != NULL) {
        if (temp->price >= lower && temp->price <= upper) {
            printf("Model: %s, Manufacturer: %s, Price: %.2f, Engine Capacity: %.2fL\n",
                    temp->model, temp->manufacturer, temp->price, temp->engine_capacity);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("No cars found in this price range.\n");
    }
}

void searchCarByModel() {
    char model[50];
    printf("\nEnter Car model to search: ");
    getchar();
    scanf("%[^\n]", model);
    
    struct Car *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->model, model) == 0) {
            printf("\nCar Details:\n");
            printf("Model: %s\n", temp->model);
            printf("Manufacturer: %s\n", temp->manufacturer);
            printf("Price: %.2f\n", temp->price);
            printf("Engine Capacity: %.2fL\n", temp->engine_capacity);
            return;
        }
        temp = temp->next;
    }
    printf("\nCar model '%s' not found!\n", model);
}

void displayCars() {
    if (head == NULL) {
        printf("\nNo cars available.\n");
        return;
    }
    struct Car *temp = head;
    printf("\nList of all cars:\n");
    while (temp != NULL) {
        printf("\n Model: %s \n Manufacturer: %s \n Price: %.2f \n Engine Capacity: %.2fL\n",
                temp->model, temp->manufacturer, temp->price, temp->engine_capacity);
        temp = temp->next;
    }
}


int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert new Car\n");
        printf("2. Delete Car by Model\n");
        printf("3. Update Car Price\n");
        printf("4. List Cars in Price Range\n");
        printf("5. Search Car by Model\n");
        printf("6. Display All Cars\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertCar();
                break;
            case 2:
                deleteCar();
                break;
            case 3:
                updateCarPrice();
                break;
            case 4:
                listCarsInPriceRange();
                break;
            case 5:
                searchCarByModel();
                break;
            case 6:
                displayCars();
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}

/*

Menu:
1. Insert new Car
2. Delete Car by Model
3. Update Car Price
4. List Cars in Price Range
5. Search Car by Model
6. Display All Cars
7. Exit
Enter your choice: 1

Enter Car Model: Model 1
Enter Manufacturer: KK
Enter Price: 45000
Enter Engine Capacity (in liters): 50

Car model added successfully!

Menu:
1. Insert new Car
2. Delete Car by Model
3. Update Car Price
4. List Cars in Price Range
5. Search Car by Model
6. Display All Cars
7. Exit
Enter your choice: 1

Enter Car Model: Model 2
Enter Manufacturer: MMM
Enter Price: 952400
Enter Engine Capacity (in liters): 65

Car model added successfully!

Menu:
1. Insert new Car
2. Delete Car by Model
3. Update Car Price
4. List Cars in Price Range
5. Search Car by Model
6. Display All Cars
7. Exit
Enter your choice: 2

Enter the Car model to delete: Model 3

Car model 'Model 3' not found!

Menu:
1. Insert new Car
2. Delete Car by Model
3. Update Car Price
4. List Cars in Price Range
5. Search Car by Model
6. Display All Cars
7. Exit
Enter your choice: 6

List of all cars:

 Model: Model 1 
 Manufacturer: KK 
 Price: 45000.00 
 Engine Capacity: 50.00L

 Model: Model 2 
 Manufacturer: MMM 
 Price: 952400.00 
 Engine Capacity: 65.00L

Menu:
1. Insert new Car
2. Delete Car by Model
3. Update Car Price
4. List Cars in Price Range
5. Search Car by Model
6. Display All Cars
7. Exit
Enter your choice: 4

Enter the price range (lower upper): 20000 60000

Cars in the price range 20000.00 - 60000.00:
Model: Model 1, Manufacturer: KK, Price: 45000.00, Engine Capacity: 50.00L

Menu:
1. Insert new Car
2. Delete Car by Model
3. Update Car Price
4. List Cars in Price Range
5. Search Car by Model
6. Display All Cars
7. Exit
Enter your choice: 5

Enter Car model to search: Model 5

Car model 'Model 5' not found!

Menu:
1. Insert new Car
2. Delete Car by Model
3. Update Car Price
4. List Cars in Price Range
5. Search Car by Model
6. Display All Cars
7. Exit
Enter your choice: 5

Enter Car model to search: Model 1

Car Details:
Model: Model 1
Manufacturer: KK
Price: 45000.00
Engine Capacity: 50.00L

Menu:
1. Insert new Car
2. Delete Car by Model
3. Update Car Price
4. List Cars in Price Range
5. Search Car by Model
6. Display All Cars
7. Exit
Enter your choice: 6

List of all cars:

 Model: Model 1 
 Manufacturer: KK 
 Price: 45000.00 
 Engine Capacity: 50.00L

 Model: Model 2 
 Manufacturer: MMM 
 Price: 952400.00 
 Engine Capacity: 65.00L

Menu:
1. Insert new Car
2. Delete Car by Model
3. Update Car Price
4. List Cars in Price Range
5. Search Car by Model
6. Display All Cars
7. Exit
Enter your choice: 3

Enter the Car model to update price: Model

Car model 'Model' not found!

Menu:
1. Insert new Car
2. Delete Car by Model
3. Update Car Price
4. List Cars in Price Range
5. Search Car by Model
6. Display All Cars
7. Exit
Enter your choice: 3

Enter the Car model to update price: Model 1
Enter new price: 6845210

Price updated successfully for 'Model 1'.

Menu:
1. Insert new Car
2. Delete Car by Model
3. Update Car Price
4. List Cars in Price Range
5. Search Car by Model
6. Display All Cars
7. Exit
Enter your choice: 6

List of all cars:

 Model: Model 1 
 Manufacturer: KK 
 Price: 6845210.00 
 Engine Capacity: 50.00L

 Model: Model 2 
 Manufacturer: MMM 
 Price: 952400.00 
 Engine Capacity: 65.00L

Menu:
1. Insert new Car
2. Delete Car by Model
3. Update Car Price
4. List Cars in Price Range
5. Search Car by Model
6. Display All Cars
7. Exit
Enter your choice: 4

Enter the price range (lower upper): 200 6895210

Cars in the price range 200.00 - 6895210.00:
Model: Model 1, Manufacturer: KK, Price: 6845210.00, Engine Capacity: 50.00L
Model: Model 2, Manufacturer: MMM, Price: 952400.00, Engine Capacity: 65.00L

Menu:
1. Insert new Car
2. Delete Car by Model
3. Update Car Price
4. List Cars in Price Range
5. Search Car by Model
6. Display All Cars
7. Exit
Enter your choice: 2

Enter the Car model to delete: Model 1

Car model 'Model 1' deleted successfully!

Menu:
1. Insert new Car
2. Delete Car by Model
3. Update Car Price
4. List Cars in Price Range
5. Search Car by Model
6. Display All Cars
7. Exit
Enter your choice: 6

List of all cars:

 Model: Model 2 
 Manufacturer: MMM 
 Price: 952400.00 
 Engine Capacity: 65.00L

Menu:
1. Insert new Car
2. Delete Car by Model
3. Update Car Price
4. List Cars in Price Range
5. Search Car by Model
6. Display All Cars
7. Exit
Enter your choice: 7


=== Code Execution Successful ===
*/
