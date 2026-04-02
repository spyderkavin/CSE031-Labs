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

// Manual case conversion to satisfy constraint 
char toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

// word path ad reveress
int checkWord(char** arr, char* word, int r, int c, int index, int** path) {
    
    
    if (*(word + index) == '\0') { //current chaarcter is word null terminatr
        return 1;
    }

    
    if (r < 0 || r >= bSize || c < 0 || c >= bSize) { //within grid lims
        return 0;
    }

    // comapre arr[r][c] to word letter
    if (toUpper(*(*(arr + r) + c)) != toUpper(*(word + index))) {
        return 0;
    }

    //store path value to backtark if needed 
    int currentPathVal = *(*(path + r) + c);

    //Update the path array with the current letter's position.
    
    int power = 1;
    int tempIndex = index + 1; //1st is 1
    while (tempIndex > 0) { 
        power *= 10; 
        tempIndex /= 10; 
    }
    *(*(path + r) + c) = (currentPathVal * power) + (index + 1);

    //Check all 8 directions (neighbors) i and j  from -1 to 1 to cover both side
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            // Skip the case where i=0 and j=0 (which is the current cell itself).
            if (i == 0 && j == 0) continue;

            // Recursively call checkWord for the next letter (index + 1) & check around
            
            if (checkWord(arr, word, r + i, c + j, index + 1, path)) {
                return 1;  //found = 1
            }
        }
    }

    // BACKTRACKING: If none of the 8 directions resulted in finding the word,
    // reset this cell's path value to what it was before we modified it. [cite: 132]
    *(*(path + r) + c) = currentPathVal;

    return 0; // Word not found starting from this specific path.
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

    // We create a 2-D integer array to store the "found".
    int **path = (int**)malloc(bSize * sizeof(int*));
    for (int i = 0; i < bSize; i++) {
        // calloc initializes every cell to 0, which represents "not part of the path".
        *(path + i) = (int*)calloc(bSize, sizeof(int));
    }

    int found = 0; // t/f

    
    // We must check every single cell (i, j) in the grid because any cell could be the starting letter of the word.
    for (int i = 0; i < bSize; i++) {
        for (int j = 0; j < bSize; j++) {
            
            
            // For every cell, we call checkword start at 0
            
            if (checkWord(arr, word, i, j, 0, path)) {
                found = 1; // Mark as found if the recursion returns true.
                break;     // Stop searching the current row.
            }
        }
        if (found) break; // if the word is found stop searching.
    }

    // output formating match the sample runs in wording and case.
    if (found) {
        printf("Word found!\n");
        printf("Printing the search path:\n");

        // Nested loops to print the path grid.
        for (int i = 0; i < bSize; i++) {
            for (int j = 0; j < bSize; j++) {
                // %-8d ensures each number has space around it, keeping columns aligned to access path[i][j].
                printf("%-8d", *(*(path + i) + j));
            }
            printf("\n"); // Newline at the end of each row.
        }
    } else {
        printf("Word not found!\n");
    }

    //prevent memory leeks
    for (int i = 0; i < bSize; i++) {
        free(*(path + i));
    }
    free(path);
}