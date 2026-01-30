#include <stdio.h>

int main() {
    int repetitions, typoLine;

    printf("Enter the repetition count for the punishment phrase: ");
    while (scanf("%d", &repetitions) != 1 || repetitions <= 0) {
        printf("You entered an invalid value for the repetition count! Please re-enter: ");
        while (getchar() != '\n'); 
    }

    printf("Enter the line where you want to insert the typo: ");
    while (scanf("%d", &typoLine) != 1 || typoLine <= 0 || typoLine > repetitions) {
        printf("You entered an invalid value for the typo placement! Please re-enter: ");
        while (getchar() != '\n');
    }

    printf("\n");

    for (int i = 1; i <= repetitions; i++) {
        if (i == typoLine) {
            printf("Cading wiht is C avesone!\n");
        } else {
            printf("Coding with C is awesome!\n");
        }
    }

    return 0;
}