#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int shift(char c);

int main(int argc, string argv[])
{
    // check if user has given right number of arguments
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    else 
    {
        // check if user has input alphabetic characters as keyword
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }                   
        }
        
        int key; 
        
        // get plaintext from user
        string plain = get_string("plaintext: ");
        printf("ciphertext: ");

        int keycounter = 0; // starts at 0
        int keymax = strlen(argv[1]); // number of characters in key
        
        // change plaintext into ciphertext
        for (int i = 0; i < strlen(plain); i++)
        {
            // reset keycounter once cycled through all characters in key
            if (keycounter >= keymax)
            {
                keycounter = 0;                    
            }

            if islower(plain[i])
            {                 
                key = shift(argv[1][keycounter]);
                printf("%c", (((plain[i] + key) - 97) % 26) + 97);
                keycounter++;
      
            }

            else if isupper(plain[i])
            {
                key = shift(argv[1][keycounter]);
                printf("%c", (((plain[i] + key) - 65) % 26) + 65);
                keycounter++;
            }

            else 
            {
                printf("%c", plain[i]);
            }     
            
        }        
        printf("\n");
    }    
}
  
// work out what number to add to each plaintext character
int shift(char c)
{
    if (isupper(c))
    {
        return c - 65;
    }
    else if (islower(c))
    {
        return c - 97;        
    }
    return 0;    
}