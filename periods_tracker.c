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

    printf("\n\tYOUR PERIOD DETAILS WHERE ADDED SUCCESSFULLY\n\n\tPRESS ANY KEY TO CONTINUE");
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

    printf("\n\tYOUR PERIOD DETAILS WERE UPDATED SUCCESSFULLY\n\n\tPRESS ANY KEY TO CONTINUE");

    getch();
}

// function to calculate next period dates
void calculate_next_period_dates(){

    printf("\n\n\tPERIOD DATES FOR THE NEXT 3 MONTHS\n\n");

    int day = periods.day;
    int month = periods.month;
    int year = periods.year;

    /*
    Calculate the period date for the next 3 months

    1. First iterate the loop for 3 times

    2. The next day is calculated by:
        next day => day + cycle length

    3. Here we assumes that the cycle length does not exceed the number of days in a month (30 in this case) and each month has only 30 days

    4. If the day is greater than (>) 30 (which indicates that the next period extends to the next month)
        subtract 30 from day to set it to the appropriate day within the month
    
    5. Then increment the value of the month by 1  to represent the next month

    6. After incrementing the month, it checks if the updated month value exceeds 12, indicating that the period extends to the next year

    7. If the month value is greater than 12, it sets month to 1 to represent January and increments the year variable by 1

    8. The loop continues until it completes 3 iterations, printing the dates for the next 3 months

    9. Finally, the function prints the message asking the user to press any key to continue and waits for a key press using getch()
    */

    for (int i = 0; i < 3; i++){
        day += periods.cycle_length;
        if (day > 30){
            day -= 30;
            month++;
            if (month > 12){
                month = 1;
                year++;
            }
        }
        printf("\t%d/%d/%d\n\n", day, month, year);
    }

    printf("\n\tPRESS ANY KEY TO CONTINUE");
    getch();
}

// function to save period details
void save_period_details(){
    int day = periods.day;
    int month = periods.month;
    int year = periods.year;

    // Create a file pointer
    FILE *file = fopen("period_dates.txt", "w");

    if (file == NULL)
    {
        printf("UNABLE TO CREATE THE FILE");
    }

    for (int i = 0; i < 3; i++){
        day += periods.cycle_length;
        if (day > 30){
            day -= 30;
            month++;
            if (month > 12){
                month = 1;
                year++;
            }
        }
        fprintf(file, "%d/%d/%d\n\n", day, month, year);
    }

    // close the file
    fclose(file);
    printf("\n\tPERIOD DATES FOR THE NEXT 3 MONTHS WERE SAVED IN 'period_dates.txt' FILE");
    printf("\n\n\tPRESS ANY KEY TO CONTINUE");
    getch();
}

// main function
void main(){

    int choice;
    while (1){
        printf("\n\n\t----------------------------------------------\n");
        printf("\t\t\tMENSTURALMATE\n");
        printf("\t-----------------------------------------------");
        printf("\n\n\t\t\t\tMAIN MENU");
        printf("\n\n\t\tADD DETAILS\t\t[PRESS-1]");
        printf("\n\n\t\tVIEW DETAILS\t\t[PRESS-2]");
        printf("\n\n\t\tEDIT DETAILS\t\t[PRESS-3]");
        printf("\n\n\t\tVIEW NEXT PERIOD DATES\t[PRESS-4]");
        printf("\n\n\t\tSAVE PERIOD DATES\t[PRESS-5]");
        printf("\n\n\t\tEXIT\t\t\t[PRESS-0]");
        printf("\n\n\t=> ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                add_period_details();
                break;
            case 2:
                view_period_details();
                break;
            case 3:
                edit_period_details();
                break;
            case 4:
                calculate_next_period_dates();
                break;
            case 5:
                save_period_details();
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
    getch();
}