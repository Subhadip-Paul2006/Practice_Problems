// Given a string, s, consisting of alphabets and digits, find the frequency of each digit in the given string.

// Input Format

// The first line contains a string, num which is the given number.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char num[1000];
    scanf("%s", num);
    int freq[10] = {0};
    for(int i = 0; i < strlen(num); i++) {
        if(num[i] >= '0' && num[i] <= '9') {
            freq[num[i] - '0']++;
        }
    }
    for(int i = 0; i < 10; i++) {
        printf("%d:%d\n", i, freq[i]);
    }
    return 0;
}