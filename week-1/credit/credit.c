#include <cs50.h>
#include <stdio.h>

/*Function to count the number of digits that has been inputed by the user.
By using the modulo of 10 to recieve the last digit and iterating until
The number is not 0. */
int digitCounter(long number)
{
    int counter = 0;
    while (number > 0)
    {
        ++counter;
        number = number / 10;

    }
    return counter;
}




/* Asks for the users credentials and returns a long to the caller.*/
long getCredentials()
{
    long credit_card_number = get_long("Number: ");

    return credit_card_number;
}


int main(void)
{
    long credit_card_number = getCredentials();

    int totalCreditCardDigits = digitCounter(credit_card_number);

    int total = 0;

    int counter = 0;

    int oddTotal = 0;

    int evenTotal = 0;

    int cardFirstDigit = 0;

    int cardSecondDigit = 0;

    int mod = 0;

    while (credit_card_number > 0)
    {
        mod = credit_card_number % 10;

        int intemediary = mod;

        total = total + intemediary;

        credit_card_number = credit_card_number / 10;

        //Gets the first digit of the credit card and stores in a seperate variable.
        if (digitCounter(credit_card_number) == 0)
        {
            cardFirstDigit = mod;
        }

        if (digitCounter(credit_card_number) == 1)
        {
            cardSecondDigit = mod;
        }

        //If the counter is even do...
        if (counter % 2 == 0)
        {
            evenTotal = evenTotal + mod;
        }

        //Else means that the counter is odd.
        else
        {
            /*After applying Luhn's algorithm, check if during the multiplication process, 2 digits are stored.
            If so, take the seperate digits and apply addition instead. */
            int currentMod = mod * 2;

            if (digitCounter(currentMod) == 2)
            {
                while (currentMod > 0)                           //do till num greater than  0
                {
                    int modWhile = currentMod % 10;                 //split last digit from number

                    int intemediaryWhile = modWhile;

                    currentMod = currentMod / 10;    //divide num by 10. num /= 10 also a valid one

                    oddTotal = oddTotal + modWhile;
                }
            }

            else
            {
                oddTotal = oddTotal + currentMod;
            }
        }

        ++counter;
    }
    int cardTotal = oddTotal + evenTotal;

    int cardModulo = cardTotal % 10;

    //If the card's modulo is anything OTHER THAN 0, than the card is invalid.
    //Else, determine the card
    if (cardModulo != 0)
    {
        printf("INVALID\n");
    }

    else if (cardFirstDigit == 3 && (cardSecondDigit == 4 || cardSecondDigit == 7))
    {
        printf("AMEX\n");
    }

    else if (cardFirstDigit == 4)
    {
        printf("VISA\n");
    }

    else if (cardFirstDigit == 5 && (cardSecondDigit == 1 || cardSecondDigit == 2 || cardSecondDigit == 3 ||
                                     cardSecondDigit == 4 || cardSecondDigit == 5))
    {
        printf("MASTERCARD\n");
    }

    else
    {
        printf("INVALID\n");
    }
    return 0;
}