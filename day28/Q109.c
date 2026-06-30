#include <stdio.h>

struct Book
{
    int id;
    char name[50];
    char author[50];
};

int main()
{
    struct Book b[100];
    int n = 0, choice, i, id, found;

    while (1)
    {
        printf("\n1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter Book ID: ");
            scanf("%d", &b[n].id);

            printf("Enter Book Name: ");
            scanf(" %[^\n]", b[n].name);

            printf("Enter Author Name: ");
            scanf(" %[^\n]", b[n].author);

            n++;
        }
        else if (choice == 2)
        {
            if (n == 0)
            {
                printf("No books available.\n");
            }
            else
            {
                for (i = 0; i < n; i++)
                {
                    printf("\nBook %d\n", i + 1);
                    printf("ID: %d\n", b[i].id);
                    printf("Name: %s\n", b[i].name);
                    printf("Author: %s\n", b[i].author);
                }
            }
        }
        else if (choice == 3)
        {
            printf("Enter Book ID to search: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (b[i].id == id)
                {
                    printf("Book Found\n");
                    printf("ID: %d\n", b[i].id);
                    printf("Name: %s\n", b[i].name);
                    printf("Author: %s\n", b[i].author);
                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                printf("Book not found.\n");
            }
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}