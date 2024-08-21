#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
bool only_digits(string s);
char rotate(char c, int key);

/**
 * main - Entry point for the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, string argv[])
{
    // Check if exactly one command-line argument is provided
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if the key contains only digits
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert the key from a string to an integer
    int key = atoi(argv[1]);

    // Prompt the user for plaintext
    string plaintext = get_string("plaintext:  ");

    // Print the ciphertext
    printf("ciphertext: ");

    // Encrypt the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

/**
 * only_digits - Checks if a string contains only digits
 * @s: The string to check
 *
 * Return: true if the string contains only digits, false otherwise
 */
bool only_digits(string s)
{
    // Iterate over each character in the string
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // Check if the character is not a digit
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

/**
 * rotate - Rotates a character by a given key
 * @c: The character to rotate
 * @key: The key to rotate by
 *
 * Return: The rotated character
 */
char rotate(char c, int key)
{
    // Check if the character is an uppercase letter
    if (isupper(c))
    {
        return (c - 'A' + key) % 26 + 'A';
    }
    // Check if the character is a lowercase letter
    else if (islower(c))
    {
        return (c - 'a' + key) % 26 + 'a';
    }
    // Return the character unchanged if it is not a letter
    else
    {
        return c;
    }
}

