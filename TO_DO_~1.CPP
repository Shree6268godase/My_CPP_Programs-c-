#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 10

struct Task
{
    char name[50];
    int completed;
};

struct Task t[MAX];
int count = 0;

void addTask()
{
    if(count >= MAX)
    {
	printf("\nTask list is full!");
	return;
    }

    printf("\nEnter task name: ");
    fflush(stdin);
    gets(t[count].name);

    t[count].completed = 0;
    count++;

    printf("Task added successfully!");
}

void viewTask()
{
    int i;
    if(count == 0)
    {
	printf("\nNo tasks available!");
	return;
    }

    printf("\n\n----- TASK LIST -----\n");
    for(i = 0; i < count; i++)
    {
	printf("%d. %s", i + 1, t[i].name);
	if(t[i].completed == 1)
	    printf(" [Completed]\n");
	else
	    printf(" [Pending]\n");
    }
}

void markCompleted()
{
    int n;
    viewTask();

    printf("\nEnter task number to mark completed: ");
    scanf("%d", &n);

    if(n > 0 && n <= count)
    {
	t[n - 1].completed = 1;
	printf("Task marked as completed!");
    }
    else
    {
	printf("Invalid task number!");
    }
}

void deleteTask()
{
    int i, n;
    viewTask();

    printf("\nEnter task number to delete: ");
    scanf("%d", &n);

    if(n > 0 && n <= count)
    {
	for(i = n - 1; i < count - 1; i++)
	{
	    t[i] = t[i + 1];
	}
	count--;
	printf("Task deleted successfully!");
    }
    else
    {
	printf("Invalid task number!");
    }
}

void main()
{
    int choice;
    clrscr();

    do
    {
	printf("\n\n==== TO-DO LIST MENU ====");
	printf("\n1. Add Task");
	printf("\n2. View Tasks");
	printf("\n3. Mark Task as Completed");
	printf("\n4. Delete Task");
	printf("\n5. Exit");
	printf("\nEnter your choice: ");
	scanf("%d", &choice);

	switch(choice)
	{
	    case 1: addTask(); break;
	    case 2: viewTask(); break;
	    case 3: markCompleted(); break;
	    case 4: deleteTask(); break;
	    case 5: printf("\nExiting program..."); break;
	    default: printf("\nInvalid choice!");
	}
    }
    while(choice != 5);

    getch();
}