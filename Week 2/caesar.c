#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // check user has provided a key
    if (argc == 2) 
    {         
        for (int i = 0; i < strlen(argv[1]); i++) 
        {
            // check each character in the key is a digit
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;                
            }
        }
        
        // convert the key to an int
        int k = atoi(argv[1]);
        
        if (k < 0)
        {
            printf("Negative key");
            return 1;
        }
            
        // get plaintext from user
        string plain = get_string("plaintext: ");
        printf("ciphertext: ");

        // iterate through plaintext and add key to each character
        for (int i = 0; i < strlen(plain); i++)
        {           
            if islower(plain[i])
            {
                printf("%c", (((plain[i] + k) - 97) % 26) + 97);
            }
            else if isupper(plain[i])
            {
                printf("%c", (((plain[i] + k) - 65) % 26) + 65);
            }
            else 
            {
                printf("%c", plain[i]);
            }            
        }
        printf("\n");
    }
    
    else 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}