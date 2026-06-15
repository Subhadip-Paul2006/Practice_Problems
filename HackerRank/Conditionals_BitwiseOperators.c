// Complete the calculate_the_maximum function in the editor below.

// calculate_the_maximum has the following parameters:

// int n: the highest number to consider
// int k: the result of a comparison must be lower than this number to be considered
// Prints
// Print the maximum values for the and, or and xor comparisons, each on a separate line.
// Input Format
// The only line contains 2 space-separated integers, n  and k.

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



void calculate_the_maximum(int n, int k) {
    int i, j;
    int max_and = 0, max_or = 0, max_xor = 0;
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            int and_val = i & j;
            int or_val  = i | j;
            int xor_val = i ^ j;

            if (and_val < k && and_val > max_and)
                max_and = and_val;

            if (or_val < k && or_val > max_or)
                max_or = or_val;

            if (xor_val < k && xor_val > max_xor)
                max_xor = xor_val;
        }
    }
    printf("%d\n%d\n%d\n", max_and, max_or, max_xor);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
    return 0;
}
