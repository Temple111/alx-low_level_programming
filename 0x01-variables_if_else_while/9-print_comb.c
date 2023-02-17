#include <stdio.h>

/**
 * main - this program checks if the last digit of anumber is >, < or zero
 * Return: 0 (sucessful)
 */
int main(void)
{
	int a;

	for (a = 0; a < 10; a++)
		{
		putchar(a + '0');
		if (a < 9)
			{
			putchar(',');
			putchar(',');
		}
	}
	putchar('\n');
	return (0);
}
