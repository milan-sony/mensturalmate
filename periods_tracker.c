#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// stucture to hold the period details
struct period_details
{
    int day;
    int month;
    int year;
    int cycle_length;
    int period_length;
}periods;

// function to add period details
void add_period_details(){
    printf("\n\n\tADD DETAILS\n\n");
    printf("\tWHEN DID YOUR LAST PERIOD START ?\n");
    printf("\n\tDAY(DD): ");
    scanf("%d", &periods.day);
    printf("\n\tMONTH(MM): ");
    scanf("%d", &periods.month);
    printf("\n\tYEAR(YYYY): ");
    scanf("%d", &periods.year);
    printf("\n\tYOUR PERIOD DETAILS ADDED SUCCESSFULLY (PRESS ANY KEY TO CONTINUE)");
    getch();
}

// function to view period details
void view_period_details(){
    printf("view");
    getch();
}

// function to edit period details
void edit_period_details(){
    printf("edit");
    getch();
}

// main function
void main(){
    int choice;
    printf("\n\n\t-----------------------------------------\n");
    printf("\t\t\tMENSTURA\n");
    printf("\t-----------------------------------------");
    while (1)
    {
        printf("\n\n\t\t\tMAIN MENU");
        printf("\n\n\t\tADD DETAILS\t[PRESS-1]");
        printf("\n\n\t\tVIEW DETAILS\t[PRESS-2]");
        printf("\n\n\t\tEDIT DETAILS\t[PRESS-3]");
        printf("\n\n\t\t\tEXIT\t[PRESS-0]");
        printf("\n\n\t=> ENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                add_period_details();
                break;
            case 2:
                view_period_details();
                break;
            case 3:
                edit_period_details();
                break;
            case 0:
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