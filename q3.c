
#include <stdio.h>

void displayRoutes() {
    printf("\n===== BUS ROUTES =====\n");
    printf("1. Karachi to Hyderabad - Rs. 800\n");
    printf("2. Karachi to Sukkur    - Rs. 2200\n");
    printf("3. Karachi to Multan    - Rs. 3500\n");
}

int getRoute() {
    int route;

    do {
        printf("\nEnter route number (1-3): ");
        scanf("%d", &route);
    } while (route < 1 || route > 3);

    return route;
}

int getSeats() {
    int seats;

    do {
        printf("Enter number of seats (1-6): ");
        scanf("%d", &seats);
    } while (seats < 1 || seats > 6);

    return seats;
}

double getFare(int route) {
    switch (route) {
        case 1: return 800;
        case 2: return 2200;
        case 3: return 3500;
        default: return 0;
    }
}

double calculateTotal(double fare, int seats) {
    return fare * seats;
}

double addSeatCharge(double total, char type) {
    if (type == 'B' || type == 'b') {
        total = total + (total * 0.30);
    }

    return total;
}

void printTicket(int route, int seats,
                 char type, double total) {

    char routeName[3][30] = {
        "Karachi to Hyderabad",
        "Karachi to Sukkur",
        "Karachi to Multan"
    };

    printf("\n====== BUS TICKET ======\n");

    printf("Route       : %s\n", routeName[route - 1]);

    printf("Seats       : %d\n", seats);

    printf("Seat Type   : %s\n",
           (type == 'B' || type == 'b') ?
           "Business" : "Economy");

    printf("Final Fare  : Rs. %.2f\n", total);

    printf("========================\n");
}

int main() {
    double totalEarnings = 0;

    for (int i = 1; i <= 2; i++) {

        printf("\nPassenger %d\n", i);

        displayRoutes();

        int route = getRoute();

        int seats = getSeats();

        double fare = getFare(route);

        double total = calculateTotal(fare, seats);

        char type;

        do {
            printf("Enter seat type (E = Economy, B = Business): ");
            scanf(" %c", &type);
        } while (type != 'E' && type != 'e' &&
                 type != 'B' && type != 'b');

        double finalFare = addSeatCharge(total, type);

        printTicket(route, seats, type, finalFare);

        totalEarnings += finalFare;
    }

    printf("\nTotal Bus Company Earnings: Rs. %.2f\n",
           totalEarnings);

    return 0;
}
