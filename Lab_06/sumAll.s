#include <stdio.h>

int main() {
    int input;
    int even_sum = 0; // [cite: 68]
    int odd_sum = 0;  // [cite: 68]

    // Loop to ask user to enter a number repeatedly [cite: 67, 71]
    while (1) {
        printf("Please enter a number: ");
        if (scanf("%d", &input) != 1) break;

        // Stop when the user enters a '0' [cite: 69]
        if (input == 0) {
            break;
        }

        /* Parity check (Even/Odd) without using div, and, or, etc. 
           Using repeated subtraction/addition to simulate MIPS loop logic.
        */
        int temp = input;
        
        // Convert to absolute-like range for parity check
        if (temp < 0) {
            while (temp < 0) temp += 2;
        } else {
            while (temp > 1) temp -= 2;
        }

        // If the result is 0, it was even; if 1, it was odd.
        if (temp == 0) {
            even_sum += input;
        } else {
            odd_sum += input;
        }
    }

    // Print out both sums (even if they are zero) [cite: 69]
    printf("Sum of even numbers is: %d\n", even_sum); // [cite: 85]
    printf("Sum of odd numbers is: %d\n", odd_sum);  // [cite: 86]

    return 0;
}