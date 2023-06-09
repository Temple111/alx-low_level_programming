/**
 * hash_djb2 - Hash function, takes a string and turns it into a hash number
 * @str: the string
 *
 * Return: 0 for success
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}
