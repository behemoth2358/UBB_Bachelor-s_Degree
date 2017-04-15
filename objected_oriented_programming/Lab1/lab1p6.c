#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solve_a()//returns the number of 0 digits of the product of the read numbers.
{
    int prod=1,x;

    printf("Enter a number:");
    scanf("%d",&x);

    while(x)
    {
        prod*=x;

        printf("Enter a number:");
        scanf("%d",&x);
    }

    int sol=0;
    while(prod)
    {
        sol+=( prod%10 == 0 ? 1 : 0);
        prod/=10;
    }

    return sol;
}

int isPrime(int x)//returns 1 if x is prime, 0 else
{
    if(x<2)
        return 0;
    if(x==2)
        return 1;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return 0;
    return 1;
}

int* solve_b()
/*
Returns the longest contiguous subsequence such that the sum of any two consecutive elements is a prime number.
First element in the array is the number of elements followed by the sequence.
*/
{
    int n;

    printf("Number of elements:");
    scanf("%d",&n);

    int *arr=(int *)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        printf("Enter a element:");
        scanf("%d",&arr[i]);
    }

    int cnt=1,currentIndex=0,solIndex=0,sol=0;
    for(int i=1;i<n;i++)
    {
        if(isPrime(arr[i]+arr[i-1]))
            cnt++;
        else{
            currentIndex=i;
            cnt=1;
        }
        if(cnt > sol)
        {
            sol=cnt;
            solIndex=currentIndex;
        }
    }
    sol=(sol==0 ? 1 : sol);

    int *mySol=(int*)malloc( (sol+1)*sizeof(int));
    mySol[0]=sol;
    for(int i=solIndex;i<solIndex+sol;i++)
        mySol[i-solIndex+1]=arr[i];
    free(arr);

    return mySol;
}



int main()
{
    printf("Enter 1 for a)\nEnter 2 for b)\nYour command:");

    int t;
    scanf("%d",&t);

    if(t==1)
    {
        int sol=solve_a();
        printf("%d\n",sol);
    }
    else if(t==2)
    {
        int *sol=solve_b();

        printf("%d\n",sol[0]);
        for(int i=1;i<=sol[0];i++)
            printf("%d ",sol[i]);
        printf("\n");

        free(sol);
    }
    else
        printf("Invalid command!\n");

    return 0;
}
