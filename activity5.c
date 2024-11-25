#include <stdio.h>
#include <string.h>
#include <unistd.h> // For sleep() function

// Function prototypes
void login(char username[], char password[]);
void checkBalance(float balance);
void depositMoney(float *balance);
void withdrawMoney(float *balance);
// Recursive function for countdown
void countdown(int n) {
    if (n < 0) {
       
        return;
    }
    
   
    sleep(1); // Pause for 1 second
    countdown(n - 1); // Recursive call with n-1
}

int main()
{   
    int start=4;

  

    char username[50], password[50], correctUsername[50], correctPassword[50];
    float balance = 1000.00; // Initial balance
    int choice;

    strcpy(correctUsername, "user123"); // Set correct username
    strcpy(correctPassword, "pass123"); // Set correct password
    start:
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    login(username, password);
   
    if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0)
    {
        printf("Checking Username and Password!\n");
            countdown(start);
            printf("Username and Password is correct!\n");
        while (1)
        {    

            printf("\nATM System:\n");
            printf("1. Check Balance\n");
            printf("2. Deposit Money\n");
            printf("3. Withdraw Money\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                depositMoney(&balance);
                break;
            case 3:
                withdrawMoney(&balance);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
            }
        }
    }
    else
    {   printf("Checking Username and Password!\n");
        countdown(start);
        printf("Invalid username or password. Access denied.\n");
        printf("Hint:\n");
        printf("Length is:%zu", strlen(correctPassword));
        printf("\n");
        goto start;
    }

    return 0;
}

void login(char username[], char password[])
{
    // This function is to simulate user login (doesn't do much in this simple version)
    printf("Welcome, %s!\n", username);
}

void checkBalance(float balance)
{
    printf("Your current balance is: %.2f\n", balance);
}

void depositMoney(float *balance)
{
    float deposit;
    printf("Enter the amount to deposit: ");
    scanf("%f", &deposit);
    if (deposit > 0)
    {
        *balance += deposit;
        printf("Successfully deposited %.2f\n", deposit);
    }
    else
    {
        printf("Invalid deposit amount.\n");
    }
}

void withdrawMoney(float *balance)
{
    float withdrawal;
    printf("Enter the amount to withdraw: ");
    scanf("%f", &withdrawal);
    if (withdrawal > 0 && withdrawal <= *balance)
    {
        *balance -= withdrawal;
        printf("Successfully withdrew %.2f\n", withdrawal);
    }
    else
    {
        printf("Invalid withdrawal amount or insufficient funds.\n");
    }
}