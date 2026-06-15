#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	printf("Hello, World!\n");
    char st[100];
    fgets(st, sizeof(st), stdin);
    printf("%s", st);  
    return 0;
}
