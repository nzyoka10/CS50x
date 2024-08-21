#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Function prototypes
bool is_valid_key(string key);
bool all_unique_letters(string key);
char substitute_char(char c, string key);

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
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Validate the key
    if (!is_valid_key(argv[1]))
    {
        printf("Key MUST contain 26 alphabetic characters, each exactly once.\n");
        return 1;
    }

    // Prompt the user for plaintext
    string plaintext = get_string("plaintext: ");

    // Output the ciphertext
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        // Encrypt each character in the plaintext
        char ciphertext_char = substitute_char(plaintext[i], argv[1]);
        printf("%c", ciphertext_char);
    }
    printf("\n");

    return 0;
}

/**
 * Check if the key is valid.
 *
 * @param key: The key string provided by the user.
 * @return: True if the key is valid; otherwise, false.
 */
bool is_valid_key(string key)
{
    // Check if the key has exactly 26 characters
    if (strlen(key) != ALPHABET_SIZE)
    {
        return false;
    }

    // Check if all characters in the key are alphabetic
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }

    // Convert key to uppercase for uniformity
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        key[i] = toupper(key[i]);
    }

    // Check if all letters in the key are unique
    return all_unique_letters(key);
}

/**
 * Check if all characters in the key are unique.
 *
 * @param key: The key string provided by the user.
 * @return: True if all characters are unique; otherwise, false.
 */
bool all_unique_letters(string key)
{
    // Array to track occurrences of each letter
    bool letter_seen[ALPHABET_SIZE] = {false};

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        int index = key[i] - 'A';

        if (letter_seen[index])
        {
            return false;
        }

        letter_seen[index] = true;
    }

    return true;
}

/**
 * Substitute a character using the provided key.
 *
 * @param c: The character to be substituted.
 * @param key: The key string used for substitution.
 * @return: The substituted character.
 */
char substitute_char(char c, string key)
{
    // If character is uppercase
    if (isupper(c))
    {
        return key[c - 'A'];
    }
    // If character is lowercase
    else if (islower(c))
    {
        return tolower(key[c - 'a']);
    }
    // If character is non-alphabetic, return it unchanged
    else
    {
        return c;
    }
}

