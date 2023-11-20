#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define arrSize 50
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

typedef struct User
{
	char	firstName[arrSize];
	char	lastName[arrSize];
	char	gender[arrSize];
	char	email[arrSize];
	char	phoneNumber[arrSize];
	char	password[arrSize];

}			User_L;

typedef struct Operations
{
	char	*opcode;
	void	(*ptr)(char *, char *);
}			Operations_t;

/*function to get user Input*/
char	*getUserInput(char *input)
{
	size_t	noBytes;
	size_t	inputSize;

	inputSize = 0;
	noBytes = getline(&input, &inputSize, stdin);
	if (noBytes == -1)
	{
		fprintf(stderr, "Eof Encounted\n");
		exit(EXIT_FAILURE);
	}
	return (input);
}

/*function to print the welcome mesage*/

void	welcome(void)
{
	const char	*text = "------------------------------------Welcome TO Command Line Login System----------------------------------------------\n";
	int			screenWidth;
	int			padding;

	screenWidth = 200;
	padding = (screenWidth - strlen(text)) / 2;
	printf(GREEN "%*s%s" RESET, padding, "", text);
}

/*function to get the user Input*/

/*Function to get the users choice*/

int	choice(int userChoice)
{
	printf("Please choose Your operation");
	printf("\n0.Signup\n1.Login\n2.Exit\n\n");
	scanf("%d", &userChoice);
	return (userChoice);
}

int	main(void)
{
    system("clear");
	welcome();

	int userChoice;
	userChoice = choice(userChoice);

	if (userChoice == 1)
		printf("SignUp succesfully\n");
	else
		printf("wrong signup\n");
	// char *input = NULL;
	// size_t noBytes;

	// input = getUserInput(input);

	// printf("%s\n", input);

	// free(input);
}