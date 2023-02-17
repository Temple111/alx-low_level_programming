#include <stdio.h>
#include <stdlib.h>
/**
 * main - a program that assigns a random number to a variable
 * Return: 0 (always successful)
 */

int main(void)
{
int n;
n = rand(); 
if (n > 0)
	printf("%d is positive\n", n);
else if (n == 0)
	printf("%d is zero\n", n);
else
	printf("%d is negative\n", n);
return (0);
}
