#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>
using namespace std;

long long exponential_power(long long base,long long power)
{
    long long result=1,m=1e9 + 7;
    base=base%m;
    while(power>0)
    {
        if (power & 1) result=(result*base)%m;
        base=(base*base)%m;
        power=power>>1;
    }

    return result;
}


int main()
{
    long long base,power;
    cin>>base>>power;

    long long a=exponential_power(base,power);
    cout<<a<<"\n";
    return 0;
}
