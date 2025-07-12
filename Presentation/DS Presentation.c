#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables for booked seats and previous stats
int bookedSeats[100] = {0}; // 1 indicates booked, 0 indicates available
typedef struct {
    char username[50];
    int trainNumber;
    int seatNumber;
    float amountPaid;
} PreviousStat;
PreviousStat previousStats[10];
int previousStatsCount = 0;
float defaultWalletBalance = 1000.0;

// Structure for linked list to manage train seats
typedef struct Seat {
    int seatNumber;
    struct Seat *next;
} Seat;

// Structure for train database
typedef struct Train {
    int trainNumber;
    char from[50];
    char to[50];
    char time[10];
    float fare;
} Train;

// Function prototypes
void registerUser();
int loginUser();
void reserveSeat();
void addFunds();
void deleteReservation();
void displayReceipt(int trainNumber, int seatNumber, float fare);
void displayAvailableTrains();
void displaySeats(Seat *head);
Seat* insertSeat(Seat *head, int seatNumber);

typedef struct {
    char username[50];
    char password[50];
    float walletBalance;
} User;

User users[10];
int userCount = 0;
int loggedInUser = -1;

// Train database
Train trains[] = {
    {1, "Mumbai", "Allahabad", "10:00 AM", 50.0},
    {2, "Chennai", "Delhi", "2:00 PM", 60.0},
    {3, "Kerala", "Kashmir", "6:00 PM", 70.0},
    {4, "Odisha", "Gujarat", "9:00 PM", 80.0}
};
int trainCount = 4;

void initializeUsers() {
    strcpy(users[0].username, "Aakash");
    strcpy(users[0].password, "1");
    users[0].walletBalance = 900.0;

    strcpy(users[1].username, "Anshuman");
    strcpy(users[1].password, "2");
    users[1].walletBalance = 1000.0;

    strcpy(users[2].username, "Kaustubh");
    strcpy(users[2].password, "3");
    users[2].walletBalance = 800.0;

    strcpy(users[3].username, "Kiran");
    strcpy(users[3].password, "4");
    users[3].walletBalance = 900.0;

    userCount = 4;
}

int main() {
    int choice;
    printf("Welcome to the Train Reservation System!\n");
    initializeUsers();

    while (1) {
        printf("\nDo you want to login or register?\n");
        printf("0. Login\n");
        printf("1. Register\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            registerUser();
        } else if (choice == 0) {
            if (loginUser()) {
                while (1) {
                    printf("\nWhat would you like to do?\n");
                    printf("1. Reserve a seat in train\n");
                    printf("2. Delete reservation\n");
                    printf("3. Add funds\n");
                    printf("4. Exit\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            reserveSeat();
                            break;
                        case 2:
                            deleteReservation();
                            break;
                        case 3:
                            addFunds();
                            break;
                        case 4:
                            printf("Exiting...\n");
                            exit(0);
                        default:
                            printf("Invalid choice. Try again.\n");
                    }
                }
            }
        } else {
            printf("Invalid input. Try again.\n");
        }
    }
}

void registerUser() {
    printf("Welcome to our family! Please register yourself.\n");
    printf("Enter username: ");
    scanf("%s", users[userCount].username);
    printf("Enter password: ");
    scanf("%s", users[userCount].password);
    users[userCount].walletBalance = 100.0;
    userCount++;
    printf("You have been registered successfully!\n");
}

int loginUser() {
    char username[50], password[50];
    int attempts = 3;

    while (attempts > 0) {
        printf("\nEnter your username: ");
        scanf("%s", username);

        for (int i = 0; i < userCount; i++) {
            if (strcmp(users[i].username, username) == 0) {
                printf("Enter your password: ");
                scanf("%s", password);
                if (strcmp(users[i].password, password) == 0) {
                    printf("Login successful!\n");
                    loggedInUser = i;
                    return 1;
                } else {
                    printf("Incorrect password. Try again.\n");
                    attempts--;
                }
            }
        }
        printf("Invalid username. Try again.\n");
        attempts--;
    }

    printf("Too many failed attempts. Exiting...\n");
    return 0;
}

void reserveSeat() {
    int trainChoice, seatChoice;
    Seat *head = NULL;

    displayAvailableTrains();
    printf("Choose a train (Enter train number): ");
    scanf("%d", &trainChoice);

    if (trainChoice < 1 || trainChoice > trainCount) {
        printf("Invalid train choice. Try again.\n");
        return;
    }

    // Create a seat list
    for (int i = 1; i <= 10; i++) {
        head = insertSeat(head, i);
    }

    printf("Available seats:\n");
    displaySeats(head);

    printf("Enter the seat number you want to book: ");
    scanf("%d", &seatChoice);

    if (bookedSeats[seatChoice]) {
        printf("Sorry, this seat is already booked. Try another.\n");
        return;
    }

    bookedSeats[seatChoice] = 1;
    users[loggedInUser].walletBalance -= trains[trainChoice - 1].fare;

    // Store in previous stats
    strcpy(previousStats[previousStatsCount].username, users[loggedInUser].username);
    previousStats[previousStatsCount].trainNumber = trainChoice;
    previousStats[previousStatsCount].seatNumber = seatChoice;
    previousStats[previousStatsCount].amountPaid = trains[trainChoice - 1].fare;
    previousStatsCount++;

    printf("Seat booked successfully!\n");
    displayReceipt(trainChoice, seatChoice, trains[trainChoice - 1].fare);
}

void deleteReservation() {
    int seatChoice;
    printf("Enter the seat number you want to cancel: ");
    scanf("%d", &seatChoice);

    if (!bookedSeats[seatChoice]) {
        printf("No booking found for this seat.\n");
        return;
    }

    bookedSeats[seatChoice] = 0;
    printf("Reservation cancelled successfully!\n");
}

void addFunds() {
    float amount;
    printf("Enter amount to add to wallet: ");
    scanf("%f", &amount);
    users[loggedInUser].walletBalance += amount;
    printf("Funds added successfully! Current balance: Rs.%.2f\n", users[loggedInUser].walletBalance);
}

void displayReceipt(int trainNumber, int seatNumber, float fare) {
    printf("\n**** Receipt ****\n");
    printf("Train Number: %d\n", trainNumber);
    printf("Seat Number: %d\n", seatNumber);
    printf("Amount Paid: Rs.%.2f\n", fare);
    printf("**********\n");
}
void displaySeats(Seat *head) {
    Seat *temp = head;
    printf("Seat Numbers: ");
    while (temp != NULL) {
        printf("%d ", temp->seatNumber);
        temp = temp->next;
    }
    printf("\n");
}
void displayAvailableTrains() {
    printf("Available trains:\n");
    for (int i = 0; i < trainCount; i++) {
        printf("%d. Train %d - From %s to %s - %s - Rs.%.2f\n",
               i + 1, trains[i].trainNumber, trains[i].from, trains[i].to, trains[i].time, trains[i].fare);
    }
}

Seat* insertSeat(Seat *head, int seatNumber) {
    Seat *newSeat = (Seat *)malloc(sizeof(Seat));
    newSeat->seatNumber = seatNumber;
    newSeat->next = head;
    return newSeat;
}