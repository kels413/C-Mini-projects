#include <stdio.h>
#include <stdlib.h>

#define arrSize 20

typedef struct User {
    char *firstName;
    char *lastName;
    char *gender;
    char *email;
    char *phoneNumber;
    char *password;
} User_L;

void getUserInputField(char **field, size_t *inputSize, const char *fieldName) {
    printf("Enter %s: ", fieldName);
    ssize_t noBytes = getline(field, inputSize, stdin);
    if (noBytes == -1) {
        fprintf(stderr, "\nEOF Encountered\n");
        exit(EXIT_FAILURE);
    }
}

void getUserInput(User_L *user) {
    size_t inputSize = 0;

    user->firstName = malloc(arrSize * sizeof(char));
    user->lastName = malloc(arrSize * sizeof(char));
    user->gender = malloc(arrSize * sizeof(char));
    user->email = malloc(arrSize * sizeof(char));
    user->phoneNumber = malloc(arrSize * sizeof(char));
    user->password = malloc(arrSize * sizeof(char));

    if (user->firstName == NULL || user->lastName == NULL ||
        user->gender == NULL || user->email == NULL ||
        user->phoneNumber == NULL || user->password == NULL) {
        fprintf(stderr, "Memory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }

    getUserInputField(&user->firstName, &inputSize, "FirstName");
    getUserInputField(&user->lastName, &inputSize, "LastName");
    getUserInputField(&user->gender, &inputSize, "gender");
    getUserInputField(&user->email, &inputSize, "email");
    getUserInputField(&user->phoneNumber, &inputSize, "phoneNumber");
    getUserInputField(&user->password, &inputSize, "password");
}

int main(void) {
    User_L user;

    getUserInput(&user);

    printf("First Name: %s\n", user.firstName);
    printf("Last Name: %s\n", user.lastName);
    printf("Gender: %s\n", user.gender);
    printf("Email: %s\n", user.email);
    printf("Phone Number: %s\n", user.phoneNumber);
    printf("Password: %s\n", user.password);

    // Don't forget to free memory when you're done
    free(user.firstName);
    free(user.lastName);
    free(user.gender);
    free(user.email);
    free(user.phoneNumber);
    free(user.password);

    return 0;
}
