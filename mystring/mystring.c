#include <stdio.h>
#include <mystring.h>

char* mystrcpy (const char* src, char* dest)
{
	char *current = dest;
	if (!src || !dest)
		return dest;

	while (*src != '\0')
	{
		*current = *src;
		++src;
		++current;
	}
	*current = '\0';
	return dest;
}

int mystrlen (const char* src)
{
	int length = 0;
	while (*src) 
	{
		++length;
		++src;
	}
	return length;
}

extern char* mystrncpy (const char* src, char* dest, int len)
{
	char *iter = dest;
	if (!src || !dest || len <= 0)
		return dest;

	while (*src && len--)
	{
		*iter = *src;
		++src;
		++iter;
	}
	*iter = '\0';
	return dest;
}
