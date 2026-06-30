#include <stdio.h>
#include <string.h>

struct Book
{
    int id;
    char title[50];
    char author[50];
    int is_issued;
};

void clear_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    struct Book library[100];
    int book_count = 0;
    int choice;
    int search_id;
    int found;

    do
    {
        printf("\n--- MINI LIBRARY SYSTEM ---\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid selection.\n");
            clear_buffer();
            continue;
        }
        clear_buffer();

        switch (choice)
        {
        case 1:
            if (book_count >= 100)
            {
                printf("Library storage is full.\n");
                break;
            }
            printf("Enter Book ID (Integer): ");
            scanf("%d", &library[book_count].id);
            clear_buffer();

            printf("Enter Book Title: ");
            scanf(" %[^\n]", library[book_count].title);
            clear_buffer();

            printf("Enter Author Name: ");
            scanf(" %[^\n]", library[book_count].author);
            clear_buffer();

            library[book_count].is_issued = 0;
            book_count++;
            printf("Book successfully added.\n");
            break;

        case 2:
            if (book_count == 0)
            {
                printf("No books available in the library.\n");
                break;
            }
            printf("\n%-10s %-25s %-20s %-10s\n", "ID", "Title", "Author", "Status");
            printf("------------------------------------------------------------------\n");
            for (int i = 0; i < book_count; i++)
            {
                printf("%-10d %-25s %-20s %-10s\n",
                       library[i].id,
                       library[i].title,
                       library[i].author,
                       library[i].is_issued ? "Issued" : "Available");
            }
            break;

        case 3:
            if (book_count == 0)
            {
                printf("No books available to search.\n");
                break;
            }
            printf("Enter Book ID to search: ");
            scanf("%d", &search_id);
            clear_buffer();

            found = 0;
            for (int i = 0; i < book_count; i++)
            {
                if (library[i].id == search_id)
                {
                    printf("\nBook Found:\n");
                    printf("ID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n",
                           library[i].id, library[i].title, library[i].author,
                           library[i].is_issued ? "Issued" : "Available");
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                printf("Book with ID %d not found.\n", search_id);
            }
            break;

        case 4:
            printf("Enter Book ID to issue: ");
            scanf("%d", &search_id);
            clear_buffer();

            found = 0;
            for (int i = 0; i < book_count; i++)
            {
                if (library[i].id == search_id)
                {
                    found = 1;
                    if (library[i].is_issued == 1)
                    {
                        printf("Book is already issued out.\n");
                    }
                    else
                    {
                        library[i].is_issued = 1;
                        printf("Book successfully issued.\n");
                    }
                    break;
                }
            }
            if (!found)
            {
                printf("Book ID not found.\n");
            }
            break;

        case 5:
            printf("Enter Book ID to return: ");
            scanf("%d", &search_id);
            clear_buffer();

            found = 0;
            for (int i = 0; i < book_count; i++)
            {
                if (library[i].id == search_id)
                {
                    found = 1;
                    if (library[i].is_issued == 0)
                    {
                        printf("Book was not issued out.\n");
                    }
                    else
                    {
                        library[i].is_issued = 0;
                        printf("Book successfully returned.\n");
                    }
                    break;
                }
            }
            if (!found)
            {
                printf("Book ID not found.\n");
            }
            break;

        case 6:
            printf("Exiting mini library system.\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
