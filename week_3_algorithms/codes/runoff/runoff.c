#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;     // Name of the candidate
    int votes;       // Number of votes the candidate has
    bool eliminated; // Whether the candidate has been eliminated
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

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
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // Get number of voters
    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Collect votes from each voter
    for (int i = 0; i < voter_count; i++)
    {
        // Collect each rank of preferences from the voter
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Run election rounds until a winner is found
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Find the minimum vote count and check if there's a tie
        int min = find_min();
        bool tie = is_tie(min);

        // If there is a tie, print all remaining candidates' names
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate candidates with the minimum number of votes
        eliminate(min);

        // Reset vote counts to zero for the next round
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }

    return 0;
}

/**
 * vote - Record a voter's preference.
 * @voter: The index of the voter.
 * @rank: The rank of the preference (0 is the highest).
 * @name: The name of the candidate being voted for.
 *
 * Return: true if the vote is successfully recorded, false otherwise.
 */
bool vote(int voter, int rank, string name)
{
    // Check each candidate to see if the name matches
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            // Record the preference
            preferences[voter][rank] = i;
            return true;
        }
    }

    // Candidate not found
    return false;
}

/**
 * tabulate - Update the vote count for non-eliminated candidates.
 */
void tabulate(void)
{
    // Process each voter
    for (int i = 0; i < voter_count; i++)
    {
        // Find the highest-ranked non-eliminated candidate
        for (int j = 0; j < candidate_count; j++)
        {
            int candidate_index = preferences[i][j];

            if (!candidates[candidate_index].eliminated)
            {
                // Increment vote count for the top non-eliminated candidate
                candidates[candidate_index].votes++;
                break;
            }
        }
    }
}

/**
 * print_winner - Check if any candidate has more than half of the votes.
 *
 * Return: true if a winner is found, false otherwise.
 */
bool print_winner(void)
{
    int majority = voter_count / 2;

    // Check each candidate to see if they have more than half of the votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > majority)
        {
            // Print the winner's name
            printf("%s\n", candidates[i].name);
            return true;
        }
    }

    // No winner found
    return false;
}

/**
 * find_min - Find the minimum number of votes among remaining candidates.
 *
 * Return: The minimum vote count.
 */
int find_min(void)
{
    int min_votes = MAX_VOTERS;

    // Determine the minimum number of votes among non-eliminated candidates
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < min_votes)
        {
            min_votes = candidates[i].votes;
        }
    }

    return min_votes;
}

/**
 * is_tie - Check if all remaining candidates have the same number of votes.
 * @min: The minimum number of votes among remaining candidates.
 *
 * Return: true if there is a tie, false otherwise.
 */
bool is_tie(int min)
{
    // Check if all non-eliminated candidates have the same number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false;
        }
    }

    return true;
}

/**
 * eliminate - Eliminate candidates with the minimum number of votes.
 * @min: The minimum number of votes among remaining candidates.
 */
void eliminate(int min)
{
    // Eliminate all candidates with the minimum vote count
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}

