// Q1

#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int size = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                size++;
            }
        }
    }

    int compactMatrix[3][size]; // 3 indicates that index in row, index in column, value at index row n index column
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = matrix[i][j];
                k++;
            }
        }
    }

    printf("Original Compact Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", compactMatrix[i][j]);
        }
        printf("\n");
    }

    // Transpose the compact matrix
    int transposedCompactMatrix[3][size];
    for (int i = 0; i < size; i++) {
        transposedCompactMatrix[0][i] = compactMatrix[1][i];
        transposedCompactMatrix[1][i] = compactMatrix[0][i];
        transposedCompactMatrix[2][i] = compactMatrix[2][i];
    }

    // Print the transposed compact matrix
    printf("\nTransposed Compact Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", transposedCompactMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
Make Sure Give input like this you can understand what exactly difference
OUTPUT ::

Enter the number of rows: 4
Enter the number of columns: 4
Enter the elements of the matrix:
0 1 0 0
0 0 0 3
2 0 0 0 
5 2 0 0
Original Compact Matrix:
0 1 2 3 3 
1 3 0 0 1 
1 3 2 5 2 

Transposed Compact Matrix:
1 3 0 0 1 
0 1 2 3 3 
1 3 2 5 2 

*/
