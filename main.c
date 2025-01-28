#include <stdio.h>
#include <stdlib.h>
#include "file_operations.h"
#include "theme_manager.h"
#include "text_editor_utilities.h"

// Function declarations
void showMainMenu();
void handleMenuSelection(int choice);

int main() {
    int choice;

    // Main loop for the program
    do {
        showMainMenu();
        printf("\nEnter your choice: ");

        // Validate user input
        while (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number: ");
            // Clear the input buffer
            while (getchar() != '\n');
        }

        // Call the appropriate feature based on user input
        handleMenuSelection(choice);

    } while (choice != 6); // Exit option is 6

    printf("Exiting Editora. Goodbye!\n");
    return 0;
}

// Function to display the main menu
void showMainMenu() {
    printf("\n--- Editora Menu ---");
    printf("\n1. Create a new file");
    printf("\n2. Open and edit a file");
    printf("\n3. Change theme (Light/Dark)");
    printf("\n4. Word count");
    printf("\n5. Find and replace text");
    printf("\n6. Exit");
    printf("\n--------------------");
}

// Function to handle user selection
void handleMenuSelection(int choice) {
    switch (choice) {
        case 1:
            createNewFile(); // Call file creation function from file_operations.c
            break;
        case 2:
            openAndEditFile(); // Call file editing function from file_operations.c
            break;
        case 3:
            switchTheme(); // Call theme manager function
            break;
        case 4:
            countWords(); // Call word count function from text_editor_utilities.c
            break;
        case 5:
            findAndReplace(); // Call find-and-replace function from text_editor_utilities.c
            break;
        case 6:
            printf("Exiting Editora. Goodbye!\n"); // Exit option
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}
