#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the currency denominations for bills and coins
int bills[] = {2000, 1000, 500, 200, 100, 50, 25}; // Array of bill denominations
int coins[] = {20, 10, 5, 1}; // Array of coin denominations

// Function to calculate the change to give back
double calcule_monnaie(double amountGiven, double amountToPay) {
    return amountGiven - amountToPay;
}

// Function to determine the bills and coins for the change
void determine_change(double change, int bills[], int coins[]) {
    int count;
    printf("Change to give back: Rs%.2f\n", change);

    // Calculate bills
    for (int i = 0; i < sizeof(bills)/sizeof(bills[0]); i++) {
        count = change / bills[i];
        if (count != 0) {
            printf("Give %d bill(s) of Rs%d\n", count, bills[i]);
            change -= count * bills[i];
        }
    }

    // Calculate coins
    for (int i = 0; i < sizeof(coins)/sizeof(coins[0]); i++) {
        count = change / coins[i];
        if (count != 0) {
            printf("Give %d coin(s) of Rs%d\n", count, coins[i]);
            change -= count * coins[i];
        }
    }
}

int main() {
    // Initialize random number generator
    srand(time(0));

    // Generate a random double between 0 and 200
    double amountToPay = (double)rand() / RAND_MAX * 200;
    printf("Amount to pay: Rs%.2f\n", amountToPay);

    double amountGiven;
    do {
        printf("Enter the amount you will give to pay: ");
        scanf("%lf", &amountGiven);

        if (amountGiven < amountToPay) {
            printf("You have given less than what you owe. Please try again.\n");
        }
    } while (amountGiven < amountToPay);

    // Calculate and print the change to give back
    double change = calcule_monnaie(amountGiven, amountToPay);

    // Determine and print the bills and coins for the change
    determine_change(change, bills, coins);

    printf("Payment successful. Thank you!\n");

    return 0;
}
