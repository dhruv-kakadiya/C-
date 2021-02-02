#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>
using namespace std;

int exponential_Fibonacci(long long base[2][2],int power)
{
    long long result[2][2]={{1,0},{0,1}};
    long long mul[2][2];
    long long sum=0;
    while(power>0)
    {
        if(power%2==1)
        {
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<2;j++)
                {
                    for(int k=0;k<2;k++)
                    {
                        sum = sum + base[i][k]*result[k][j];
                    }
                    mul[i][j]=sum;
                    sum=0;
                }
            }
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<2;j++)
                {
                    result[i][j]=mul[i][j];
                }
            }
        }


        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                {
                    sum+=base[i][k]*base[k][j];
                }
                mul[i][j]=sum;
                sum=0;
            }
        }
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                base[i][j]=mul[i][j];
            }
        }

        power=power/2;
    }

    return result[0][0];
}


int main()
{
    int n;
    cin>>n;
    long long base[2][2]={{1,1},{1,0}};

    cout<<"Nth Fibonacci Term:"<<exponential_Fibonacci(base,n-1);
    return 0;
}
