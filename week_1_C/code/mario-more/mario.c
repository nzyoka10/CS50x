#include <cs50.h>
#include <stdio.h>

void print_row(int total_rows, int current_row);

int main(void)
{
    // Prompt the user for the pyramid's height
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Print the pyramid of that height
    for (int i = 0; i < n; i++)
    {
        print_row(n, i + 1);
    }
}

void print_row(int total_rows, int current_row)
{
    // Print leading spaces
    for (int i = 0; i < total_rows - current_row; i++)
    {
        printf(" ");
    }

    // Print left-hand bricks
    for (int i = 0; i < current_row; i++)
    {
        printf("#");
    }

    // Print gap between the pyramids
    printf("  ");

    // Print right-hand bricks
    for (int i = 0; i < current_row; i++)
    {
        printf("#");
    }

    // Print newline character to move to the next row
    printf("\n");
}

