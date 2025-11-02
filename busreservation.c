#include <stdio.h>

#define Max_User 3
#define Max_Buses 4
#define Max_Seat 50

struct User {
    char username[30];
    char userpass[30];
};

struct Bus {
    int busNo;
    int seats[Max_Seat];
    float fare;
    char from[30];
    char to[30];
};

struct User users[Max_User];
struct Bus buses[Max_Buses];
int countUser = 0;

void signUp();
int signIn();
int compareText(char str1[], char str2[]);
void dashboard(int userIndex);
void viewBuses();
void bookSeat();
void deleteSeat();
void busDetails();


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
            printf("Login successful. Welcome, %s\n", users[i].username);
            return i;
        }
        i++;
    }
    
    printf("Wrong username or password!\n");
    return -1;
}


void dashboard(int userIndex) {
    int choice = 0;
    
    while (choice != 4) {
        printf("\n=== User Menu ===\n");
        printf("1. Reserve Seat\n");
        printf("2. Cancel Seat\n");
        printf("3. View Buses\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            bookSeat();
        } else if (choice == 2) {
             deleteSeat();
        } else if (choice == 3) {
             viewBuses();
        } else if (choice == 4) {
            printf("Logging out...\n");
        } else {
            printf("Invalid choice, try again.\n");
        }
    }
}


void busDetails() {
    sprintf(buses[0].from, "%s", "Delhi");
    sprintf(buses[0].to, "%s", "Bhopal");
    
    sprintf(buses[1].from, "%s", "Dehradun");
    sprintf(buses[1].to, "%s", "Haldwani");
    
    sprintf(buses[2].from, "%s", "Almora");
    sprintf(buses[2].to, "%s", "Bageshwar");

    sprintf(buses[3].from, "%s", "Nainital");
    sprintf(buses[3].to, "%s", "Rishikesh");
    
    int i = 0;
    while (i < Max_Buses) {
        buses[i].busNo = 100 + i;
        buses[i].fare = 500 + (i * 100);
        
        int j = 0;
        while (j < Max_Seat) {
            buses[i].seats[j] = 0;
            j++;
        }
        i++;
    }
}



void viewBuses() {
    int i, j, available, busNum, found = 0;
    
    printf("Enter Bus Number: ");
    scanf("%d", &busNum);
    printf("\n");
    
    for (i = 0; i < Max_Buses; i++) {
        if(buses[i].busNo == busNum){
            found = 1;
            available = 0;
            
            for (j = 0; j < Max_Seat; j++) {
                if (buses[i].seats[j] == 0) {
                    available++;
                }
            }
            
            printf("Bus Number       : %d\n", buses[i].busNo);
            printf("From             : %s\n", buses[i].from);
            printf("To               : %s\n", buses[i].to);
            printf("Total Seats      : %d\n", Max_Seat);
            printf("Available Seats  : %d\n", available);
            printf("Fare             : ₹%.2f\n", buses[i].fare);
            break;
        }
    }
    if (found == 0)
        printf("Invalid Bus Number!\n");
}

void bookSeat() {
    int busNo, seatNo, booked = 0;
    
    printf("Enter Bus Number: ");
    scanf("%d", &busNo);
    printf("Enter Number of Seats: ");
    scanf("%d", &seatNo);
    
    for (int i = 0; i < Max_Buses; i++) {
        if (buses[i].busNo == busNo) {
            for (int j = 0; j < Max_Seat && booked < seatNo; j++) {
                if (buses[i].seats[j] == 0) {
                    buses[i].seats[j] = 1;
                    booked++;
                }
            }
            
            if (booked == seatNo)
                printf("\nBooking Successful! %d seats booked on Bus Number %d\n", seatNo, busNo);
            else
                printf("\nOnly %d seats were available!\n", booked);
            
            return;
        }
    }
    
    printf("\nInvalid Bus Number!\n");
}

void deleteSeat() {
    int busNo, seatNo, cancelled = 0;
    
    printf("Enter Bus Number: ");
    scanf("%d", &busNo);
    printf("Enter Number of Seats: ");
    scanf("%d", &seatNo);
    
    for (int i = 0; i < Max_Buses; i++) {
        if (buses[i].busNo == busNo) {
            for (int j = 0; j < Max_Seat && cancelled < seatNo; j++) {
                if (buses[i].seats[j] == 1) {
                    buses[i].seats[j] = 0;
                    cancelled++;
                }
            }
            
            if (cancelled == seatNo)
                printf("\nCancellation Successful! %d seats cancelled on Bus Number %d\n", seatNo, busNo);
            else
                printf("\nOnly %d seats could be cancelled!\n", cancelled);
            
            return;
        }
    }
    
    printf("\nInvalid Bus Number!\n");
}
int main() {
    int choice = 0, loggedIn = -1;
    busDetails();
    
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
            printf("Goodbye!\n");
        } else {
            printf("Invalid choice, try again.\n");
        }
    }
    
   return 0;
}