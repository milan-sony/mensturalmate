#include <stdio.h>
#include <stdlib.h>

// Structure to hold period details
struct Period {
    int day;
    int month;
    int cycleLength;
    int periodLength;
};

// Function to add period details
void addPeriodDetails(struct Period *period) {
    printf("Enter last period date (DD MM): ");
    scanf("%d %d", &(period->day), &(period->month));
    
    printf("Enter cycle length (in days): ");
    scanf("%d", &(period->cycleLength));
    
    printf("Enter period length (in days): ");
    scanf("%d", &(period->periodLength));
    
    printf("Period details added successfully!\n");
}

// Function to view period details
void viewPeriodDetails(struct Period period) {
    printf("Last period date: %d/%d\n", period.day, period.month);
    printf("Cycle length: %d days\n", period.cycleLength);
    printf("Period length: %d days\n", period.periodLength);
}

// Function to edit period details
void editPeriodDetails(struct Period *period) {
    printf("Edit last period date (DD MM): ");
    scanf("%d %d", &(period->day), &(period->month));
    
    printf("Edit cycle length (in days): ");
    scanf("%d", &(period->cycleLength));
    
    printf("Edit period length (in days): ");
    scanf("%d", &(period->periodLength));
    
    printf("Period details edited successfully!\n");
}

// Function to calculate period dates for the next 3 months
void calculatePeriodDates(struct Period period) {
    printf("Period dates for the next 3 months:\n");
    
    int day = period.day;
    int month = period.month;
    
    for (int i = 0; i < 3; i++) {
        printf("%02d/%02d\n", day, month);
        
        day += period.cycleLength;
        if (day > 30) {
            day -= 30;
            month++;
        }
    }
}

// Function to save period details to a file
void saveToFile(struct Period period) {
    FILE *file = fopen("period_details.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    fprintf(file, "Last period date: %d/%d\n", period.day, period.month);
    fprintf(file, "Cycle length: %d days\n", period.cycleLength);
    fprintf(file, "Period length: %d days\n", period.periodLength);
    
    fclose(file);
    printf("Period details saved to file!\n");
}

int main() {
    struct Period period;
    int choice;
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Add period details\n");
        printf("2. View period details\n");
        printf("3. Edit period details\n");
        printf("4. Calculate period dates for the next 3 months\n");
        printf("5. Save period details to a file\n");
        printf("0. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addPeriodDetails(&period);
                break;
            case 2:
                viewPeriodDetails(period);
                break;
            case 3:
                editPeriodDetails(&period);
                break;
            case 4:
                calculatePeriodDates(period);
                break;
            case 5:
                saveToFile(period);
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}
