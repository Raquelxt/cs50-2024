#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for height until valid input (1-8)
    int height = 0;
    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }

    // Loop through each row of the pyramid
    for (int j = 0; j < height; j++)
    {
        // Print spaces for left pyramid
        for (int i = 0; i < height - j - 1; i++)
        {
            printf(" ");
        }

        // Print hashes for left pyramid
        for (int i = 0; i <= j; i++)
        {
            printf("#");
        }

        // Print two spaces between the pyramids
        printf("  ");

        // Print hashes for right pyramid
        for (int i = 0; i <= j; i++)
        {
            printf("#");
        }

        // Move to the next line after each row
        printf("\n");
    }
}
