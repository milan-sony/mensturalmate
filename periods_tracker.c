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

    if (periods.day == '\0'){
        printf("\n\n\t YOU HAVE NOT ADDED ANY DETAILS");
        printf("\n\n\t PRESS ANY KEY TO CONTINUE");
    }
    else{
        printf("\n\n\tVIEW DETAILS\n\n");

        printf("\tYOUR LAST PERIOD DATE\t: %d/%d/%d", periods.day,periods.month,periods.year);

        printf("\n\tCYCLE LENGTH\t\t: %d DAYS", periods.cycle_length);

        printf("\n\tPERIOD LENGTH\t\t: %d DAYS", periods.period_length);

        printf("\n\n\tPRESS ANY KEY TO CONTINUE");
    }
    getch();
}

// function to edit period details
void edit_period_details(){

    if (periods.day == '\0'){
        printf("\n\n\t YOU HAVE NOT ADDED ANY DETAILS");
        printf("\n\n\t PRESS ANY KEY TO CONTINUE");
    }
    else{
        printf("\n\n\tEDIT DETAILS\n\n");

        printf("\tYOUR LAST PERIOD DATE: %d/%d/%d", periods.day,periods.month,periods.year);
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
    }
    getch();
}

// function to calculate next period dates
void calculate_next_period_dates(){

    if (periods.day == '\0'){
        printf("\n\n\t YOU HAVE NOT ADDED ANY DETAILS");
        printf("\n\n\t PRESS ANY KEY TO CONTINUE");
    }
    else{
        printf("\n\n\tYOUR PERIOD DATES FOR THE NEXT 3 MONTHS ARE:\n\n");

        int day = periods.day;
        int month = periods.month;
        int year = periods.year;
        int days_in_month;

        for (int i = 0; i < 3; i++){

            // find number of days in a month
            if(month == 1){
                days_in_month = 31;
            }
            else if (month == 2){
                if (year % 2 == 0){
                    days_in_month = 29;
                }
                else{
                    days_in_month = 28;
                }
            }
            else if (month == 3){
                days_in_month = 31;
            }
            else if (month == 4){
                days_in_month = 30;
            }
            else if (month == 5){
                days_in_month = 31;
            }
            else if (month == 6){
                days_in_month = 30;
            }
            else if (month == 7){
                days_in_month = 31;
            }
            else if (month == 8){
                days_in_month = 30;
            }
            else if (month == 9){
                days_in_month = 31;
            }
            else if (month == 10){
                days_in_month = 30;
            }
            else if (month == 11){
                days_in_month = 31;
            }
            else if (month == 12){
                days_in_month = 30;
            }

            day += periods.cycle_length;

            if (day > days_in_month){
                day -= days_in_month;
                month++;
                if (month > 12){
                    month = 1;
                    year++;
                }
            }
            printf("\t=> \t%d/%d/%d\n\n", day, month, year);
        }
        printf("\n\tPRESS ANY KEY TO CONTINUE");
    }
    getch();
}

// function to save period details
void save_period_details(){

    if (periods.day == '\0'){

        printf("\n\n\t YOU HAVE NOT ADDED ANY DETAILS");
        printf("\n\n\t PRESS ANY KEY TO CONTINUE");

    }
    else{

        int day = periods.day;
        int month = periods.month;
        int year = periods.year;
        int days_in_month;

        // Create a file pointer
        FILE *file = fopen("period_details.txt", "w");

        if (file == NULL){
            printf("UNABLE TO CREATE THE FILE");
        }

        fprintf(file, "YOUR PERIOD DETAILS\n\n");
        fprintf(file, "=> Last period date\t: %d/%d/%d\n", periods.day, periods.month, periods.year);
        fprintf(file, "=> Cycle length\t\t: %d days\n", periods.cycle_length);
        fprintf(file, "=> Period length\t: %d days\n\n", periods.period_length);
        fprintf(file, "YOUR PERIOD DATES FOR THE NEXT 3 MONTHS ARE:\n\n");

        for (int i = 0; i < 3; i++){

            if(month == 1){
                days_in_month = 31;
            }
            else if (month == 2){
                if (year % 2 == 0){
                    days_in_month = 29;
                }
                else{
                    days_in_month = 28;
                }
            }
            else if (month == 3){
                days_in_month = 31;
            }
            else if (month == 4){
                days_in_month = 30;
            }
            else if (month == 5){
                days_in_month = 31;
            }
            else if (month == 6){
                days_in_month = 30;
            }
            else if (month == 7){
                days_in_month = 31;
            }
            else if (month == 8){
                days_in_month = 30;
            }
            else if (month == 9){
                days_in_month = 31;
            }
            else if (month == 10){
                days_in_month = 30;
            }
            else if (month == 11){
                days_in_month = 31;
            }
            else if (month == 12){
                days_in_month = 30;
            }

            day += periods.cycle_length;

            if (day > days_in_month){
                day -= days_in_month;
                month++;
                if (month > 12){
                    month = 1;
                    year++;
                }
            }
            fprintf(file, "=> %d/%d/%d\n\n", day, month, year);
        }

        // close the file
        fclose(file);
        printf("\n\tYOUR PERIOD DETAILS WERE SAVED SUCCESSFULLY IN 'period_details.txt' FILE");
        printf("\n\n\tPRESS ANY KEY TO CONTINUE");
    }
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
        printf("\n\n\t\tSAVE ALL DETAILS\t[PRESS-5]");
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
                printf("\n\n");
                exit(0);
            default:
                printf("\n\tYOU HAVE ENTERED WRONG CHOICE");
                printf("\n\n\tPRESS ANY KEY TO TRY AGAIN");
                getch();
                break;
        }

    system("cls");
    }
    getch();
}