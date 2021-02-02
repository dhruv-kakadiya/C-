#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>
using namespace std;


int main()
{
    int n,k,m;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    queue<int> b;
    b.push(0);


    for(int i=1;i<k;i++)
    {
        if(a[b.front()]<=a[i])
        {
            b.pop();
        }
        b.push(i);
    }
    cout<<a[b.front()]<<" ";


    for(int i=k;i<n;i++)
    {
        if(a[b.front()]<=a[i])
        {
            while(!b.empty()) b.pop();
        }
        b.push(i);

        if(b.front()<=i-k)
        {
            b.pop();
            m = a[b.back()];
            while(a[b.front()]<=m && b.front()!=i) b.pop();
        }

        cout<<a[b.front()]<<" ";
    }
    cout<<"\n";
    return 0;
}
