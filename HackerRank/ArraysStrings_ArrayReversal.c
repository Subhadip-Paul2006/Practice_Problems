// Given an array, of size n, reverse it.

// Example: If array, [1,2,3,4,5], after reversing it, the array should be, [3,2,1].

// Input Format

// The first line contains an integer, n, denoting the size of the array. The next line contains n space-separated integers denoting the elements of the array.
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}