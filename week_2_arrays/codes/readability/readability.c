#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

/**
 * count_letters - Counts the number of letters in a text
 * @text: The text to analyze
 *
 * Return: The number of letters in the text
 */
int count_letters(string text);

/**
 * count_words - Counts the number of words in a text
 * @text: The text to analyze
 *
 * Return: The number of words in the text
 */
int count_words(string text);

/**
 * count_sentences - Counts the number of sentences in a text
 * @text: The text to analyze
 *
 * Return: The number of sentences in the text
 */
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade_level = round(index);

    // Print the grade level
    if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", grade_level);
    }
}

/**
 * count_letters - Counts the number of letters in a text
 * @text: The text to analyze
 *
 * Return: The number of letters in the text
 */
int count_letters(string text)
{
    int count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }

    return count;
}

/**
 * count_words - Counts the number of words in a text
 * @text: The text to analyze
 *
 * Return: The number of words in the text
 */
int count_words(string text)
{
    int count = 1; // Start with 1 to count the last word

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }

    return count;
}

/**
 * count_sentences - Counts the number of sentences in a text
 * @text: The text to analyze
 *
 * Return: The number of sentences in the text
 */
int count_sentences(string text)
{
    int count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

    return count;
}

