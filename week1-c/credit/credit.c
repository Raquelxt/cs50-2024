#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long int number = get_long("Number: "); // Get the credit card number
    long int original_number = number;      // Store original number for later use
    int checksum = 0;                       // Initialize checksum
    int digit = 0;                          // Variable for the current digit
    bool should_double = false;             // Flag to determine whether to double the digit

    // Calculate checksum using Luhn's algorithm
    while (number > 0)
    {
        digit = number % 10; // Extract last digit

        // Double every second digit
        if (should_double)
        {
            int doubled_digit = digit * 2;
            checksum +=
                (doubled_digit > 9) ? (doubled_digit % 10) + (doubled_digit / 10) : doubled_digit;
        }
        else
        {
            checksum += digit; // Add digit if not doubled
        }

        should_double = !should_double; // Toggle the flag
        number /= 10;                   // Remove last digit
    }

    // Check if checksum is valid
    if (checksum % 10 == 0)
    {
        int length = 0;                  // Variable for the length of the card number
        long int temp = original_number; // Temporary variable to determine length

        // Determine length of the number
        while (temp > 0)
        {
            temp /= 10; // Remove last digit
            length++;   // Increment length
        }

        // Identify card type based on length and starting digits
        if ((length == 13 && original_number / 1000000000000 == 4) ||
            (length == 16 && original_number / 1000000000000000 == 4))
        {
            printf("VISA\n");
        }
        else if (length == 15 &&
                 (original_number / 10000000000000 == 34 || original_number / 10000000000000 == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && (original_number / 100000000000000 >= 51 &&
                                  original_number / 100000000000000 <= 55))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n"); // Print INVALID if none match
        }
    }
    else
    {
        printf("INVALID\n"); // Print INVALID if checksum is not valid
    }
}
