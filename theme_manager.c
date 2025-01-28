#include <stdio.h>
#include <stdlib.h>
#include "theme_manager.h"

#define THEME_STATE_FILE "theme_state.txt"

// Function to load the theme state from a file
int loadThemeState() {
    FILE *file = fopen(THEME_STATE_FILE, "r");
    if (file == NULL) {
        return 0; // Default to light theme if the file doesn't exist
    }
    int isDark;
    fscanf(file, "%d", &isDark);
    fclose(file);
    return isDark;
}

// Function to save the theme state to a file
void saveThemeState(int isDark) {
    FILE *file = fopen(THEME_STATE_FILE, "w");
    if (file == NULL) {
        perror("Error saving theme state");
        return;
    }
    fprintf(file, "%d", isDark);
    fclose(file);
}

// Function to switch between light and dark themes
void switchTheme() {
    static int isDark = -1;

    if (isDark == -1) {
        isDark = loadThemeState();
    }

    if (isDark) {
        printf("Switched to Light Theme.\n");
        isDark = 0;
    } else {
        printf("Switched to Dark Theme.\n");
        isDark = 1;
    }

    saveThemeState(isDark);
}
