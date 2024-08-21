#include <cs50.h>
#include <stdio.h>

// bricks function
void print_row(int spaces, int bricks);

int main(void)
{
    // prompt user input for the pyramid height
    int k; // height

    // get a positive interger
    do
    {
        k = get_int("Height: ");
    }
    while (k < 1);

    // build the pyramid of the typed height
    for (int i = 0; i < k; i++)
    {
        // print_row(i + 1);
        int spaces = k - i - 1;
        int bricks = i + 1;
        print_row(spaces, bricks);
    }
}

// function to print row of bricks
void print_row(int spaces, int bricks)
{
    // print space
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }

    // print bricks
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }

    // print new line
    printf("\n");
}

