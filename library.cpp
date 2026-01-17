#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 10
#define FINE_PER_DAY 5

struct Book
{
    int id;
    char title[30];
    char author[30];
    int available;   // 1 = Available, 0 = Issued
};

struct Book b[MAX];
int count = 0;

void addBook()
{
    if(count >= MAX)
    {
        printf("\nLibrary is full!");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &b[count].id);

    printf("Enter Book Title: ");
    fflush(stdin);
    gets(b[count].title);

    printf("Enter Author Name: ");
    gets(b[count].author);

    b[count].available = 1;
    count++;

    printf("Book added successfully!");
}

void viewBooks()
{
    int i;
    if(count == 0)
    {
        printf("\nNo books available!");
        return;
    }

    printf("\n\nID\tTitle\t\tAuthor\t\tStatus\n");
    for(i = 0; i < count; i++)
    {
        printf("%d\t%s\t\t%s\t\t",
               b[i].id, b[i].title, b[i].author);

        if(b[i].available == 1)
            printf("Available\n");
        else
            printf("Issued\n");
    }
}

void searchBook()
{
    int id, i, found = 0;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(b[i].id == id)
        {
            printf("\nBook Found!");
            printf("\nTitle: %s", b[i].title);
            printf("\nAuthor: %s", b[i].author);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("\nBook not found!");
}

void issueBook()
{
    int id, i;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(b[i].id == id && b[i].available == 1)
        {
            b[i].available = 0;
            printf("Book issued successfully!");
            return;
        }
    }

    printf("Book not available!");
}

void returnBook()
{
    int id, days, i;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(b[i].id == id && b[i].available == 0)
        {
            printf("Enter number of late days: ");
            scanf("%d", &days);

            printf("Fine Amount = Rs. %d", days * FINE_PER_DAY);
            b[i].available = 1;
            printf("\nBook returned successfully!");
            return;
        }
    }

    printf("Invalid book ID!");
}

void main()
{
    int choice;
    clrscr();

    do
    {
        printf("\n\n===== LIBRARY MANAGEMENT SYSTEM =====");
        printf("\n1. Add Book");
        printf("\n2. View Books");
        printf("\n3. Search Book");
        printf("\n4. Issue Book");
        printf("\n5. Return Book");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: printf("\nExiting..."); break;
            default: printf("\nInvalid choice!");
        }
    }
    while(choice != 6);

    getch();
}