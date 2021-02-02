#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];

    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);

    int table[n+1];
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for(int i=0; i<m; i++)
        for(int j=a[i]; j<=n; j++)
            table[j] += table[j-a[i]];

    cout<<table[n];
    return 0;
}
