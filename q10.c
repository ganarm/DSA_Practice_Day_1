// Q.10
/*
  Write a program to arrange list of students to find out first ten toppers from a class using Bubble sort.
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
            if (students[j].percentage < students[j+1].percentage) {
                // Swap the students
                struct Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

void displayTopTenToppers() {
    printf("\nTop 10 Toppers:\n");
    printf("Roll No\tName\tPercentage\n");
    for (int i = 0; i < n && i < 2; i++) {
        printf("%d\t%s\t%.2f\n", students[i].rollNo, students[i].name, students[i].percentage);
    }
}

int main() {
    inputStudents();
    bubbleSortStudents();
    displayTopTenToppers();
    return 0;
}
