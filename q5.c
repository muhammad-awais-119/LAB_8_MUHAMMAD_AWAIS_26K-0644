
#include <stdio.h>

int main() {

    // Three main variables
    double costPrice, sellPrice, quantity;

    // Pointers to the variables
    double *ptrCost = &costPrice;
    double *ptrSell = &sellPrice;
    double *ptrQuantity = &quantity;

    // Input using pointers only
    printf("Enter cost price: ");
    scanf("%lf", ptrCost);

    printf("Enter selling price: ");
    scanf("%lf", ptrSell);

    printf("Enter quantity sold: ");
    scanf("%lf", ptrQuantity);

    // Variables for calculations
    double totalCost, totalSales, profitLoss;
    double profitPercentage;

    // Pointers to calculation variables
    double *ptrTotalCost = &totalCost;
    double *ptrTotalSales = &totalSales;
    double *ptrProfitLoss = &profitLoss;
    double *ptrPercentage = &profitPercentage;

    // Calculate using pointers only
    *ptrTotalCost = (*ptrCost) * (*ptrQuantity);

    *ptrTotalSales = (*ptrSell) * (*ptrQuantity);

    *ptrProfitLoss = (*ptrTotalSales) - (*ptrTotalCost);

    // Display results
    printf("\n====== SHOP REPORT ======\n");

    printf("Total Cost  : Rs. %.2lf\n", *ptrTotalCost);

    printf("Total Sales : Rs. %.2lf\n", *ptrTotalSales);

    printf("Profit/Loss : Rs. %.2lf\n", *ptrProfitLoss);

    // Decision structure
    if (*ptrProfitLoss > 0) {
        printf("Result: Profit\n");
    }
    else if (*ptrProfitLoss < 0) {
        printf("Result: Loss\n");
    }
    else {
        printf("Result: No profit no loss\n");
    }

    // Profit percentage
    if (*ptrTotalCost != 0) {

        *ptrPercentage =
            (*ptrProfitLoss / *ptrTotalCost) * 100;

        printf("Profit/Loss Percentage: %.2lf%%\n",
               *ptrPercentage);
    }
    else {
        printf("Percentage cannot be calculated.\n");
    }

    // Pointer to larger value
    double *larger;

    if (*ptrCost > *ptrSell) {
        larger = ptrCost;
        printf("\nPointer points to Cost Price\n");
    }
    else {
        larger = ptrSell;
        printf("\nPointer points to Selling Price\n");
    }

    printf("Larger Value: %.2lf\n", *larger);

    // Address table
    printf("\n====== ADDRESS TABLE ======\n");

    printf("Variable          Address\n");

    printf("costPrice         %p\n", (void*)&costPrice);
    printf("sellPrice         %p\n", (void*)&sellPrice);
    printf("quantity          %p\n", (void*)&quantity);

    printf("totalCost         %p\n", (void*)&totalCost);
    printf("totalSales        %p\n", (void*)&totalSales);
    printf("profitLoss        %p\n", (void*)&profitLoss);
    printf("profitPercentage  %p\n", (void*)&profitPercentage);

    printf("\nPointer           Address\n");

    printf("ptrCost           %p\n", (void*)&ptrCost);
    printf("ptrSell           %p\n", (void*)&ptrSell);
    printf("ptrQuantity       %p\n", (void*)&ptrQuantity);

    printf("ptrTotalCost      %p\n", (void*)&ptrTotalCost);
    printf("ptrTotalSales     %p\n", (void*)&ptrTotalSales);
    printf("ptrProfitLoss     %p\n", (void*)&ptrProfitLoss);
    printf("ptrPercentage     %p\n", (void*)&ptrPercentage);
    printf("larger            %p\n", (void*)&larger);

    return 0;
}
