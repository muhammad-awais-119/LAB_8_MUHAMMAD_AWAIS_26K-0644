
#include <stdio.h>

void displayRules() {
    printf("\n===== TAXI FARE RULES =====\n");
    printf("Base Fare: Rs. 150\n");
    printf("First 10 km: Rs. 60 per km\n");
    printf("After 10 km: Rs. 45 per km\n");
    printf("First 5 minutes waiting: FREE\n");
    printf("After 5 minutes: Rs. 10 per minute\n");
    printf("Night charge: 25%% extra\n");
}

double getDistance() {
    double distance;

    do {
        printf("\nEnter distance (0-200 km): ");
        scanf("%lf", &distance);
    } while (distance <= 0 || distance > 200);

    return distance;
}

int getWaitingTime() {
    int waiting;

    do {
        printf("Enter waiting time (0-120 minutes): ");
        scanf("%d", &waiting);
    } while (waiting < 0 || waiting > 120);

    return waiting;
}

double distanceCharge(double distance) {
    double charge = 150;

    if (distance <= 10) {
        charge += distance * 60;
    }
    else {
        charge += (10 * 60) + ((distance - 10) * 45);
    }

    return charge;
}

double waitingCharge(int waiting) {
    if (waiting > 5) {
        return (waiting - 5) * 10;
    }

    return 0;
}

double nightCharge(double fare, int hour) {
    if (hour >= 22 || hour < 6) {
        fare += fare * 0.25;
    }

    return fare;
}

int main() {
    double totalEarnings = 0;
    double highestFare = 0;

    displayRules();

    for (int i = 1; i <= 3; i++) {

        printf("\n========== TRIP %d ==========\n", i);

        double distance = getDistance();

        int waiting = getWaitingTime();

        int hour;

        do {
            printf("Enter trip hour (0-23): ");
            scanf("%d", &hour);
        } while (hour < 0 || hour > 23);

        double dCharge = distanceCharge(distance);

        double wCharge = waitingCharge(waiting);

        double total = dCharge + wCharge;

        double finalFare = nightCharge(total, hour);

        printf("\n====== TRIP RECEIPT ======\n");
        printf("Distance       : %.2f km\n", distance);
        printf("Waiting Time   : %d minutes\n", waiting);
        printf("Distance Charge: Rs. %.2f\n", dCharge);
        printf("Waiting Charge : Rs. %.2f\n", wCharge);
        printf("Final Fare     : Rs. %.2f\n", finalFare);
        printf("==========================\n");

        totalEarnings += finalFare;

        if (finalFare > highestFare) {
            highestFare = finalFare;
        }
    }

    printf("\nTotal Earnings: Rs. %.2f\n", totalEarnings);

    printf("Highest Fare of the Day: Rs. %.2f\n",
           highestFare);

    return 0;
}
