#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>
using namespace std;

int main()
{
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        int n;
        string s,b="";
        cin>>n>>s;
        stack<char> a;
        int i=0;
        while(i<n)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                b=b+s[i];
                i++;
            }
            else if(s[i]=='(')
            {
                a.push(s[i]);
                i++;
            }
            else if(a.empty())
            {
                a.push(s[i]);
                i++;
            }
            else if(s[i]==')')
            {
                while(!a.empty() && a.top()!='(')
                {
                    b=b+a.top();
                    a.pop();
                }
                a.pop();
                i++;
            }
            else
            {
                if(s[i]=='+' || s[i]=='-')
                {
                    while(true)
                    {
                        if(a.empty()) break;
                        else if(a.top()=='+' || a.top()=='-' || a.top()=='*' || a.top()=='/' || a.top()=='^')
                        {
                            b=b+a.top();
                            a.pop();
                        }
                        else break;
                    }
                    a.push(s[i]);
                    i++;
                }
                else if(s[i]=='*' || s[i]=='/')
                {
                    while(true)
                    {
                        if(a.empty()) break;
                        else if(a.top()=='*' || a.top()=='/' || a.top()=='^')
                        {
                            b=b+a.top();
                            a.pop();
                        }
                        else break;
                    }
                    a.push(s[i]);
                    i++;
                }
                else if(s[i]=='^')
                {
                    while(true)
                    {
                        if(a.empty()) break;
                        else if(a.top()=='^')
                        {
                            b=b+a.top();
                            a.pop();
                        }
                        else break;
                    }
                    a.push(s[i]);
                    i++;
                }
            }
        }

        while(!a.empty())
        {
            b=b+a.top();
            a.pop();
        }
        cout<<b<<"\n";
    }
    return 0;
}
