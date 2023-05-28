#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void add_details(){
    // system("cls");
    printf("add");
    getch();
}

void track_periods(){
    // system("cls");
    printf("track");
    getch();
}

void edit_details(){
    // system("cls");
    printf("edit");
    getch();
}

void main(){
    int ch;
    printf("\n\n\t-----------------------------------------\n");
    printf("\t\t\tMENSTURA\n");
    printf("\t-----------------------------------------");
    while (1)
    {
        printf("\n\n\t\t\tMAIN MENU");
        printf("\n\n\t\tADD DETAILS\t[ENTER-1]");
        printf("\n\n\t\tTRACK PERIODS\t[ENTER-2]");
        printf("\n\n\t\tEDIT DETAILS\t[ENTER-3]");
        printf("\n\n\t\t\tEXIT\t[ENTER-4]");
        printf("\n\n\t=> ENTER YOUR CHOICE: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                add_details();
                break;
            case 2:
                track_periods();
                break;
            case 3:
                edit_details();
                break;
            case 4:
                exit(0);
            default:
                printf("\n\tYOU HAVE ENTERED WRONG CHOICE");
                printf("\n\tPRESS ANY KEY TO TRY AGAIN");
                getch();
                break;
        }
    system("cls");
    }
}