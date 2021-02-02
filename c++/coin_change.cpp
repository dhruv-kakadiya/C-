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
    int a[n],w[n][m+1];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);

    for(int i=0;i<n;i++) w[i][0]=1;
    for(int j=1;j<=m;j++)
    {
        if(j%a[0]==0) w[0][j]=1;
        else w[0][j]=0;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j<a[i]) w[i][j]=w[i-1][j];
            else w[i][j]=w[i-1][j]+w[i][j-a[i]];
        }
    }

    cout<<w[n-1][m];
    return 0;
}
