#include <stdio.h>

int main() {
    // Declare a variable n and set it to 25 [cite: 48]
    int n = 25;
    int user_input;

    // Instructions to read in an integer from users [cite: 56]
    printf("Enter an integer: ");
    if (scanf("%d", &user_input) != 1) {
        return 1;
    }

    // Step 5: Compare if the user input is less than n [cite: 58]
    if (user_input < n) {
        printf("Less than\n"); // [cite: 59]
    }

    // Step 6: Compare if the user input is greater than or equal to n [cite: 59]
    if (user_input >= n) {
        printf("Greater than or equal to\n"); // [cite: 61]
    }

    /* Step 7 & 8: Logic for Greater than / Less than or equal to [cite: 62, 64]
       Note: Instructions mention commenting out previous steps for these.
    */
    
    // if (user_input > n) {
    //     printf("Greater than\n"); // [cite: 63]
    // }

    // if (user_input <= n) {
    //     printf("Less than or equal to\n"); // [cite: 65]
    // }

    return 0;
}