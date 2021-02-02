
#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>
using namespace std;


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


int main()
{
    int a,b;
    cin>>a>>b;
    int g=gcd(max(a,b),min(a,b));
    int lcm=(a*b)/g;
    cout<<g<<" "<<lcm;
    return 0;
}
