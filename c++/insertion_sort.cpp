#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>
using namespace std;

void insertion_sort(int a[],int n)
{
    int loc;
    for(int i=1;i<n;i++)
    {
        int temp=a[i];
        loc=i;
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]>temp)
            {
                a[j+1]=a[j];
                loc--;
            }
            else break;
        }
        a[loc]=temp;
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

    insertion_sort(a,n);
    print_array(a,n);
    return 0;
}
