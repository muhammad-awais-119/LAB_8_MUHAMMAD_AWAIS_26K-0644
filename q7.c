
#include <stdio.h>

int findMax(int *p, int n) {

    int max = *p;

    for (int i = 1; i < n; i++) {

        if (*(p + i) > max) {
            max = *(p + i);
        }
    }

    return max;
}

int findMin(int *p, int n) {

    int min = *p;

    for (int i = 1; i < n; i++) {

        if (*(p + i) < min) {
            min = *(p + i);
        }
    }

    return min;
}

double findAverage(int *p, int n) {

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += *(p + i);
    }

    return (double)sum / n;
}

int countAbove(int *p, int n, double avg) {

    int count = 0;

    for (int i = 0; i < n; i++) {

        if (*(p + i) > avg) {
            count++;
        }
    }

    return count;
}

void reverseArray(int *p, int n) {

    int *start = p;

    int *end = p + n - 1;

    while (start < end) {

        int temp = *start;

        *start = *end;

        *end = temp;

        start++;

        end--;
    }
}

int searchMark(int *p, int n, int key) {

    for (int i = 0; i < n; i++) {

        if (*(p + i) == key) {
            return i + 1;
        }
    }

    return -1;
}

int main() {

    int marks[10];

    int n = 10;

    // Input marks
    for (int i = 0; i < n; i++) {

        do {
            printf("Enter marks of student %d (0-100): ", i + 1);

            scanf("%d", &marks[i]);

        } while (marks[i] < 0 || marks[i] > 100);
    }

    // Display original array
    printf("\nOriginal Marks:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", marks[i]);
    }

    // Call functions
    int maximum = findMax(marks, n);

    int minimum = findMin(marks, n);

    double average = findAverage(marks, n);

    int aboveAverage = countAbove(marks, n, average);

    // Pass count
    int passCount = 0;

    for (int i = 0; i < n; i++) {

        if (marks[i] >= 40) {
            passCount++;
        }
    }

    // Display report
    printf("\n\n====== CLASS REPORT ======\n");

    printf("Highest Marks: %d\n", maximum);

    printf("Lowest Marks : %d\n", minimum);

    printf("Average Marks: %.2lf\n", average);

    printf("Above Average Students: %d\n", aboveAverage);

    printf("Pass Count: %d\n", passCount);

    // Search a mark
    int key;

    printf("\nEnter marks to search: ");
    scanf("%d", &key);

    int position = searchMark(marks, n, key);

    if (position != -1) {
        printf("Mark found at position %d\n", position);
    }
    else {
        printf("Mark not found!\n");
    }

    // Reverse array
    reverseArray(marks, n);

    printf("\nReversed Marks:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", marks[i]);
    }

    printf("\n");

    return 0;
}
