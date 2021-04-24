/**
 * @file tic_tac_toe.c Asish Sankhyan
 * @brief A tow player board game implemented in c called tic tac toe 
 * @version 0.1
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int checkWin();
/**
 * @brief A continuos function to draw a board on the screen continously is a void function and returns nothing 
 * 
 */
void draw()
{
    system("cls");
    printf("\n\n\t Tic Tac Toe \n\n");
    printf("Player1 (X) - Player2 (O) \n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", square[1], square[2], square[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", square[4], square[5], square[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", square[7], square[8], square[9]);
    printf("     |     |     \n");
}
/**
 * @brief The main function
 * 
 * @return int 
 */
int main()
{
    system("color 4a");
    int player = 1, i, choice;
    char mark; // X,O
    do
    {
        draw();
        player = (player % 2) ? 1 : 2;
        printf("Player %d, enter the choice : ", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O';
        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else
        {
            printf("Invalid option !");
            player--;
            getch();
        }
        i = checkWin();
        player++;

    } while (i == -1);

    draw();
    if (i == 1)
    {
        printf("==>Player %d won", --player);
        // PlaySound(TEXT("C:\\Users\\dell\\Music\\win.wav"), NULL, SND_SYNC);
    }
    else
    {
        printf("==>Game draw");
    }
    getch();
    return 0;
}
/**
 * @brief checks whether eihter of the player won the game and returns respectively
 * 
 * @return int an binary value to check if a player wins
 */
int checkWin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}
