#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av)
{
	long unsigned int i, n, p = 0, q = 0;
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
		for (i = 2; i < n; i++)
		{
			if (n % i == 0)
			{
				p = n / i;
				q = i;
				break;
			}
		}
		if (p && q)
		{
			printf("%lu=%lu*%lu\n", n, p, q);
		}
	}
	fclose(file);
	free(line);
	return (0);
}
