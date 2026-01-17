#include<stdio.h>
#include<conio.h>

void main()
{
 float a,b;
 int choice;
 clrscr();

 printf("***Simple Calculator");
 printf("\n 1.Addition \n2.Subtraction \n3.Multiplication \n 4.Division \n 5.Modulus \n 6.Exit");

 printf("Enter your choice \n");
 scanf("%d",&choice);

 printf("Enter first number \n");
 scanf("%f",&a);

 printf("Enter second number \n");
 scanf("%f",&b);

 switch(choice)
 {
  case 1:printf("Result is:",a+b);
	 break;

  case 2:printf("Result is:",a-b);
	 break;

  case 3:printf("Result is:",a*b);
	 break;

  case 4:if(b!=0)
	 {
	   printf("Result is:",a/b);
	 }
	 else
	 {
	  printf("Error:Division by zero");
	  }

	 break;

  case 5:printf("Result is:",a%b);
	 break;

  case 6:exit(0);
	 break;

  default:printf("Invalid selection");

  }

  getch();
 }