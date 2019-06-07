// Generates a pyramid for Mario to jump over
#include <cs50.h>
#include <stdio.h>

int main(void){
    int height;
    printf("How many steps should Mario jump?\n");
    printf("Pick a number between 1-8\n");
    
    do 
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    for(int i = 1; i <= height; i++){
        for (int k = height; k > i; k--){
            printf(" ");
        }
        for (int j = 0; j < i; j++){
            printf("#");
        }
        printf("  ");
        for (int l = 0; l < i; l++){
            printf("#");
        }        
        printf("\n");
    }
}
