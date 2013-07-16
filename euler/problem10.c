#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime (unsigned long long int number);

int main ()
{
	unsigned long long int sum  = 0, number = 2;
	while (number < 2000000)
	{
		if (isPrime (number))
			sum += number;
		number++;
	}
	printf ("%llu", sum);
	return 0;
}

bool isPrime (unsigned long long int number)
{
	for (unsigned long int i = 2; i <= sqrt (number); i++)
	{
		if (number % i == 0)
			return false;
	}
	return true;
}
