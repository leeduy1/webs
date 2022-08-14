#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{   int i; int a=5, b=50;
    double x=3.5, y= 20.8;
    printf("10 Hardware random integers:\n");
    for (i=0;i<10; i++) printf("%d ", rand());
    /*Init randomise using system time-miliseconds
        Each time the program executes, the system time changes.
        So, random sequence changes
    */
     srand(time(NULL)); 
     printf("\n\n10 Software random integers:\n");
     for (i=0;i<10; i++) printf("%d ", rand());
}
