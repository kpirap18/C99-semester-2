#include <stdio.h>
#include <math.h>

int main()
{
    int s;
    int count = 0;
    setbuf(stdout, NULL);
    printf("Input integer s\n");
    scanf("%d", &s);
    count = (s - 20) / 25;
    printf("The count bottle %d\n", count);
    return 0;
}    
   
