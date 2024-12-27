// Q9
/*
  Write a program to create fields of student like Roll No, Name and percentage. Search a particular student according to roll number using binary search.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Student {
    int rollNo;
    char name[50];
    float percentage;
};

struct Student students[MAX];
int n = 0;  // Number of students

void inputStudents() {
    printf("Enter number of students: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Percentage: ");
        scanf("%f", &students[i].percentage);
    }
}

void bubbleSortStudents() {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (students[j].rollNo > students[j+1].rollNo) {
                // Swap the students
                struct Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

int binarySearch(int rollNo) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].rollNo == rollNo) {
            return mid;
        } else if (students[mid].rollNo < rollNo) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void searchStudent() {
    int rollNo;
    printf("Enter roll number to search: ");
    scanf("%d", &rollNo);
    int index = binarySearch(rollNo);
    if (index != -1) {
        printf("Student found:\n");
        printf("Roll No: %d\n", students[index].rollNo);
        printf("Name: %s\n", students[index].name);
        printf("Percentage: %.2f\n", students[index].percentage);
    } else {
        printf("Student with roll number %d not found.\n", rollNo);
    }
}

int main() {
    inputStudents();
    bubbleSortStudents();
    
    char choice;
    do {
        searchStudent();
        printf("Do you want to search again? (y/n): ");
        scanf(" %c", &choice);  // Note the space before %c to consume any leftover whitespace
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}
