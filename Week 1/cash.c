// Create a program that first asks the user how much change is owed
// And then prints the minimum number of coins with which that change can be made

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    int coins = 0;
    
    printf("How much change do I owe you?\n");
    
    do 
    {
        dollars = get_float("Change: ");
    }
    while (dollars < 0);
    
    int cents = round(dollars * 100);
    
    while ((cents - 25) >= 0)
    {
        cents -= 25;
        coins++;
    }
    while ((cents-10) >= 0)
    {
        cents -= 10;
        coins++;    
    }
    while ((cents - 5) >= 0)
    {
        cents -= 5;
        coins++;
    }
    while ((cents - 1) >= 0)
    {
        cents -= 1;
        coins++;
    }
    
    printf("%i\n", coins);
}
