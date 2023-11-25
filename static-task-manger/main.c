#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

typedef struct Task
{
	char	description[100];
	char	dueTime[100];
	char	Taskstatus[100];
}			Task;

void	removeNewline(char *str)
{
	char	*newline;

	newline = strchr(str, '\n');
	if (newline != NULL)
	{
		*newline = '\0';
	}
}

void	printFormattedDescription(char *description)
{
	int	len;
	int	half;

	len = strlen(description);
	half = len / 2;
	printf("%-20.*s\n%-20s", half, description, description + half);
}

void	addItem(Task *tasks, int size)
{
	int	i;

	for (i = 0; i < size; i++)
	{
		printf("Enter Task[%d] Description: ", i + 1);
		fgets(tasks[i].description, sizeof(tasks[i].description), stdin);
		removeNewline(tasks[i].description);
		printf("Enter Task[%d] Due Time: ", i + 1);
		fgets(tasks[i].dueTime, sizeof(tasks[i].dueTime), stdin);
		removeNewline(tasks[i].dueTime);
		printf("Enter Task[%d] Status: ", i + 1);
		fgets(tasks[i].Taskstatus, sizeof(tasks[i].Taskstatus), stdin);
		removeNewline(tasks[i].Taskstatus);
	}
}

/*print stars*/

void	printStars(void)
{
	int i, j, k;
	for (i = 0; i < 95; i++)
		printf("%c ", '*');
	for (j = 0; j < 10; j++)
	{
		/* code */
		printf("%-190c\n", '*');
		printf("%190c\n", '*');
	}
	for (k = 0; k < 95; k++)
	{
		/* code */
		printf("%c ", '*');
	}
	printf("\n");
}

int	main(void)
{
	Task	tasks[100];
	int		taskSize;

	int i, j;
	printf("How many Elements you want to store? ");
	scanf("%d", &taskSize);
	// printStars();
	getchar();
	addItem(tasks, taskSize);
	printf("\n");
	// Print tasks in a tabular format
	printf(GREEN "%-80s %-80s %-80s\n" RESET, "Description", "Due Time",
		"Status");
	for (i = 0; i < taskSize; i++)
	{
		// printFormattedDescription(tasks[i].description);
		printf("%-80s%-80s%-80s\n", tasks[i].description, tasks[i].dueTime,
			tasks[i].Taskstatus);
		system("clear");
		// printStars();
	}
	return (0);
}
