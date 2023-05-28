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
    printf("\tDAY(DD): ");
    scanf("%d", &periods.day);
    printf("\tMONTH(MM): ");
    scanf("%d", &periods.month);
    printf("\tYEAR(YYYY): ");
    scanf("%d", &periods.year);
    printf("\n\n\tWHATS YOUR CYCLE LENGTH ?\n");
    printf("\t(DAYS FROM THE FIRST DAY OF YOUR PERIOD TO A DAY BEFORE THE NEXT PERIOD)\n");
    printf("\tENTER THE NUMBER IN DAYS(DD): ");
    scanf("%d", &periods.cycle_length);
    printf("\n\n\tWHATS YOUR PERIOD LENGTH ?\n");
    printf("\tENTER THE NUMBER IN DAYS(DD): ");
    scanf("%d", &periods.period_length);
    printf("\n\tYOUR PERIOD DETAILS WHERE ADDED SUCCESSFULLY (PRESS ANY KEY TO CONTINUE)");
    getch();
}

// function to view period details
void view_period_details(){
    printf("\n\n\tVIEW DETAILS\n\n");
    printf("\tLAST PERIOD DATE: %d/%d/%d", periods.day,periods.month,periods.year);
    printf("\n\tCYCLE LENGTH: %d DAYS", periods.cycle_length);
    printf("\n\tPERIOD LENGTH: %d DAYS", periods.period_length);
    printf("\n\n\tPRESS ANY KEY TO CONTINUE");
    getch();
}

// function to edit period details
void edit_period_details(){
    printf("\n\n\tEDIT DETAILS\n\n");
    printf("\tLAST PERIOD DATE: %d/%d/%d", periods.day,periods.month,periods.year);
    printf("\n\tEDIT YOUR LAST PERIOD DATE\n");
    printf("\tDAY(DD): ");
    scanf("%d", &periods.day);
    printf("\tMONTH(MM): ");
    scanf("%d", &periods.month);
    printf("\tYEAR(YYYY): ");
    scanf("%d", &periods.year);
    printf("\n\n\tEDIT YOUR CYCLE LENGTH\n");
    printf("\t(DAYS FROM THE FIRST DAY OF YOUR PERIOD TO A DAY BEFORE THE NEXT PERIOD)\n");
    printf("\n\tLAST CYCLE LENGTH: %d DAYS", periods.cycle_length);
    printf("\n\tEDIT THE NUMBER IN DAYS(DD): ");
    scanf("%d", &periods.cycle_length);
    printf("\n\n\tEDIT YOUR PERIOD LENGTH\n");
    printf("\n\tLAST PERIOD LENGTH: %d DAYS", periods.period_length);
    printf("\n\tEDIT THE NUMBER IN DAYS(DD): ");
    scanf("%d", &periods.period_length);
    printf("\n\tYOUR PERIOD DETAILS WHERE UPDATED SUCCESSFULLY (PRESS ANY KEY TO CONTINUE)");
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