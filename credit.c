#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Ask users to enter credit card number
    //If the input is less than one digit, the question will be repeated again.
    long num;
    do
    {
    num = get_long("Number: ");
    }
    while(num < 1);

    //store the sum of the digits in credit card
    int sum = 0;
    //determine the number of digits in credit card
    int digit_num = 0;
    long ccnum = num;

    while(ccnum>1)
    {
        // Get the rightmost digit of the credit card number
        // extract the digits one by one, starting from the rightmost digit and moving left
        int digit = ccnum % 10; //%10 (divided by 10)to give remainder

        // If the digit is in an odd position, add it to the sum of digits that weren't not multiplied by 2
        if (digit_num % 2 == 0)
        {
            sum += digit;
        }
        // If the digit is in an even position, double it and add its digits to the sum
        else
        {
            int doubled = digit*2;
            sum += (doubled % 10) + (doubled / 10);
        }

        // Increment the digit count and remove the rightmost digit from the number
        digit_num++;
        ccnum /= 10;
    }

    // Check validity and card type (card length & starting digits of cards)
    //If the last digit is 0
    if (sum % 10 == 0)
    {
        if ((num >= 340000000000000 && num < 350000000000000 ) || (num >= 370000000000000 && num < 380000000000000))
        {
            printf("AMERRICAN EXPRESS\n");
        }
        else if (num >= 5100000000000000 && num < 5600000000000000)
        {
            printf("MASTERCARD\n");
        }
        else if ((num >= 4000000000000 && num< 50000000000000) || (num >= 4000000000000000 && num < 5000000000000000))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else        //If the last digit is not 0
    {
        printf("INVALID\n");
    }

    return 0;
}