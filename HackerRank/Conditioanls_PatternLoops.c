// Print a pattern of numbers from 1 to n as shown below. Each of the numbers is separated by a single space.
//4 4 4 4 4 4 4  
//4 3 3 3 3 3 4   
//4 3 2 2 2 3 4   
//4 3 2 1 2 3 4   
//4 3 2 2 2 3 4   
//4 3 3 3 3 3 4   
//4 4 4 4 4 4 4   
// Input Format: The input will contain a single integer n.
#include <stdio.h>
#include <stdlib.h> 
int main() 
{
    int n;
    scanf("%d", &n);
    int size = 2 * n - 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int top = i;
            int left = j;
            int right = size - 1 - j;
            int bottom = size - 1 - i;

            int min = top < left ? top : left;
            min = min < right ? min : right;
            min = min < bottom ? min : bottom;

            printf("%d ", n - min);
        }
        printf("\n");
    }
    return 0;
}