// Make an algorithm that determines whether a credit card number is valid, and what type it is if it is valid

// Luhn's Algorithm
// - Starting with the second-to-last-digit, multiply every other digit by 2 and then add those digits together
// - Add the sum to the sum of the digits that weren't multiplied by 2
// - If the total's last digit is 0, the number is valid

// American express: 15 digit numbers, start with 34/37
// Mastercard: 16 digit numbers, start with 51/52/53/54/55
// Visa: 13 & 16 digit numbers, start with 4

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long ccNumber;
    
    // Get user input
    printf("Please enter your credit card number\n");
    do 
    {
        ccNumber = get_long("Number: ");
    }
    while (ccNumber < 0);
    
    // Make modifiable variable for ccNumber
    long ccTest1 = ccNumber;
    long ccTest2 = ccNumber;
    
    int odd, even, sumOdd = 0, sumEven = 0;
    
    while (ccTest1 > 0)
    {
        // Add odd numbers
        odd = ccTest1 % 10;
        sumOdd += odd;
        ccTest1 -= odd;
        ccTest1 /= 10;
        
        // Add even numbers
        even = ccTest1 % 10;
        
        if ( (even * 2) > 9)
        {
            int evenTimes2 = even * 2;
            sumEven += evenTimes2 % 10;
            sumEven += (evenTimes2 - (evenTimes2 % 10)) / 10;
        }
        else
        {
            sumEven += (even * 2);
        }
            
        ccTest1 -= even;
        ccTest1 /= 10;
    }
    
    // Check if Luhn's Algorithm is valid
    if ( (sumOdd + sumEven) % 10 == 0)
    {
        bool amex, mastercard, visa;
        
        amex = 
            (ccTest2 >= 340000000000000 && ccTest2 < 350000000000000) ||
            (ccTest2 >= 370000000000000 && ccTest2 < 380000000000000);
        
        mastercard = 
            (ccTest2 >= 5100000000000000 && ccTest2 < 5600000000000000);
        
        visa = 
            (ccTest2 >= 4000000000000 && ccTest2 < 5000000000000) ||
            (ccTest2 >= 4000000000000000 && ccTest2 < 5000000000000000);
        
        // Check which credit card it matches
        if (amex)
        {
            printf("AMEX\n");
        }
        else if (mastercard)
        {
            printf("MASTERCARD\n");
        }
        else if (visa)
        {
            printf("VISA\n");
        }
        else 
        {
            printf("INVALID\n");
        }        
    }
    else
    {
        printf("INVALID\n");
    }
}