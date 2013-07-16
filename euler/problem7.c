#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime (unsigned long int number);

int main ()
{
	unsigned long int count = 1, number = 2;
	while (count != 10001)
	{
		number++;
		if (isPrime (number))
			count ++;
	}
	printf ("%ld", number);
	return 0;
}

bool isPrime (unsigned long int number)
{
	for (unsigned long int i = 2; i <= sqrt (number); i++)
	{
		if (number % i == 0)
			return false;
	}
	return true;
}
