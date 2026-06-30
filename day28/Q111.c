#include <stdio.h>
#include <string.h>

#define MAX_SEATS 5
#define TICKET_PRICE 150

struct Ticket
{
    int seatNumber;
    char passengerName[50];
    int isBooked;
};

int main()
{
    struct Ticket theater[MAX_SEATS];
    int choice;
    int targetSeat;
    int totalBooked = 0;

    for (int i = 0; i < MAX_SEATS; i++)
    {
        theater[i].seatNumber = i + 1;
        theater[i].isBooked = 0;
        strcpy(theater[i].passengerName, "");
    }

    while (1)
    {
        printf("\n*** TICKET BOOKING SYSTEM ***\n");
        printf("1. View Available Seats\n");
        printf("2. Book a Ticket\n");
        printf("3. Cancel a Ticket\n");
        printf("4. Show Revenue Summary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5)
        {
            printf("Exiting system. Thank you!\n");
            break;
        }

        switch (choice)
        {
        case 1:
            printf("\n--- Seating Chart ---\n");
            for (int i = 0; i < MAX_SEATS; i++)
            {
                if (theater[i].isBooked == 0)
                {
                    printf("Seat %d: [ AVAILABLE ]\n", theater[i].seatNumber);
                }
                else
                {
                    printf("Seat %d: [ BOOKED by %s ]\n", theater[i].seatNumber, theater[i].passengerName);
                }
            }
            break;

        case 2:
            if (totalBooked >= MAX_SEATS)
            {
                printf("\nError: All seats are fully booked!\n");
                break;
            }
            printf("\nEnter seat number (1-%d) to book: ", MAX_SEATS);
            scanf("%d", &targetSeat);

            if (targetSeat < 1 || targetSeat > MAX_SEATS)
            {
                printf("Invalid seat number choice!\n");
            }
            else if (theater[targetSeat - 1].isBooked == 1)
            {
                printf("Seat already reserved by someone else!\n");
            }
            else
            {
                printf("Enter passenger name: ");
                scanf(" %[^\n]s", theater[targetSeat - 1].passengerName);
                theater[targetSeat - 1].isBooked = 1;
                totalBooked++;
                printf("Success: Seat %d reserved for %s!\n", targetSeat, theater[targetSeat - 1].passengerName);
            }
            break;

        case 3:
            printf("\nEnter seat number (1-%d) to cancel: ", MAX_SEATS);
            scanf("%d", &targetSeat);

            if (targetSeat < 1 || targetSeat > MAX_SEATS)
            {
                printf("Invalid seat number selection!\n");
            }
            else if (theater[targetSeat - 1].isBooked == 0)
            {
                printf("This seat is already vacant!\n");
            }
            else
            {
                printf("Success: Registration for %s at seat %d has been removed.\n", theater[targetSeat - 1].passengerName, targetSeat);
                theater[targetSeat - 1].isBooked = 0;
                strcpy(theater[targetSeat - 1].passengerName, "");
                totalBooked--;
            }
            break;

        case 4:
            printf("\n--- Financial Summary ---\n");
            printf("Total Seats Sold: %d / %d\n", totalBooked, MAX_SEATS);
            printf("Total Revenue Generated: $%d\n", totalBooked * TICKET_PRICE);
            break;

        default:
            printf("Invalid selection! Please pick an option from 1 to 5.\n");
        }
    }

    return 0;
}
