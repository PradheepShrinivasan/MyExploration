#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main ()
{
	unsigned long int  base  = 1, sum = 0, legs = 2 ,count = 0;  
	float height = 0;
	while (count < 6)
	{
		for (base = 2; base < 2*legs; base+=2) 
		{
			height = sqrt (legs*legs - base*base/4);
			if (base-height == 1.0 || height-base == 1.0)
			{
				printf ("found base %ld legs %ld and height %f \n", base ,legs,height );
				sum += legs;
				count++;
			}
		}
		legs++;
	}
	printf ("%ld \n",sum);
	return 0;
}
