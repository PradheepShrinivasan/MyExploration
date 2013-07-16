// Start with the number with the maximum value of mutilpying 2 3 digit number
// if the number is palindrome ..  check if the number is prime 
// if not prime then the number can be represeted as a miltiple of 2 numbers


#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isNumPalindrome (unsigned int number);
unsigned  int numReversed (unsigned int numberToReverse);
bool isPrimeNumber (unsigned int primeNumber);
bool checkIfNumberIsMultiple (unsigned int number);

int main ()
{
	unsigned int maxNumberValue = 999 * 999;

	for (;maxNumberValue > 0 ; maxNumberValue--)
	{
		printf ("Checking number %d \n", maxNumberValue);
		if (isNumPalindrome (maxNumberValue))
		{
			if (!isPrimeNumber (maxNumberValue))
			{
				if (checkIfNumberIsMultiple (maxNumberValue))
				{
					printf (" Number found %d \n", maxNumberValue);
					return 0;
				}
				
			}
		}
	}
	

	return 0;
}

bool checkIfNumberIsMultiple (unsigned int number)
{
	for (unsigned int i = 999 ; i > 100; i--)
	{
		if ((number % i == 0) && (number/i >= 100) && (number/i < 999))
		{
			printf (" number is a multiple of %d and %d  ", number/i ,i );
			return true;
		}

			
	}
	return false;
}

bool isNumPalindrome (unsigned int number)
{
	if (number == numReversed (number))
		return true;
	return false;
}

unsigned  int numReversed (unsigned int numberToReverse)
{
	unsigned int reversedNumber = 0;
	while (numberToReverse)
	{
		reversedNumber *= 10;
		reversedNumber += numberToReverse % 10;
		numberToReverse /=  10;
	}

	return reversedNumber;
}

bool isPrimeNumber (unsigned int primeNumber)
{
	for  (unsigned int i = 2; i < sqrt (primeNumber); i++)
	{
		if (primeNumber % i == 0)
			return false;
	}
	return true;
}

