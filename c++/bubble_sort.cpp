#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>
using namespace std;

void bubble_sort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int flag=0;
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag++;
            }
        }

        if(flag==0) break;
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
    int n,loc;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    bubble_sort(a,n);
    print_array(a,n);
    return 0;
}
