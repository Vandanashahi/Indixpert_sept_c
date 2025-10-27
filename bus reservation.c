#include <stdio.h>

#define Max_User 3

struct User {
    char username[30];
    char userpass[30];
};

struct User users[Max_User];
int countUser = 0;


void signUp();
int signIn();
void dashboard(int userIndex);
int compareText(char str1[], char str2[]);


int compareText(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i])
            return 1;
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0')
        return 0;
    else
        return 1;
}


void signUp() {
    if (countUser >= Max_User) {
        printf("User limit reached!\n");
        return;
    }

    printf("\n=== SIGN UP ===\n");
    printf("Enter username: ");
    scanf("%s", users[countUser].username);
    printf("Enter password: ");
    scanf("%s", users[countUser].userpass);

    countUser++;
    printf("Account created successfully!\n");
}


int signIn() {
    char name[30], pass[30];
    int i;

    printf("\n=== SIGN IN ===\n");
    printf("Username: ");
    scanf("%s", name);
    printf("Password: ");
    scanf("%s", pass);

    i = 0;
    while (i < countUser) {
        if (compareText(name, users[i].username) == 0 &&
            compareText(pass, users[i].userpass) == 0) {
            printf("Login successful. Welcome, %s!\n", users[i].username);
            return i;
        }
        i++;
    }

    printf("Wrong username or password!\n");
    return -1;
}


void dashboard(int userIndex) {
    int choice = 0;

    while (choice != 2) {
        printf("\n=== USER MENU ===\n");
        printf("1. Logout\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Logging out...\n");
            return;  
        } else if (choice == 2) {
            printf("Exiting the system...\n");
            exit(0);
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
}


int main() {
    int choice = 0, loggedIn = -1;

    while (choice != 3) {
        printf("\n************* BUS RESERVATION SYSTEM *************\n");
        printf("1. Sign Up\n");
        printf("2. Sign In\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            signUp();
        } else if (choice == 2) {
            loggedIn = signIn();
            if (loggedIn != -1)
                dashboard(loggedIn); 
        } else if (choice == 3) {
            printf("Thank you for using the system. Goodbye!\n");
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

   return 0;
}