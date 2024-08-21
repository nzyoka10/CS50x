#include <cs50.h>
#include <stdio.h>

// function prototypes
int card_length(long long card_number);
bool luhn_algorithm(long long card_number);
void print_card_type(long long card_number);

int main(void)
{
    // prompt user for credit card number
    long long card_number;

    do
    {
        card_number = get_long_long("Number: ");
    }
    while (card_number < 0);

    // check validity of the card number using Luhn's algorithm
    bool is_valid = luhn_algorithm(card_number);

    // print card type or INVALID if not valid
    if (is_valid)
    {
        print_card_type(card_number);
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

// function to calculate the length of the credit card number
int card_length(long long card_number)
{
    int length = 0;
    while (card_number > 0)
    {
        card_number /= 10;
        length++;
    }
    return length;
}

// function to check validity of the credit card number using Luhn's algorithm
bool luhn_algorithm(long long card_number)
{
    int sum = 0;
    int length = card_length(card_number);
    bool multiply = false;

    while (card_number > 0)
    {
        int digit = card_number % 10;

        if (multiply)
        {
            digit *= 2;
            while (digit > 0)
            {
                sum += digit % 10;
                digit /= 10;
            }
        }
        else
        {
            sum += digit;
        }

        card_number /= 10;
        multiply = !multiply;
    }

    return (sum % 10 == 0);
}

// function to determine and print the card type
void print_card_type(long long card_number)
{
    int length = card_length(card_number);

    // check for Visa (13 or 16 digits, starting with 4)
    if ((length == 13 || length == 16) &&
        (card_number / 1000000000000 == 4 || card_number / 1000000000000000 == 4))
    {
        printf("VISA\n");
    }
    // check for MasterCard (16 digits, starting with 51, 52, 53, 54, or 55)
    else if (length == 16 &&
             (card_number / 100000000000000 == 51 || card_number / 100000000000000 == 52 ||
              card_number / 100000000000000 == 53 || card_number / 100000000000000 == 54 ||
              card_number / 100000000000000 == 55))
    {
        printf("MASTERCARD\n");
    }
    // check for American Express (15 digits, starting with 34 or 37)
    else if (length == 15 &&
             (card_number / 10000000000000 == 34 || card_number / 10000000000000 == 37))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

