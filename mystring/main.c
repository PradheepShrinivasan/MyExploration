// this code is the test code that is written to 
// test the working of string library

#include <stdio.h>
#include <mystring.h>

int main()
{
	char *current = "helloworld";
	char destination [12];

	printf ("strcpy of helloworld %s \n", mystrcpy (current, destination));
	printf ("%s \n", mystrncpy (current, destination, 1));
	printf ("%s \n", mystrncpy (current, destination, 0));
	printf ("length of helloworld = %d", mystrlen ("helloworld"));
	return 0;
}
