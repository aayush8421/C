#include<stdio.h>
int main()
{
    int marks;
    printf("Enter the marks(1-100):\n");
    scanf("%d",&marks);
    // if(marks>30)
    // {
    //     printf("Passed");
    // }
    // else
    // {
    //     printf("Failed");
    // }
    (marks>30)?printf("Passed"):printf("Failed");
    return 0;
}