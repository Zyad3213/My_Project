#include <stdio.h>
#define GREEN_FOREGROUND 2
#define RED_FOREGROUND 12
#include <windows.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
int count=0;
void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}
void setConsoleColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void printmatrix(int matrix[9][9])
{
    setConsoleColor(0xf9);
    printf("                _   _      _ _                    \n");
    printf("               | | | | ___| | | ___               \n");
    printf("               | |_| |/ _ \\ | |/ _ \\              \n");
    printf("               |  _  |  __/ | | (_) |             \n");
    printf("               |_| |_|\\___|_|_|\\___/              \n");
    printf("                                                  \n\n\n");

    setConsoleColor(0x4f);
    printf("\t\tWelcome to Sudoko Game\t\t  \n\n\n");


    for (int row = 0; row < 9; row++)
    {
        if(row==3||row==6)
        {
            setConsoleColor(0xff);
            printf("_________________________________________________\n");
            setConsoleColor(7);
        }
        for (int col = 0; col < 9; col++)
        {

            if(col==3||col==6)
            {
                setConsoleColor(0xff);
                printf("  ");
                setConsoleColor(7);
            }
            if(  (row==0 && col==0)||(row==0 && col==1)||(row==1 && col==3)
                    ||(row==4 && col==3)||(row==7 && col==3)||(row==1 && col==0)
                    ||(row==2 && col==1)||(row==2 && col==2)||(row==3 && col==0)
                    ||(row==4 && col==0)||(row==5 && col==0)||(row==6 && col==1)
                    ||(row==0 && col==4)||(row==1 && col==4)||(row==1 && col==5)
                    ||(row==2 && col==7)||(row==3 && col==4)||(row==4 && col==5)
                    ||(row==5 && col==4)||(row==3 && col==8)||(row==4 && col==8)
                    ||(row==5 && col==8)||(row==8 && col==8)||(row==7 && col==8)
                    ||(row==8 && col==7)||(row==8 && col==4)||(row==7 && col==4)
                    ||(row==7 && col==5)||(row==6 && col==6)||(row==6 && col==7))
            {
                setConsoleColor(0x0a);
                printf("| %d |", matrix[row][col]);
            }
            else if(matrix[row][col]==0)
            {
                setConsoleColor(0x0f);
                printf("|   |", matrix[row][col]);
            }
            else if(row==0 && col==0)
            {
                setConsoleColor(0x0a);
                printf("| %d |", matrix[row][col]);
            }
            else
            {
                setConsoleColor(RED_FOREGROUND);
                printf("| %d |", matrix[row][col]);
                setConsoleColor(7);
            }
        }
        printf("\n");
    }
}

int scanElement(int matrix[9][9])
{
    if(count==51)
    {
        for(int i=0; i<9; i++)
        {
            setConsoleColor(0x0b);
            printf("\n\t\tWinner \n");
            printf("         ____                            \n");
            printf("        |  _ \\  ___  _ _  ___            \n");
            printf("        | | | |/ _ \\| |  |/ _ \\          \n");
            printf("        | |_| | (_) | || |  __/          \n");
            printf("        |____/ \\___/|_||_|\\___|          \n");
            printf("                                       \n");

            delay(1);
            system("cls");
            setConsoleColor(0x0f);
            delay(1);
            setConsoleColor(0x0f);
        }
        setConsoleColor(7);
        return 0 ;
    }
    setConsoleColor(0x0f);
    int col, raw, num,flag_enter = 0, i, j ;


    setConsoleColor(0x0f);
    printf("\nEnter the raw : ");
    scanf("%d",&raw);
    printf("Enter the Column : ");
    scanf("%d",&col);

    printf("Enter a number from 1 to 9 :");
    scanf("%d",&num);

    if((raw>=0 && raw<9)&&(col>=0 && col<9)&&(num>=0 && num<10))
    {
        i=raw ;
        j=col ;

        flag_enter = 1 ;
        /** check **/
        for(i=0; i<9; i++)
        {
            if(matrix[i][col]==num)
            {
                flag_enter = 0 ;
            }
        }
        for(j=0; j<9; j++)
        {
            if(matrix[raw][j]==num)
            {
                flag_enter = 0 ;
            }
        }/** End check **/

        if(       (raw==0 && col==0)||(raw==0 && col==1)||(raw==1 && col==3)
                  ||(raw==4 && col==3)||(raw==7 && col==3)||(raw==1 && col==0)
                  ||(raw==2 && col==1)||(raw==2 && col==2)||(raw==3 && col==0)
                  ||(raw==4 && col==0)||(raw==5 && col==0)||(raw==6 && col==1)
                  ||(raw==0 && col==4)||(raw==1 && col==4)||(raw==1 && col==5)
                  ||(raw==2 && col==7)||(raw==3 && col==4)||(raw==4 && col==5)
                  ||(raw==5 && col==4)||(raw==3 && col==8)||(raw==4 && col==8)
                  ||(raw==5 && col==8)||(raw==8 && col==8)||(raw==7 && col==8)
                  ||(raw==8 && col==7)||(raw==8 && col==4)||(raw==7 && col==4)
                  ||(raw==7 && col==5)||(raw==6 && col==6)||(raw==6 && col==7))
        {
            setConsoleColor(RED_FOREGROUND);
            printf("********** Please Don`t Change in constant number ************\n");
            setConsoleColor(7);
            delay(1);
            system("cls");
            printmatrix(matrix);
        }
        if(flag_enter == 1 )
        {
            if(matrix[raw][col]==0)
                count++;

            matrix[raw][col]=num ;

            delay(1);
            system("cls");
            printmatrix(matrix);
        }
        else
        {
            setConsoleColor(RED_FOREGROUND);
            Beep(1000, 500);
            printf("********** Wrong Data Please chose another number ************\n");
            setConsoleColor(7);
            delay(1);
            system("cls");
            printmatrix(matrix);
        }
    }
    else
    {
        Beep(1000, 500);
        setConsoleColor(RED_FOREGROUND);
        printf("********** Wrong Data Please Enter Number From  1 to 9 ************\n");
        setConsoleColor(7);
        delay(1);
        system("cls");
        printmatrix(matrix);
    }

    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(matrix[i][j]!=0)
            {
                scanElement(matrix);
            }
        }
    }


}

int main()
{

    int matrix [9][9] =
    {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    printmatrix( matrix);
    scanElement(matrix);
    return 0 ;
}

