
#include <stdio.h>

void displayHospital() {
    printf("\n===== CITY HOSPITAL =====\n");
    printf("1. General Ward     Rs. 1500/day\n");
    printf("2. Semi-Private     Rs. 3500/day\n");
    printf("3. Private          Rs. 6000/day\n");
}

int getRoomType() {
    int type;

    do {
        printf("\nEnter room type (1-3): ");
        scanf("%d", &type);
    } while (type < 1 || type > 3);

    return type;
}

int getDays() {
    int days;

    do {
        printf("Enter number of days (1-30): ");
        scanf("%d", &days);
    } while (days < 1 || days > 30);

    return days;
}

double getRoomCharges(int type, int days) {
    double rate;

    switch (type) {
        case 1:
            rate = 1500;
            break;

        case 2:
            rate = 3500;
            break;

        case 3:
            rate = 6000;
            break;

        default:
            rate = 0;
    }

    return rate * days;
}

double getMedicineCharges(double medicine) {
    return medicine + (medicine * 0.05);
}

double calculateDiscount(double total, int days) {
    if (days >= 7)
        return total * 0.08;

    return 0;
}

double seniorDiscount(double total, char senior) {
    if (senior == 'y' || senior == 'Y') {
        total -= 1000;
    }

    if (total < 0)
        total = 0;

    return total;
}

void printBill(int type, int days,
               double room, double medicine,
               double discount, double finalAmount) {

    char roomName[3][20] = {
        "General Ward",
        "Semi-Private",
        "Private"
    };

    printf("\n====== HOSPITAL BILL ======\n");

    printf("Room Type       : %s\n",
           roomName[type - 1]);

    printf("Days Stayed     : %d\n", days);

    printf("Room Charges    : Rs. %.2f\n", room);

    printf("Medicine Charges: Rs. %.2f\n", medicine);

    printf("Discount        : Rs. %.2f\n", discount);

    printf("Final Amount    : Rs. %.2f\n", finalAmount);

    printf("===========================\n");
}

int main() {
    displayHospital();

    int type = getRoomType();

    int days = getDays();

    double roomCharges = getRoomCharges(type, days);

    double medicine;

    do {
        printf("Enter medicine bill: ");
        scanf("%lf", &medicine);
    } while (medicine < 0);

    double medicineCharges = getMedicineCharges(medicine);

    double total = roomCharges + medicineCharges;

    double discount = calculateDiscount(total, days);

    double finalAmount = total - discount;

    char senior;

    printf("Is the patient a senior citizen? (y/n): ");
    scanf(" %c", &senior);

    if (senior == 'y' || senior == 'Y') {
        finalAmount = seniorDiscount(finalAmount, senior);
    }

    printBill(type, days, roomCharges,
              medicineCharges, discount, finalAmount);

    return 0;
}
