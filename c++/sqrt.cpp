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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        cout<<sqt(n)<<"\n";
    }
    return 0;
}
