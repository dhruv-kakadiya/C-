#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>
using namespace std;


/*
it will not work if input contains negative value.
for that, find minimum of array.
    this minimum is negative value,so that add this value in all element of array.
    then find K.
    And do rest operation.
    But at time to print this sorted array.....We have to "sub" minimum value from all elements of array.
*/
void counting_sort(int a[],int n,int k)
{
    int count[k+1]={0},b[n];
    for(int i=0;i<n;i++)
    {
        count[a[i]]++;
    }

    for(int i=1;i<=k;i++)
    {
        count[i]=count[i]+count[i-1];
    }

    for(int i=n-1;i>=0;i--)
    {
        count[a[i]]--;
        b[count[a[i]]]=a[i];
    }

    for(int i=0;i<n;i++)
    {
        a[i]=b[i];
    }
}


void print_array(int a[],int n)
{
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}


int main()
{
    int n,k=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>k) k=a[i];
    }

    counting_sort(a,n,k);
    print_array(a,n);
    cout<<"\n";
    return 0;
}
