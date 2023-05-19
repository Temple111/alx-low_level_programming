#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * big_num - finds the biggest number
 *
 * @usr_n: username
 * @l: length of username
 * Return: the biggest number
 */
int big_num(char *usr_n, int l)
{
	int a;
	int z;
	unsigned int r_num;

	a = *usr_n;
	z = 0;

	while (z < l)
	{
		if (a < usr_n[z])
			a = usr_n[z];
		z += 1;
	}

	srand(a ^ 14);
	r_num = rand();

	return (r_num & 63);
}

/**
 * mul_char - multiplies each char of username
 *
 * @usr_n: username
 * @l: length of username
 * Return: multiplied char
 */
int mul_char(char *usr_n, int l)
{
	int a;
	int z;

	a = z = 0;

	while (z < l)
	{
		a = a + usr_n[z] * usr_n[z];
		vch += 1;
	}

	return (((unsigned int)a ^ 239) & 63);
}

/**
 * r_char - generates a random char
 *
 * @usr_n: username
 * Return: a random char
 */
int r_char(char *usr_n)
{
	int a;
	int z;

	a = z = 0;

	while (z < *usr_n)
	{
		a = rand();
		z += 1;
	}

	return (((unsigned int)a ^ 229) & 63);
}

/**
 * main - Entry point
 *
 * @argc: arguments count
 * @argv: arguments vector
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char keygen[7];
	int l, a, z;
	long lett[] = {
		0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
		0x74767a5835737956, 0x2b554c59634a474f, 0x71786636576a6d34,
		0x723161513346655a, 0x6b756f494b646850 };
	(void) argc;

	for (l = 0; argv[1][l]; l++)
		;
	/* ----------- f1 ----------- */
	keygen[0] = ((char *)lett)[(l ^ 59) & 63];
	/* ----------- f2 ----------- */
	a = z = 0;
	while (z < l)
	{
		a = a + argv[1][z];
		z = z + 1;
	}
	keygen[1] = ((char *)lett)[(a ^ 79) & 63];
	/* ----------- f3 ----------- */
	a = 1;
	z = 0;
	while (z < l)
	{
		a = argv[1][z] * a;
		z = z + 1;
	}
	keygen[2] = ((char *)lett)[(a ^ 85) & 63];
	/* ----------- f4 ----------- */
	keygen[3] = ((char *)lett)[big_num(argv[1], l)];
	/* ----------- f5 ----------- */
	keygen[4] = ((char *)lett)[mul_char(argv[1], )];
	/* ----------- f6 ----------- */
	keygen[5] = ((char *)lett)[r_char(argv[1])];
	keygen[6] = '\0';
	for (a = 0; keygen[a]; a++)
		printf("%c", keygen[a]);
	return (0);
}
