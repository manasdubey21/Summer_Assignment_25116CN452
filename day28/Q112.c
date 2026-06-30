#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact
{
    char name[50];
    char phone[20];
    char email[50];
};

void addContact()
{
    struct Contact c;
    FILE *fp = fopen("contacts.dat", "ab");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    printf("\nEnter Name: ");
    scanf(" %[^\n]", c.name);
    printf("Enter Phone Number: ");
    scanf(" %[^\n]", c.phone);
    printf("Enter Email: ");
    scanf(" %[^\n]", c.email);

    fwrite(&c, sizeof(struct Contact), 1, fp);
    fclose(fp);
    printf("Contact added successfully!\n");
}

void viewContacts()
{
    struct Contact c;
    FILE *fp = fopen("contacts.dat", "rb");
    if (fp == NULL)
    {
        printf("\nNo contacts found or file empty.\n");
        return;
    }
    printf("\n================ ALL CONTACTS ================\n");
    printf("%-20s %-20s %-30s\n", "Name", "Phone", "Email");
    printf("----------------------------------------------------\n");
    while (fread(&c, sizeof(struct Contact), 1, fp))
    {
        printf("%-20s %-20s %-30s\n", c.name, c.phone, c.email);
    }
    printf("====================================================\n");
    fclose(fp);
}

void searchContact()
{
    struct Contact c;
    char searchName[50];
    int found = 0;
    FILE *fp = fopen("contacts.dat", "rb");
    if (fp == NULL)
    {
        printf("\nNo contacts found to search.\n");
        return;
    }
    printf("\nEnter Name to search: ");
    scanf(" %[^\n]", searchName);

    while (fread(&c, sizeof(struct Contact), 1, fp))
    {
        if (strcasecmp(c.name, searchName) == 0)
        {
            if (!found)
            {
                printf("\nContact Found:\n");
                printf("------------------------------------\n");
            }
            printf("Name : %s\n", c.name);
            printf("Phone: %s\n", c.phone);
            printf("Email: %s\n\n", c.email);
            found = 1;
        }
    }
    if (!found)
    {
        printf("Contact not found.\n");
    }
    fclose(fp);
}

void deleteContact()
{
    struct Contact c;
    char deleteName[50];
    int found = 0;
    FILE *fp = fopen("contacts.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (fp == NULL)
    {
        printf("\nNo contacts found to delete.\n");
        if (temp)
            fclose(temp);
        return;
    }
    printf("\nEnter Name to delete: ");
    scanf(" %[^\n]", deleteName);

    while (fread(&c, sizeof(struct Contact), 1, fp))
    {
        if (strcasecmp(c.name, deleteName) == 0)
        {
            found = 1;
        }
        else
        {
            fwrite(&c, sizeof(struct Contact), 1, temp);
        }
    }
    fclose(fp);
    fclose(temp);

    if (found)
    {
        remove("contacts.dat");
        rename("temp.dat", "contacts.dat");
        printf("Contact deleted successfully.\n");
    }
    else
    {
        remove("temp.dat");
        printf("Contact not found.\n");
    }
}

int main()
{
    int choice;
    do
    {
        printf("\n*** CONTACT MANAGEMENT SYSTEM ***\n");
        printf("1. Add New Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice)
        {
        case 1:
            addContact();
            break;
        case 2:
            viewContacts();
            break;
        case 3:
            searchContact();
            break;
        case 4:
            deleteContact();
            break;
        case 5:
            printf("Exiting system. Goodbye!\n");
            break;
        default:
            printf("Invalid selection! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
