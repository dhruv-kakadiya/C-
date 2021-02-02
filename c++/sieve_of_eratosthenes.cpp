#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>
using namespace std;

void allPrime(int a[],int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(a[i])
        {
            for(int j=2;i*j<=n;j++) a[i*j]=0;
        }
    }
}

void print_array(int a[],int n)
{
    int count=0;
    for(int i=2;i<=n;i++)
    {
        if (a[i])
        {
            cout<<i<<" ";
            count++;
        }
    }
    cout<<"\n";
    cout<<count<<"\n";
}
int main()
{
    int n;
    cin>>n;
    int a[n+1];

    a[0]=0;
    a[1]=0;
    a[2]=1;
    for(int i=3;i<=n;i++)
    {
        if(i%2) a[i]=1;
    }
    allPrime(a,n);
    print_array(a,n);
    return 0;
}
