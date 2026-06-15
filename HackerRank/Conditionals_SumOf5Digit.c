// Given a five digit integer, print the sum of its digits.
// Input Format
// The input contains a single five digit number, n.

#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int n, sum = 0;
    scanf("%d", &n);
    
    for (int i = 0; i < 5; i++) {
        sum += n % 10;
        n /= 10;
    }
    
    printf("%d", sum);
    return 0;
}