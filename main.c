#include <stdio.h>
#include <stdlib.h>
#include "bus_tracking.h"

// CGPA Calculator function (extracted from original cgpa.c)
void calculate_cgpa() {
    printf("\n=== CGPA CALCULATOR ===\n");
    int numSubjects = 3; // Fixed number of subjects
    float totalPoints = 0.0, totalCredits = 0.0;

    // Loop through each subject to get grades and credit hours
    for (int i = 0; i < numSubjects; i++) {
        char grade;
        int credits;
        float gradePoints;

        // Input credit hours
        printf("Enter credit hours for subject %d: ", i + 1);
        scanf("%d", &credits);

        // Input grade
        printf("Enter grade for subject %d (A, B, C, D, F): ", i + 1);
        scanf(" %c", &grade);  // Note the space before %c to consume any leftover newline

        // Convert grade to grade points
        switch (grade) {
            case 'A':
                gradePoints = 4.0;
                break;
            case 'B':
                gradePoints = 3.0;
                break;
            case 'C':
                gradePoints = 2.0;
                break;
            case 'D':
                gradePoints = 1.0;
                break;
            case 'F':
                gradePoints = 0.0;
                break;
            default:
                printf("Invalid grade entered.\n");
                return; // Return instead of exit for better integration
        }

        // Calculate total points and credits
        totalPoints += (gradePoints * credits);
        totalCredits += credits;
    }

    // Calculate CGPA
    if (totalCredits > 0) {
        float cgpa = totalPoints / totalCredits;
        printf("Your CGPA is: %.2f\n", cgpa);
    } else {
        printf("No credits entered. Cannot calculate CGPA.\n");
    }
}

void display_main_menu() {
    printf("\n=== STUDENT MANAGEMENT SYSTEM ===\n");
    printf("1. CGPA Calculator\n");
    printf("2. Bus Tracking System\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void run_bus_tracking_system() {
    initialize_bus_system();
    
    int choice;
    do {
        display_bus_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                display_all_buses();
                break;
            case 2:
                display_all_routes();
                break;
            case 3:
                track_bus_location();
                break;
            case 4:
                add_bus();
                break;
            case 5:
                add_route();
                break;
            case 6:
                update_bus_status();
                break;
            case 7:
                board_passenger();
                break;
            case 8:
                display_passengers();
                break;
            case 9:
                simulate_bus_movement();
                break;
            case 0:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
}

int main() {
    int choice;
    
    printf("Welcome to the Student Management System!\n");
    
    do {
        display_main_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                calculate_cgpa();
                break;
            case 2:
                run_bus_tracking_system();
                break;
            case 3:
                printf("Thank you for using the Student Management System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);
    
    return 0; // Successful execution
}