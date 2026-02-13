#include <stdio.h>

int main() {
    int repetitions, typoLine;

    // Prompt the user for the number of lines to print
    printf("Enter the repetition count for the punishment phrase: ");
    // Validate that input is a positive integer and clear buffer if invalid
    while (scanf("%d", &repetitions) != 1 || repetitions <= 0) {
        printf("You entered an invalid value for the repetition count! Please re-enter: ");
        ///while (getchar() != '\n'); 
    }

    // Prompt the user for which specific line should contain the typo
    printf("Enter the line where you want to insert the typo: ");
    // Validate that the typo line is within the range of total repetitions
    while (scanf("%d", &typoLine) != 1 || typoLine <= 0 || typoLine > repetitions) {
        printf("You entered an invalid value for the typo placement! Please re-enter: ");
        ///while (getchar() != '\n');
    }
    
    printf("\n");

    // Iterate from 1 up to the specified number of repetitions
    for (int i = 1; i <= repetitions; i++) {
        // Check if the current line index matches the chosen typo line
        if (i == typoLine) {
            // Print the version of the phrase with intentional spelling errors
            printf("Cading wiht is C avesone!\n");
        } else {
            // Print the correctly spelled version of the phrase
            printf("Coding with C is awesome!\n");
        }
    }

    return 0;
}