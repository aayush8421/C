#include<stdio.h>
void main()
{
    int i,j;
    for(i=1;i<5;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }
    for(i=3;i>=0;i--)
    {
        for(j=0;j<=i;j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }
}