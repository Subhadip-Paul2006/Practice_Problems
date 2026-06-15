// Given a sentence, s, print each word of the sentence in a new line.

// Input Format

// The first and only line contains a sentence, s.

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {
    char s[1000];
    fgets(s, sizeof(s), stdin);
    char *token = strtok(s, " \n");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " \n");
    }
    return 0;
}