#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>
using namespace std;


int exponential_search(int a[],int target,int n)
{
    if(a[0]==target) return 0;
    int i=1,l,r;
    while(i<n && a[i]<=target)
    {
        i=i*2;
    }
    l=i/2;
    r=min(i,n-1);
    int m,loc;
    while(l<=r)
    {
        m=l+(r-l)/2;
        if(a[m]==target)
        {
            loc=m;
            r=m-1;
        }
        else if(target<a[m]) r=m-1;
        else l=m+1;
    }
    return loc;
}


int main()
{
    int n,target,pos;
    cin>>n>>target;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    pos=exponential_search(a,target,n);
    cout<<"POSITION OF TARGET ELEMENT:"<<pos<<"\n";
    return 0;
}
