#include <stdio.h>
#include <stdlib.h>
#include "file_operations.h"

// Function to create a new file
void createNewFile() {
    char filename[100];
    FILE *file;

    printf("Enter the name of the new file (with extension): ");
    if (scanf("%99s", filename) != 1) { // Use %99s to prevent buffer overflow
        printf("Invalid input.\n");
        return;
    }

    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating file"); // Use perror to provide detailed error message
        return;
    }

    printf("File '%s' created successfully.\n", filename);
    fclose(file);
}

// Function to open and edit a file
void openAndEditFile() {
    char filename[100];
    char content[1000];
    FILE *file;

    printf("Enter the name of the file to open: ");
    if (scanf("%99s", filename) != 1) { // Use %99s to prevent buffer overflow
        printf("Invalid input.\n");
        return;
    }

    file = fopen(filename, "r+");
    if (file == NULL) {
        perror("Error opening file"); // Use perror to provide detailed error message
        return;
    }

    printf("\nEnter new content to append: ");
    getchar(); // Clear newline character from the input buffer
    if (fgets(content, sizeof(content), stdin) == NULL) {
        printf("Error reading content.\n");
        fclose(file);
        return;
    }

    fseek(file, 0, SEEK_END); // Move to the end of the file
    fprintf(file, "%s", content);
    printf("Content appended successfully.\n");

    fclose(file);
}
