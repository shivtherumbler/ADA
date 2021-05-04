#include<stdio.h>
void main()
{
    int i;
    int c=21;
    int p=19;
    int lambda=51;
    int m=79;

    for(i=0;i<20;i++){
    c=(lambda*c+m)%p;
    printf("%d \n", c);
    }
}

