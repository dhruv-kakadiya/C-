
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<string,string> pss;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef map<ll,ll> mll;
typedef unsigned long long ull;
typedef unordered_map<int,int> umii;
typedef unordered_map<ll,ll> umll;
typedef unordered_map<string,ll> umsl;
typedef unordered_map<string,int> umsi;
typedef unordered_map<string,string> umss;
typedef unordered_set<int> usi;
typedef unordered_set<ll> usl;
typedef unordered_set<string> uss;

#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ff(i,a,b) for(int i = int(a); i < int(b); i++)
#define ffn(i,n) ff(i,0,n)
#define rf(i,a,b) for(int i = int(a)-1; i >= int(b); i--)
#define rfn(i,n) rf(i,n,0)
#define endl "\n"

void BFS(vector<int> g[],int n,int st)
{
    queue<int> q;
    bool v[n+1]={0};
    q.push(st);
    v[st]=1;
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        ffn(j,g[a].size())
        {
            if(!v[g[a][j]])
            {
                q.push(g[a][j]);
                v[g[a][j]]=1;
            }
        }
    }
    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--)
    {
        BFS();
    }
    return 0;
}
