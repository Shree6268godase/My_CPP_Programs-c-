#include<stdio.h>
#include<conio.h>
#include<ctime>
using namespace std;

int main()
{
    int number ,guess;

    srand(time(0));
    number = rand()%100+1;

    cout<< "guess the number between 1 and 100" <<end1;

    do
    {
        cout << "Enter your guess:";
        cin >>guess;

        if(guess>number)
         cout<< "Too high! Try again" <<end1;

         else if(guess < number)
         cout <<"Too Low! Try again" << end1;

         else 
         cout << "Congractulations! YOu guess corrct number" << end1;

    }while(guess != number);
    return 0;
}