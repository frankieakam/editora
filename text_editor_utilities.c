#include <stdio.h>
#include <string.h>
#include "text_editor_utilities.h"

// Function to count words in a file
void countWords() {
    char filename[100];
    char word[50];
    FILE *file;
    int count = 0;

    printf("Enter the name of the file to count words: ");
    if (scanf("%99s", filename) != 1) { // Use %99s to prevent buffer overflow
        printf("Invalid input.\n");
        return;
    }

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file"); // Use perror to provide detailed error message
        return;
    }

    while (fscanf(file, "%49s", word) != EOF) { // Use %49s to prevent buffer overflow
        count++;
    }

    printf("Total words: %d\n", count);
    fclose(file);
}

// Function to find and replace text in a file
void findAndReplace() {
    char filename[100], search[50], replace[50], tempFile[] = "temp_editora_file.txt";
    char line[1000];
    FILE *file, *temp;

    printf("Enter the file name: ");
    if (scanf("%99s", filename) != 1) { // Use %99s to prevent buffer overflow
        printf("Invalid input.\n");
        return;
    }
    printf("Enter the word to find: ");
    if (scanf("%49s", search) != 1) { // Use %49s to prevent buffer overflow
        printf("Invalid input.\n");
        return;
    }
    printf("Enter the word to replace: ");
    if (scanf("%49s", replace) != 1) { // Use %49s to prevent buffer overflow
        printf("Invalid input.\n");
        return;
    }

    file = fopen(filename, "r");
    temp = fopen(tempFile, "w");
    if (file == NULL || temp == NULL) {
        perror("Error opening file"); // Use perror to provide detailed error message
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        char *pos;
        while ((pos = strstr(line, search)) != NULL) {
            int len = pos - line;
            line[len] = '\0';
            fprintf(temp, "%s%s", line, replace);
            strcpy(line, pos + strlen(search));
        }
        fprintf(temp, "%s", line);
    }

    fclose(file);
    fclose(temp);

    if (remove(filename) != 0 || rename(tempFile, filename) != 0) {
        perror("Error renaming file"); // Use perror to provide detailed error message
        return;
    }

    printf("Find and replace completed.\n");
}
