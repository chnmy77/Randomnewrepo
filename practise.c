#include<stdio.h>
int main()
{
    int i,a=5, arr[10];
    for(i=0;i<5;i++)
    {
        arr[i]=i+1;
    }

    for(i=0;i<5;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}