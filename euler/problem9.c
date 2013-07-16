#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// we know a < b < c 
// and also that a+b+c = 1000  so c = 1000-a-b
// also c^2= a^2+b^2 giving us 
// (1000-a-b)^2 = a^2 +b^2
// so ideally a will be lesser than 250 and b greater than 250 
int main  ()
{
	int a = 1, b = 999;
	for (;a < 500; b--,a ++)
	{
		int temp = 1000-a-b;
		if (temp*temp == (a*a+b*b))
		{
			printf ("%d %d",a,b);
		}
	}

	return 0;
}




