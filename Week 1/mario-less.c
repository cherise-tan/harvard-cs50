// Recreate steps using hashes "#" for bricks
// Allow user to decide how tall the user should be, by prompting them for a positive integer between 1-8 (inclusive)

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    printf("How many steps should Mario climb?\n");
    printf("Specify a number between 1-8\n");
    
    do 
    {
        height = get_int("Steps: ");
    }
    while (height < 1 || height > 8);
    {
        for (int i = 1; i <= height; i++){
            for(int k = height; k > i; k--){
                printf(" ");
            }            
            for (int j = 0; j < i; j++){
                printf("#");
            }
            printf("\n");
        }      
    }
}
