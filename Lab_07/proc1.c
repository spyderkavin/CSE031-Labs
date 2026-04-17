#include <stdio.h>

/* Equivalent C program for proc1.s [cite: 18] */
int main() {
    int m = 10; // Corresponds to .word 10
    int n = 5;  // Corresponds to .word 5
    
    // SUM(m, n)
    int v0 = m + n; 
    
    printf("%d", v0); // System call for printing
    return 0;
}