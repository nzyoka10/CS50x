#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name; // Name of the candidate
    int votes;   // Number of votes for the candidate
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: The array of command-line arguments.
 *
 * Return: 0 if successful, otherwise an error code.
 */
int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;

    // Ensure the number of candidates does not exceed the maximum allowed
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // Initialize candidates
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // Get number of voters
    int voter_count = get_int("Number of voters: ");

    // Process each vote
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Record vote or show error message for invalid votes
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Print the winner(s) of the election
    print_winner();
}

/**
 * vote - Update vote totals given a new vote.
 * @name: The name of the candidate voted for.
 *
 * Return: true if the vote was successfully recorded, otherwise false.
 */
bool vote(string name)
{
    // Iterate over each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if candidate's name matches the given name
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }

    // Return false if no candidate's name matches
    return false;
}

/**
 * print_winner - Print the winner (or winners) of the election.
 *
 * The winner is the candidate with the most votes. If there is a tie,
 * all candidates with the maximum number of votes are printed.
 */
void print_winner(void)
{
    int max_votes = 0;

    // Find the maximum number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // Print all candidates with the maximum number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}

