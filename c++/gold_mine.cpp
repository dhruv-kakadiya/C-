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
    int a[n][m];
    int m1,m2,m3,sum,maxx,maxi=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        int k=i;
        int l=0;
        sum=a[k][l];
        for(int j=0;j<m-1;j++)
        {
            if(k==0 || l==m-1) m1=-1;
            else m1=a[k-1][l+1];

            if(l==m-1) m2=-1;
            else m2=a[k][l+1];

            if(k==n-1 || l==m-1) m3=-1;
            else m3=a[k+1][l+1];

            maxx=max(max(m1,m2),m3);
            if(maxx==m1)
            {
                k--;
                l++;
            }
            else if(maxx==m2)
            {
                l++;
            }
            else
            {
                k++;
                l++;
            }

            sum+=maxx;
        }
        maxi=max(maxi,sum);
    }
    cout<<maxi<<"\n";
    return 0;
}
