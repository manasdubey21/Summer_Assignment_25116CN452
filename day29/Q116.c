#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item
{
    int id;
    char name[50];
    int quantity;
    float price;
};

int main()
{
    struct Item inventory[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    while (1)
    {
        printf("\n=== INVENTORY MANAGEMENT SYSTEM ===\n");
        printf("1. Add Item\n");
        printf("2. Display Inventory\n");
        printf("3. Search Item\n");
        printf("4. Update Quantity\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (itemCount >= MAX_ITEMS)
            {
                printf("Inventory is full!\n");
                continue;
            }

            struct Item newItem;
            int exists = 0;

            printf("Enter Item ID: ");
            scanf("%d", &newItem.id);

            for (int i = 0; i < itemCount; i++)
            {
                if (inventory[i].id == newItem.id)
                {
                    printf("Error: Item ID already exists!\n");
                    exists = 1;
                    break;
                }
            }

            if (exists)
            {
                continue;
            }

            printf("Enter Item Name: ");
            scanf("%s", newItem.name);
            printf("Enter Quantity: ");
            scanf("%d", &newItem.quantity);
            printf("Enter Price: ");
            scanf("%f", &newItem.price);

            inventory[itemCount] = newItem;
            itemCount++;
            printf("Item added successfully!\n");
        }
        else if (choice == 2)
        {
            if (itemCount == 0)
            {
                printf("Inventory is empty.\n");
                continue;
            }

            printf("\nID\tName\t\tQuantity\tPrice\n");
            printf("---------------------------------------------\n");
            for (int i = 0; i < itemCount; i++)
            {
                printf("%d\t%-15s\t%d\t\t$%.2f\n",
                       inventory[i].id,
                       inventory[i].name,
                       inventory[i].quantity,
                       inventory[i].price);
            }
        }
        else if (choice == 3)
        {
            if (itemCount == 0)
            {
                printf("Inventory is empty.\n");
                continue;
            }

            int searchId;
            int found = 0;

            printf("Enter Item ID to search: ");
            scanf("%d", &searchId);

            for (int i = 0; i < itemCount; i++)
            {
                if (inventory[i].id == searchId)
                {
                    printf("\nItem Found:\n");
                    printf("ID: %d\n", inventory[i].id);
                    printf("Name: %s\n", inventory[i].name);
                    printf("Quantity: %d\n", inventory[i].quantity);
                    printf("Price: $%.2f\n", inventory[i].price);
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("Item with ID %d not found.\n", searchId);
            }
        }
        else if (choice == 4)
        {
            if (itemCount == 0)
            {
                printf("Inventory is empty.\n");
                continue;
            }

            int updateId;
            int found = 0;

            printf("Enter Item ID to update quantity: ");
            scanf("%d", &updateId);

            for (int i = 0; i < itemCount; i++)
            {
                if (inventory[i].id == updateId)
                {
                    printf("Current Quantity: %d\n", inventory[i].quantity);
                    printf("Enter New Quantity: ");
                    scanf("%d", &inventory[i].quantity);
                    printf("Quantity updated successfully!\n");
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("Item with ID %d not found.\n", updateId);
            }
        }
        else if (choice == 5)
        {
            printf("Exiting system.\n");
            break;
        }
        else
        {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
