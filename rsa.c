#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int isPrime(unsigned int n)
{
	unsigned int i, h;

	h = n / 2;
	for (i = 2; i < h; i++)
	{
		if (n % i == 0)
			return (0);
	}
	return (1);
}

int main(int ac, char **av)
{
	long unsigned int iter, n, p = 0, q = 0;
	FILE *file;
	char *line;
	size_t bufsize = 0;

	if (ac != 2)
	{
		fprintf(stderr, "%s <file>\n", av[0]);
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Cannot open %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &bufsize, file)) != -1)
	{
		sscanf(line, "%lu", &n);
		for (iter = 2; iter < n; iter++)
		{
			if (n % iter == 0)
			{
				if (isPrime(iter))
				{
					if (isPrime(n / iter))
					{
						p = n / iter;
						q = iter;
						break;
					}
				}
			}
		}
		if (p && q)
		{
			printf("%lu=%lu*%lu\n", n, p, q);
		}
		else
			printf("%lu=%lu*1\n", n, n);
		free(line);
		line = NULL;
	}
	fclose(file);
	return (0);
}
