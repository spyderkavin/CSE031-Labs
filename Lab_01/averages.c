#include <stdio.h>

int main() {
    int num, temp, digit_sum;
    int sum_even = 0;
    int count_even = 0;
    int sum_odd = 0; 
    int count_odd = 0;

    while (1) {
        printf("enter a number type 0 to stop: ");
        scanf("%d", &num);

        if (num == 0) break; // Exit the loop if 0 is entered

        // Calculate digit sum
        digit_sum = 0;
        temp = (num < 0) ? -num : num; // Make sure it's positive for math
        while (temp > 0) {
            digit_sum += temp % 10;
            temp /= 10;
        }

        // Sort into even or odd category
        if (digit_sum % 2 == 0) {
            sum_even += num;
            count_even++;
        } else {
            sum_odd += num;
            count_odd++;
        }
    }
    if (count_even > 0)
        printf("avg_even: %.2f\n", (float)sum_even / count_even);
    
    if (count_odd > 0)
        printf("avg_odd: %.2f\n", (float)sum_odd / count_odd);

    return 0;
}