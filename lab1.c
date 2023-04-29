#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for starting population size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while(start<9);

    // Prompt user for ending population size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while(end<start);

    int years = 0;

    //number of years required for the llama population to reach that end size
    while (start < end)
    {
        int new = start/ 3;
        int dead = start/ 4;
        start += new - dead;
        years++;
    }

    printf("Years: %i\n", years);
    return 0;
