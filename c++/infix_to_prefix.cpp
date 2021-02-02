#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>
using namespace std;


int main()
{
    string s1="",s;
    cin>>s;
    int n=s.size();

    stack<char> a;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]>='a' && 'z'>=s[i]) s1=s1+s[i];
        else if(a.empty()) a.push(s[i]);
        else if(s[i]==')') a.push(s[i]);
        else if(s[i]=='+' || s[i]=='-')
        {
            while(a.top()=='*' || a.top()=='/' || a.top()=='^' || a.top()==')')
            {
                s1=s1+a.top();
                a.pop();
            }
            a.push(s[i]);
        }
        else if(s[i]=='(')
        {
            while(a.top()!=')')
            {
                s1=s1+a.top();
                a.pop();
            }
            a.pop();
        }
        else if(s[i]=='*' || s[i]=='/')
        {
            while(a.top()=='^')
            {
                s1=s1+a.top();
                a.pop();
            }
            a.push(s[i]);
        }
        else if(s[i]=='^')
        {
            while(a.top()=='^')
            {
                s1=s1+a.top();
                a.pop();
            }
            a.push(s[i]);
        }
    }
    while(!a.empty())
    {
        s1=s1+a.top();
        a.pop();
    }


    for(int i=n-1;i>=0;i--) cout<<s1[i];
    cout<<"\n";
    return 0;
}
