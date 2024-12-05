#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function declarations
int scoresum(string player);
void results(int score1, int score2);

// Assigning individual scores to each letter
int letter_score[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // Ask for both players` input words
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // Calculate each players` final scores
    int score1 = scoresum(player1);
    int score2 = scoresum(player2);

    // Display the final result
    results(score1, score2);
}

// Calculate the score of a word
int scoresum(string player)
{
    int sum = 0;
    int length = strlen(player);
    int letter_position;

    for (int i = 0; i < length; i++)
    {
        if (isalpha(player[i]))
        {
            player[i] = toupper(player[i]);
            letter_position = player[i] - 'A';
            sum += letter_score[letter_position];
        }
    }

    printf("The score sum is %i\n", sum);

    return sum;
}

// Compare the scores from players 1 and 2
void results(int score1, int score2)
{
    // Prints the winner
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
