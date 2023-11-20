#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Callfunctions
{
	char	*opcode;
	int		(*ptr)(int, int);
}			call;

int	add(int a, int b)
{
	return (a + b);
}

int	minus(int a, int b)
{
	return (a - b);
}

int	main(void)
{
	int i, a, b;
	a = 100;
	b = 500;
	call operations[] = {{"add", add}, {"minus", minus}, {NULL, NULL}};

	char *choice = malloc(20); /* +1 for the null character */

	if (choice == NULL)
	{
		fprintf(stderr, "Memory Allocation Failed!\n");
		exit(EXIT_FAILURE);
	}

	printf("(add to sum) (minus to subtract): ");
	scanf("%s", choice);

	for (i = 0; operations[i].opcode != NULL; i++)
	{
		/* code */

		if (strcmp(choice, operations[i].opcode) == 0)
		{
			int result = operations[i].ptr(a, b);
			printf("%d\n", result);
			break;
		}
	}

	if (operations[i].opcode == NULL)
		printf("%s Invalid choice!\n", choice);
	free(choice);
	return (0);
}