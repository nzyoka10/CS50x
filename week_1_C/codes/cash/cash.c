#include <cs50.h>
#include <stdio.h>

int calculate_coins(int cents, int denomination);

int main(void)
{
    // prompt the user for change owed, in cents
    int cents;

    do
    {
        cents = get_int("Change owed (in cents): ");
    }
    while (cents < 0);

    // initialize total coins count
    int total_coins = 0;

    // calculate quarters and update remaining cents
    int quarters = calculate_coins(cents, 25);
    total_coins += quarters;
    cents -= quarters * 25;

    // calculate dimes and update remaining cents
    int dimes = calculate_coins(cents, 10);
    total_coins += dimes;
    cents -= dimes * 10;

    // calculate nickels and update remaining cents
    int nickels = calculate_coins(cents, 5);
    total_coins += nickels;
    cents -= nickels * 5;

    // pennies are the remaining cents
    total_coins += cents;

    // print the total number of coins
    printf("%i\n", total_coins);

    return 0;
}

// function to calculate number of coins of given denomination
int calculate_coins(int cents, int denomination)
{
    int count = 0;
    while (cents >= denomination)
    {
        count++;
        cents -= denomination;
    }
    return count;
}

