// You have to print the character, ch, in the first line. Then print s in next line. In the last line print the sentence, sen.

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char ch1[100], ch2[100], ch3[100];
    fgets(ch1, sizeof(ch1), stdin);
    printf("%s", ch1);
    fgets(ch2, sizeof(ch2), stdin);
    printf("%s", ch2);
    fgets(ch3, sizeof(ch3), stdin);
    printf("%s", ch3);  
    return 0;
}  
