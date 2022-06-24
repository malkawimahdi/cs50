#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int height = 0;

    do
    {

        //User response is stored in height variable.
        height = get_int("Height: ");
    }

//Continously probes the user until a height is stored that adheres to the convention below.
    while (height < 1 || height > 8);

// For every row, whilst the row is less than the height (8 rows total)
    for (int row = 0; row < height; ++row)
    {
        //Spaces in a row = height - row - 1
        for (int space_count = 0; space_count < height - row - 1; ++space_count)
        {
            printf(" ");
        }
        for (int column = 0; column <= row; ++column)
        {
            printf("#");
        }
        printf("  ");
        printf("\n");
    }
}