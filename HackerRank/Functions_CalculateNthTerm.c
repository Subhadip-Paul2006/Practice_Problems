// This challenge will help you learn the concept of recursion.
// A function that calls itself is known as a recursive function. The C programming language supports recursion. But while using recursion, one needs to be careful to define an exit condition from the function, otherwise it will go into an infinite loop.
// There is a series,S, where the next term is the sum of previous three terms. Given the first three terms of the series, a, b, and c respectively, you have to output the nth term of the series using recursion.

#include <stdio.h> 
int nthTerm(int a, int b, int c, int n) {
    if (n == 1) return a;
    if (n == 2) return b;
    if (n == 3) return c;
    return nthTerm(a, b, c, n - 1) + nthTerm(a, b, c, n - 2) + nthTerm(a, b, c, n - 3);
}
int main() {
    int a, b, c, n;
    scanf("%d %d %d %d", &a, &b, &c, &n);
    int result = nthTerm(a, b, c, n);
    printf("%d\n", result);
}