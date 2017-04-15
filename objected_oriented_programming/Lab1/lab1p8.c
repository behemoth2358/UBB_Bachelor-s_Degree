#include <stdio.h>

int logPow(int x,int n)//returns x^n
{
    int sol=1;
    while(n)
    {
        if(n%2==1)
        {
            sol*=x;
            n--;
        }
        x*=x;
        n/=2;
    }
    return sol;
}

int main()
{
    int x,n;

    printf("Enter the number:");
    scanf("%d",&x);
    printf("Enter the power:");
    scanf("%d",&n);

    int sol=logPow(x,n);

    printf("Solution is %d\n",sol);

    return 0;
}
