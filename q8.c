
#include <stdio.h>
#include <stdlib.h>

// Display stock
void displayStock(int *p, int n) {

    printf("\nCurrent Stock:\n");

    for (int i = 0; i < n; i++) {
        printf("Item %d: %d\n", i + 1, *(p + i));
    }
}

// Calculate total and lowest stock
void displaySummary(int *p, int n) {

    int total = 0;

    int lowest = *p;

    for (int i = 0; i < n; i++) {

        total += *(p + i);

        if (*(p + i) < lowest) {
            lowest = *(p + i);
        }
    }

    printf("\nTotal Stock: %d\n", total);

    printf("Lowest Stock: %d\n", lowest);
}

// Update stock
void updateStock(int *p, int n) {

    int position, value;

    printf("Enter item position to update (1-%d): ", n);
    scanf("%d", &position);

    if (position < 1 || position > n) {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter new stock value: ");
    scanf("%d", &value);

    if (value < 0) {
        printf("Stock cannot be negative!\n");
        return;
    }

    *(p + position - 1) = value;

    printf("Stock updated successfully!\n");

    displaySummary(p, n);
}

// Insert new item
int* insertItem(int *p, int *n) {

    int position, value;

    printf("Enter position for new item (1-%d): ", *n + 1);
    scanf("%d", &position);

    if (position < 1 || position > *n + 1) {
        printf("Invalid position!\n");
        return p;
    }

    printf("Enter stock value: ");
    scanf("%d", &value);

    if (value < 0) {
        printf("Stock cannot be negative!\n");
        return p;
    }

    // Create bigger array
    int *newArray = (int*)malloc((*n + 1) * sizeof(int));

    if (newArray == NULL) {
        printf("Memory allocation failed!\n");
        return p;
    }

    // Copy elements and insert new value
    int j = 0;

    for (int i = 0; i < *n + 1; i++) {

        if (i == position - 1) {
            *(newArray + i) = value;
        }
        else {
            *(newArray + i) = *(p + j);
            j++;
        }
    }

    // Delete old array
    free(p);

    // Update pointer and size
    *n = *n + 1;

    printf("Item inserted successfully!\n");

    displaySummary(newArray, *n);

    return newArray;
}

// Delete item
int* deleteItem(int *p, int *n) {

    if (*n <= 1) {
        printf("Cannot delete the last remaining item!\n");
        return p;
    }

    int position;

    printf("Enter position to delete (1-%d): ", *n);
    scanf("%d", &position);

    if (position < 1 || position > *n) {
        printf("Invalid position!\n");
        return p;
    }

    // Create smaller array
    int *newArray = (int*)malloc((*n - 1) * sizeof(int));

    if (newArray == NULL) {
        printf("Memory allocation failed!\n");
        return p;
    }

    // Copy all except deleted element
    int j = 0;

    for (int i = 0; i < *n; i++) {

        if (i != position - 1) {
            *(newArray + j) = *(p + i);
            j++;
        }
    }

    // Delete old array
    free(p);

    // Update size
    *n = *n - 1;

    printf("Item deleted successfully!\n");

    displaySummary(newArray, *n);

    return newArray;
}

// Sort stock using bubble sort and pointers
void sortStock(int *p, int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (*(p + j) > *(p + j + 1)) {

                int temp = *(p + j);

                *(p + j) = *(p + j + 1);

                *(p + j + 1) = temp;
            }
        }
    }

    printf("Stock sorted successfully!\n");

    displaySummary(p, n);
}

int main() {

    int n;

    do {
        printf("Enter starting size (3-8): ");
        scanf("%d", &n);
    } while (n < 3 || n > 8);

    // Dynamic memory allocation
    int *stock = (int*)malloc(n * sizeof(int));

    if (stock == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input starting stock
    for (int i = 0; i < n; i++) {

        do {
            printf("Enter stock of item %d: ", i + 1);
            scanf("%d", &stock[i]);
        } while (stock[i] < 0);
    }

    int choice;

    do {

        printf("\n====== STOCK MENU ======\n");

        printf("1. Display Stock\n");
        printf("2. Update Stock\n");
        printf("3. Insert New Item\n");
        printf("4. Delete Item\n");
        printf("5. Sort Stock\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                displayStock(stock, n);
                break;

            case 2:
                updateStock(stock, n);
                break;

            case 3:
                stock = insertItem(stock, &n);
                break;

            case 4:
                stock = deleteItem(stock, &n);
                break;

            case 5:
                sortStock(stock, n);
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    // Release memory
    free(stock);

    stock = NULL;

    printf("Memory released successfully!\n");

    return 0;
}
