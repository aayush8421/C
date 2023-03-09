#include<stdio.h>
#include<math.h>

// int decToBinary(int binary[],int n);
// void reverse(int binary[],int n);
// void shift(int binary[],int n);
// int binaryToDec(int binary[],int n);

int decToBinary(int binary[],int n)
{
    int i;
    while(n>0)
    {
        binary[i]=n%2;
        n=n/2;
        i++;
    }
    return i;
}

void reverse(int binary[],int n)
{
    int t;
    for(int i=0;i<n/2;i++)
    {
        t=binary[i];
        binary[i]=binary[n-i-1];
        binary[n-i-1]=t;
    }
}

void shift(int binary[],int n)
{
    // int a=binary[0];
    // int b=binary[1];
    for(int i=2;i<=n;i++)
    {
        binary[i-2]=binary[i];
    }
    // binary[n-2]=a;
    // binary[n-1]=b;
    binary[n-1]=0;
    binary[n-2]=0;

}

int binaryToDec(int binary[],int n)
{
    int d=0,b=0;
    for(int i=n-1;i>=0;i--)
    {
        d=d+binary[i]*pow(2,b);
        b++;
    }
    return d;
}

void main()
{
    int n;
    printf("Enter the number:\n");
    scanf("%d",&n);
    printf("\n");
    int binary[32];
    int i=decToBinary(binary,n);
    for(int j=0;j<i;j++)
    {
        printf("%d",binary[j]);
    }
    reverse(binary,i);
    shift(binary,i);
    int dec=binaryToDec(binary,i);
    printf("Number after shifting %d by 2 bits is: %d",n,dec);
}