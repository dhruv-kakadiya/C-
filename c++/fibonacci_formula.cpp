#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>
using namespace std;

float sqt(float e)
{
    float x=e;
    float y=1;
    float z=0.000001;
    while(x-y>z)
    {
        x=(x+y)/2;
        y=e/x;
    }
    return x;
}


int main()
{
    int n;
    cin>>n;
    float c=sqt(5);
    float a=(1+c)/2;
    a=pow(a,n);
    long long d=round(a/c);
    cout<<d;
    return 0;
}
