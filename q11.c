// Q.11
/*
Write a program to sort a list of sales data for a retail company. Each record represents a sale and contains the following information: 
sales ID, customer name, product name, quantity sold, and total sale amount. sort the sales data based on the total sale amount in descending 
order using the Merge Sort algorithm./Quick sort method
*/
#include <stdio.h>
#include <string.h>

#define MAX 20

struct Sale {
    int salesID;
    char customerName[50];
    char productName[50];
    int quantitySold;
    float totalSaleAmount;
};

void merge(struct Sale[], int, int, int);
void mergeSort(struct Sale[], int, int);

int main() {
    struct Sale sales[MAX];
    int n;

    printf("Enter the number of sales records: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for sale %d:\n", i + 1);
        printf("Sales ID: ");
        scanf("%d", &sales[i].salesID);
        printf("Customer Name: ");
        scanf("%s", sales[i].customerName);
        printf("Product Name: ");
        scanf("%s", sales[i].productName);
        printf("Quantity Sold: ");
        scanf("%d", &sales[i].quantitySold);
        printf("Total Sale Amount: ");
        scanf("%f", &sales[i].totalSaleAmount);
    }

    mergeSort(sales, 0, n - 1);

    printf("\nSales data sorted by total sale amount in descending order:\n");
    for (int i = 0; i < n; i++) {
        printf("\nSale %d:\n", i + 1);
        printf("Sales ID: %d\n", sales[i].salesID);
        printf("Customer Name: %s\n", sales[i].customerName);
        printf("Product Name: %s\n", sales[i].productName);
        printf("Quantity Sold: %d\n", sales[i].quantitySold);
        printf("Total Sale Amount: %.2f\n", sales[i].totalSaleAmount);
    }

    return 0;
}

void mergeSort(struct Sale sales[], int l, int h) {
    int mid;
    if (l < h) {
        mid = (l + h) / 2;
        mergeSort(sales, l, mid);
        mergeSort(sales, mid + 1, h);
        merge(sales, l, mid, h);
    }
}

void merge(struct Sale sales[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;
    struct Sale temp[MAX];

    while (i <= mid && j <= h) {
        if (sales[i].totalSaleAmount >= sales[j].totalSaleAmount) {
            temp[k] = sales[i];
            i++;
        } else {
            temp[k] = sales[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = sales[i];
        i++;
        k++;
    }

    while (j <= h) {
        temp[k] = sales[j];
        j++;
        k++;
    }

    for (k = l; k <= h; k++) {
        sales[k] = temp[k];
    }
}
