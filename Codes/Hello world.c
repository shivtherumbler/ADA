#include<stdio.h>
#include<time.h>
void fun1(){
    int i=1000;
while(i>0){
    printf("\n Hello World");
    i--;
}
}
void main()
{
    time_t start,end;
    start=time(NULL);
    fun1();
    end = time(NULL);
    printf("\n Time: %u", end-start);
}
