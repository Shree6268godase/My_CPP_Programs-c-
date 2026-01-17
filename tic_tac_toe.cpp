#include <stdio.h>
#include <conio.h>

char board[9] = {'1','2','3','4','5','6','7','8','9'};
char player = 'X';

void showBoard()
{
    clrscr();
    printf("\n TIC TAC TOE GAME \n\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}


int checkWin()
{
    if(board[0]==player && board[1]==player && board[2]==player) return 1;
    if(board[3]==player && board[4]==player && board[5]==player) return 1;
    if(board[6]==player && board[7]==player && board[8]==player) return 1;

    if(board[0]==player && board[3]==player && board[6]==player) return 1;
    if(board[1]==player && board[4]==player && board[7]==player) return 1;
    if(board[2]==player && board[5]==player && board[8]==player) return 1;

    if(board[0]==player && board[4]==player && board[8]==player) return 1;
    if(board[2]==player && board[4]==player && board[6]==player) return 1;

    return 0;
}


void changePlayer()
{
    if(player == 'X')
        player = 'O';
    else
        player = 'X';
}

void main()
{
    int choice, i;
    clrscr();

    for(i = 0; i < 9; i++)
    {
        showBoard();
        printf("\nPlayer %c, enter your choice: ", player);
        scanf("%d", &choice);

        if(choice < 1 || choice > 9 || board[choice-1]=='X' || board[choice-1]=='O')
        {
            printf("\nInvalid move!");
            getch();
            i--;
            continue;
        }

        board[choice-1] = player;

        if(checkWin())
        {
            showBoard();
            printf("\nPlayer %c wins!", player);
            getch();
            return;
        }

        changePlayer();
    }

    showBoard();
    printf("\nGame Draw!");
    getch();
}