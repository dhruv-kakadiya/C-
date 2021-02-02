#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>
using namespace std;


void radix_sort(int a[],int n,int cl)
{
    int b[n],c[n],count[10]={0},fact=1;
    for(int j=0;j<cl;j++)
    {
        for(int i=0;i<n;i++)
        {
            b[i]=a[i]/fact;
            b[i]=b[i]%10;
            count[b[i]]++;
        }

        for(int i=1;i<10;i++)
        {
            count[i]=count[i]+count[i-1];
        }

        for(int i=n-1;i>=0;i--)
        {
            count[b[i]]--;
            c[count[b[i]]]=a[i];
        }

        for(int i=0;i<n;i++)
        {
            a[i]=c[i];
        }
        fact*=10;
        for(int i=0;i<10;i++) count[i]=0;
    }
}

void print_array(int a[],int n)
{
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}


int main()
{
    int n,z=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>z) z=a[i];
    }

    int cl=0;
    while(z>0)
    {
        cl++;
        z=z/10;
    }

    radix_sort(a,n,cl);
    print_array(a,n);
    cout<<"\n";
    return 0;
}
