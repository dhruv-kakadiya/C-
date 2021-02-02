#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>
using namespace std;

int lcm(int,int);

int gcd(int a,int b)
{
    while(b>0)
    {
        int temp=a;
        a=b;
        b=temp%b;
    }
    return a;
}

int lcm(int a,int b)
{
    int l=gcd(a,b);
    return (a*b)/l;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<lcm(a,b);
    return 0;
}
