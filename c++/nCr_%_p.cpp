#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>
using namespace std;

int main()
{
    int n,r,p;
    cin>>n>>r>>p;

    if(r>n-r) r=n-r;
    int a[r+1];
    a[0]=1;
    for(int i=1;i<=r;i++) a[i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=r;j++)
        {
            a[j]=(a[j]+a[j-1])%p;
        }
    }

    cout<<a[r];
    return 0;
}
