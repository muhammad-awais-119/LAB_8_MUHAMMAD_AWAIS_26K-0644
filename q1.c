
#include <stdio.h>

void displayPacks() {
    printf("\n===== MOBILE RECHARGE =====\n");
    printf("1. Rs. 100\n");
    printf("2. Rs. 200\n");
    printf("3. Rs. 500\n");
    printf("4. Rs. 1000\n");
}

int getPack() {
    int pack;

    do {
        printf("\nEnter pack number (1-4): ");
        scanf("%d", &pack);
    } while (pack < 1 || pack > 4);

    return pack;
}

long long getMobile() {
    long long mobile;

    do {
        printf("Enter 11-digit mobile number: ");
        scanf("%lld", &mobile);
    } while (mobile < 10000000000LL ||
             mobile > 99999999999LL);

    return mobile;
}

double getAmount(int pack) {
    switch (pack) {
        case 1: return 100;
        case 2: return 200;
        case 3: return 500;
        case 4: return 1000;
        default: return 0;
    }
}

double addTax(double amount) {
    return amount + (amount * 0.15);
}

double getBonus(double amount) {
    if (amount >= 500)
        return amount * 0.10;

    return 0;
}

void printSlip(long long mobile, double amount,
               double tax, double bonus) {

    printf("\n====== RECHARGE SLIP ======\n");
    printf("Mobile Number : %011lld\n", mobile);
    printf("Package Amount: Rs. %.2f\n", amount);
    printf("Tax (15%%)     : Rs. %.2f\n", tax);
    printf("Bonus         : Rs. %.2f\n", bonus);
    printf("Total Balance : Rs. %.2f\n", tax + bonus);
    printf("===========================\n");
}

int main() {
    double totalSpent = 0;

    for (int i = 1; i <= 3; i++) {

        printf("\nRecharge Number %d\n", i);

        displayPacks();

        int pack = getPack();

        long long mobile = getMobile();

        double amount = getAmount(pack);

        double newAmount = addTax(amount);

        double bonus = getBonus(amount);

        printSlip(mobile, amount,
                  newAmount - amount, bonus);

        totalSpent += amount;
    }

    printf("\nTotal Money Spent: Rs. %.2f\n",
           totalSpent);

    return 0;
}
