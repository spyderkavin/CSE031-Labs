#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the functions
void printPuzzle(char** arr);
void searchPuzzle(char** arr, char* word);
char toUpper(char c);
int checkWord(char** arr, char* word, int r, int c, int index, int** path);

int bSize;

// Main function, DO NOT MODIFY 
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

    // Read the size of the puzzle block
    fscanf(fptr, "%d\n", &bSize);
    
    // Allocate space for the puzzle block and the word to be searched
    char **block = (char**)malloc(bSize * sizeof(char*));
    char *word = (char*)malloc(20 * sizeof(char));

    // Read puzzle block into 2D arrays
    for(i = 0; i < bSize; i++) {
        *(block + i) = (char*)malloc(bSize * sizeof(char));
        for (j = 0; j < bSize - 1; ++j) {
            fscanf(fptr, "%c ", *(block + i) + j);            
        }
        fscanf(fptr, "%c \n", *(block + i) + j);
    }
    fclose(fptr);

    printf("Enter the word to search: ");
    scanf("%19s", word);
    
    // Print out original puzzle grid
    printf("\nPrinting puzzle before search:\n");
    printPuzzle(block);
    
    // Call searchPuzzle to the word in the puzzle
    searchPuzzle(block, word);
    
     // Free allocated memory
    for (i = 0; i < bSize; i++)
        free(*(block + i));
    free(block);
    free(word);

    return 0;
}

// Manual case conversion to satisfy constraint [cite: 21]
char toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

// Recursive helper to find word path and handle backtracking [cite: 23, 132]
int checkWord(char** arr, char* word, int r, int c, int index, int** path) {
    // Base Case: Word completed
    if (*(word + index) == '\0') {
        return 1;
    }

    // Boundary and character match check using pointer arithmetic 
    if (r < 0 || r >= bSize || c < 0 || c >= bSize || 
        toUpper(*(*(arr + r) + c)) != toUpper(*(word + index))) {
        return 0;
    }

    // Save current path state
    int currentVal = *(*(path + r) + c);
    
    // Logic to store path sequence (e.g., 642 for multiple visits) [cite: 133]
    int power = 1;
    int temp = index + 1;
    while (temp > 0) { power *= 10; temp /= 10; }
    *(*(path + r) + c) = (currentVal * power) + (index + 1);

    // Search all 8 directions 
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            if (checkWord(arr, word, r + i, c + j, index + 1, path)) {
                return 1;
            }
        }
    }

    // Backtrack if path fails
    *(*(path + r) + c) = currentVal;
    return 0;
}

void printPuzzle(char** arr) {
    for (int i = 0; i < bSize; i++) {
        for (int j = 0; j < bSize; j++) {
            printf("%c ", *(*(arr + i) + j)); // Pointer arithmetic 
        }
        printf("\n");
    }
    printf("\n");
}

void searchPuzzle(char** arr, char* word) {
    // Allocate and initialize path array to 0 [cite: 23]
    int **path = (int**)malloc(bSize * sizeof(int*));
    for (int i = 0; i < bSize; i++) {
        *(path + i) = (int*)calloc(bSize, sizeof(int));
    }

    int found = 0;
    for (int i = 0; i < bSize; i++) {
        for (int j = 0; j < bSize; j++) {
            if (checkWord(arr, word, i, j, 0, path)) {
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    if (found) {
        printf("Word found!\n"); // Exactly matching output [cite: 22]
        printf("Printing the search path:\n");
        for (int i = 0; i < bSize; i++) {
            for (int j = 0; j < bSize; j++) {
                printf("%-8d", *(*(path + i) + j));
            }
            printf("\n");
        }
    } else {
        printf("Word not found!\n"); // Exactly matching output [cite: 22]
    }

    // Free path memory
    for (int i = 0; i < bSize; i++) free(*(path + i));
    free(path);
}