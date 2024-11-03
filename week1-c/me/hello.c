#include <cs50.h>
#include <stdio.h>

// Says hello to the user
int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}
