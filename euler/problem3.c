#include <stdio.h>
#include <math.h>

#define PRIMEFACTORNUM 600851475143
unsigned short int isPrime (unsigned long int number);

int main ()
{

	for (unsigned long int i = 2; i < PRIMEFACTORNUM; i++)
	{
		if (PRIMEFACTORNUM % i == 0) // the number is divisible 
		{
			//check to see if we the quotient is prime
			long quotient = PRIMEFACTORNUM / i;
			if (isPrime (quotient))
			{
				printf ("%ld", quotient);
				return 0;
			}
		}

	}

	printf (" Is the number prime  ? %s",isPrime (17)?"true":"false");
	printf (" Is the number prime  ? %s",isPrime (8)?"true":"false");
	return 0;
}

unsigned short int isPrime (unsigned long int number)
{
	for (long i = 2; i < sqrt (number); i++)
		if (number % i == 0)
			return 0;
	return 1;
}
