#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>
using namespace std;

void selection_sort(int a[],int n)
{
    int loc;
    for(int i=0;i<n-1;i++)
    {
        int min=a[i];
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<min)
            {
                min=a[j];
                loc=j;
            }
        }

        if(min!=a[i])
        {
            a[loc]=a[i]+a[loc];
            a[i]=a[loc]-a[i];
            a[loc]=a[loc]-a[i];
        }
    }

}

void print_array(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    selection_sort(a,n);
    print_array(a,n);
    return 0;
}
