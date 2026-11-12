
#include <stdio.h>
#include <string.h>

// Read three subject marks using pointers
void readMarks(int *m1, int *m2, int *m3) {

    do {
        printf("Enter marks of subject 1 (0-100): ");
        scanf("%d", m1);
    } while (*m1 < 0 || *m1 > 100);

    do {
        printf("Enter marks of subject 2 (0-100): ");
        scanf("%d", m2);
    } while (*m2 < 0 || *m2 > 100);

    do {
        printf("Enter marks of subject 3 (0-100): ");
        scanf("%d", m3);
    } while (*m3 < 0 || *m3 > 100);
}

// Calculate total, average, highest and lowest
void calculateStats(int m1, int m2, int m3,
                    int *total, double *average,
                    int *highest, int *lowest) {

    *total = m1 + m2 + m3;

    *average = (double)(*total) / 3;

    *highest = m1;

    if (m2 > *highest)
        *highest = m2;

    if (m3 > *highest)
        *highest = m3;

    *lowest = m1;

    if (m2 < *lowest)
        *lowest = m2;

    if (m3 < *lowest)
        *lowest = m3;
}

// Swap two marks
void swapMarks(int *a, int *b) {

    int temp = *a;

    *a = *b;

    *b = temp;
}

// Sort three marks in descending order
void sortMarks(int *m1, int *m2, int *m3) {

    if (*m1 < *m2) {
        swapMarks(m1, m2);
    }

    if (*m1 < *m3) {
        swapMarks(m1, m3);
    }

    if (*m2 < *m3) {
        swapMarks(m2, m3);
    }
}

// Add grace marks
void addGraceMarks(int *mark, int grace) {

    if (*mark >= 35 && *mark <= 39) {

        *mark += grace;

        // Do not increase beyond 40
        if (*mark > 40) {
            *mark = 40;
        }
    }
}

// Find grade and remarks
void findGrade(double avg, char *grade,
               char remarks[]) {

    // Grade boundaries are assumed because
    // the lab sheet does not specify them.

    if (avg >= 80) {

        *grade = 'A';

        strcpy(remarks, "Excellent");
    }

    else if (avg >= 60) {

        *grade = 'B';

        strcpy(remarks, "Good");
    }

    else {

        *grade = 'C';

        strcpy(remarks, "Needs Improvement");
    }
}

// Pass by value
void incrementByValue(int x) {

    x++;
}

// Pass by reference equivalent in C
void incrementByReference(int *x) {

    (*x)++;
}

int main() {

    int m1, m2, m3;

    int total, highest, lowest;

    double average;

    int grace;

    char grade;

    char remarks[30];

    for (int i = 1; i <= 5; i++) {

        printf("\n========== STUDENT %d ==========\n", i);

        // Read marks
        readMarks(&m1, &m2, &m3);

        // Ask for grace marks
        do {
            printf("Enter grace marks (0-5): ");
            scanf("%d", &grace);
        } while (grace < 0 || grace > 5);

        // Apply grace marks
        addGraceMarks(&m1, grace);

        addGraceMarks(&m2, grace);

        addGraceMarks(&m3, grace);

        // Calculate statistics
        calculateStats(m1, m2, m3,
                       &total, &average,
                       &highest, &lowest);

        // Sort marks from highest to lowest
        sortMarks(&m1, &m2, &m3);

        // Find grade
        findGrade(average, &grade, remarks);

        // Display student result
        printf("\n====== STUDENT RESULT ======\n");

        printf("Sorted Marks: %d %d %d\n", m1, m2, m3);

        printf("Total Marks : %d\n", total);

        printf("Average     : %.2lf\n", average);

        printf("Highest     : %d\n", highest);

        printf("Lowest      : %d\n", lowest);

        printf("Grade       : %c\n", grade);

        printf("Remarks     : %s\n", remarks);

        printf("============================\n");
    }

    // Comparison between pass by value
    // and pass by reference
    printf("\n====== PASS BY VALUE AND REFERENCE ======\n");

    int x = 10;

    printf("Original value: %d\n", x);

    incrementByValue(x);

    printf("After incrementByValue: %d\n", x);

    incrementByReference(&x);

    printf("After incrementByReference: %d\n", x);

    return 0;
}


