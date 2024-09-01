#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function prototype for compute_score
int compute_score(string word);

int main(void)
{
    // Prompt the user for two words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute the score of each word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determine and print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

/**
 * compute_score - Computes the score for a given word.
 * @word: The word whose score is to be computed.
 *
 * Return: The score of the word.
 */
int compute_score(string word)
{
    // Variable to keep track of score
    int score = 0;

    // Loop through each character in the word
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // Check if character is an uppercase letter
        if (isupper(word[i]))
        {
            // Add the corresponding point value to score
            score += POINTS[word[i] - 'A'];
        }
        // Check if character is a lowercase letter
        else if (islower(word[i]))
        {
            // Add the corresponding point value to score
            score += POINTS[word[i] - 'a'];
        }
    }

    // Return the computed score
    return score;
}

