#include <stdio.h>

int main() {
    int num, temp, digit_sum;
    int sum_even = 0;
    int count_even = 0;
    int sum_odd = 0; 
    int count_odd = 0;

    // Start an infinite loop to collect numbers until the sentinel value is entered
    while (1) {
        printf("enter a number type 0 to stop: ");
        scanf("%d", &num);

        // Terminate the loop if the user enters 0
        if (num == 0) break; 

        // Reset the digit sum accumulator for the new number
        digit_sum = 0;
        // Convert the number to its absolute value to handle negative inputs
        temp = (num < 0) ? -num : num; 
        
        // Loop to extract each digit from the number
        while (temp > 0) {
            // Add the last digit of the current value to the sum
            digit_sum += temp % 10;
            // Remove the last digit by performing integer division
            temp /= 10;
        }

        // Check if the calculated sum of digits is an even number
        if (digit_sum % 2 == 0) {
            // Add the original number to the even-sum total and increment the count
            sum_even += num;
            count_even++;
        } else {
            // Add the original number to the odd-sum total and increment the count
            sum_odd += num;
            count_odd++;
        }
    }
    
    // Check if any numbers with an even digit sum were processed to avoid division by zero
    if (count_even > 0)
        // Cast the sum to a float to ensure the division produces a decimal result
        printf("avg_even: %.2f\n", (float)sum_even / count_even);
    
    // Check if any numbers with an odd digit sum were processed
    if (count_odd > 0)
        // Print the average of numbers that had an odd digit sum
        printf("avg_odd: %.2f\n", (float)sum_odd / count_odd);

    return 0;
}