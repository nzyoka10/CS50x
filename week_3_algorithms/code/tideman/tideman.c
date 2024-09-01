#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is the number of voters who prefer candidate i over candidate j
int preferences[MAX][MAX];

// locked[i][j] is true if candidate i is locked in over candidate j
bool locked[MAX][MAX];

// Each pair has a winner and a loser
typedef struct
{
    int winner; // index of the winning candidate
    int loser;  // index of the losing candidate
} pair;

// Array of candidate names
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2]; // Array to store pairs of candidates

int pair_count;      // Number of pairs
int candidate_count; // Number of candidates

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool creates_cycle(int start, int end);

/**
 * Main function
 * Handles the entire election process:
 * 1. Initializes candidates and locked graph
 * 2. Collects votes and records preferences
 * 3. Adds, sorts, and locks pairs
 * 4. Prints the winner
 */
int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear the graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes from each voter
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);
        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();

    return 0;
}

/**
 * Update ranks given a new vote
 *
 * @param rank: the rank of the candidate
 * @param name: the name of the candidate
 * @param ranks: array of ranks to update
 *
 * @return: true if the vote was successfully recorded, false otherwise
 */
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

/**
 * Update preferences given one voter's ranks
 *
 * @param ranks: array of ranks from one voter
 */
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

/**
 * Record pairs of candidates where one is preferred over the other
 */
void add_pairs(void)
{
    pair_count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i != j)
            {
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                    pair_count++;
                }
            }
        }
    }
}

/**
 * Sort pairs in decreasing order by strength of victory
 */
void sort_pairs(void)
{
    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = i + 1; j < pair_count; j++)
        {
            int strength_i = preferences[pairs[i].winner][pairs[i].loser];
            int strength_j = preferences[pairs[j].winner][pairs[j].loser];

            if (strength_i < strength_j)
            {
                pair temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
            }
        }
    }
}

/**
 * Lock pairs into the candidate graph in order, without creating cycles
 */
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;

        if (!creates_cycle(winner, loser))
        {
            locked[winner][loser] = true;
        }
    }
}

/**
 * Helper function to determine if adding an edge creates a cycle
 *
 * @param start: the starting candidate index
 * @param end: the ending candidate index
 *
 * @return: true if adding the edge creates a cycle, false otherwise
 */
bool creates_cycle(int start, int end)
{
    if (start == end)
    {
        return true;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[end][i] && creates_cycle(start, i))
        {
            return true;
        }
    }

    return false;
}

/**
 * Print the winner of the election
 */
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        bool is_source = true;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                is_source = false;
                break;
            }
        }
        if (is_source)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
}

