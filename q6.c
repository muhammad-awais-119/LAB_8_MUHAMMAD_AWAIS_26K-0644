
#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;

    do {
        printf("Enter number of days (1-10): ");
        scanf("%d", &n);
    } while (n < 1 || n > 10);

    // Dynamically allocate memory
    double *temp = (double*)malloc(n * sizeof(double));

    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input temperatures
    for (int i = 0; i < n; i++) {

        do {
            printf("Enter temperature for day %d: ", i + 1);
            scanf("%lf", &temp[i]);

            if (temp[i] < -10 || temp[i] > 55) {
                printf("Invalid! Enter between -10 and 55.\n");
            }

        } while (temp[i] < -10 || temp[i] > 55);
    }

    // Display temperatures and addresses
    printf("\n====== TEMPERATURE RECORD ======\n");

    for (int i = 0; i < n; i++) {
        printf("Day %d: %.2lf at address %p\n",
               i + 1, temp[i], (void*)&temp[i]);
    }

    // Initialize hottest and coldest
    double hottest = *temp;
    double coldest = *temp;

    int above40 = 0;

    // Pointer moves forward
    double *ptr = temp;

    for (int i = 0; i < n; i++) {

        if (*ptr > hottest) {
            hottest = *ptr;
        }

        if (*ptr < coldest) {
            coldest = *ptr;
        }

        if (*ptr > 40) {
            above40++;
        }

        ptr++;
    }

    printf("\n====== WEATHER REPORT ======\n");

    printf("Hottest Temperature: %.2lf\n", hottest);

    printf("Coldest Temperature: %.2lf\n", coldest);

    printf("Days Above 40: %d\n", above40);

    // Release memory
    free(temp);

    temp = NULL;

    printf("\nMemory has been successfully released!\n");

    return 0;
}
