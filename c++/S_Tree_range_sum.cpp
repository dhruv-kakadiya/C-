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
typedef vector<pss> vss;
typedef set<int> si;
typedef set<ll> sl;
typedef set<pii> sii;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef map<ll,ll> mll;
typedef unordered_map<int,int> umii;
typedef unordered_map<char,char> umcc;
typedef unordered_map<ll,ll> umll;
typedef unordered_map<string,ll> umsl;
typedef unordered_map<string,int> umsi;
typedef unordered_map<string,string> umss;
typedef unordered_set<int> usi;
typedef unordered_set<char> usc;
typedef unordered_set<pii> usii;
typedef unordered_set<pll> usll;
typedef unordered_set<ll> usl;
typedef unordered_set<string> uss;

#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ff(i,a,b) for(int i = int(a); i < int(b); i++)
#define ffn(i,n) ff(i,0,n)
#define rf(i,a,b) for(int i = int(a); i >= int(b); i--)
#define rfn(i,n) rf(i,n-1,0)
#define endl <<"\n"
#define sp <<" "<<

struct stree
{
    int size;
    vl z;

    void init(int n)
    {
        size=1;
        while(size<n) size*=2;
        z.resize(2*size);
    }

    void rset(int i, ll v, int x, int lx, int rx)
    {
        if(rx-lx==1)
        {
            z[x]+=v;
            return ;
        }

        int m=lx+(rx-lx)/2;
        if(i<m) rset(i,v,2*x+1,lx,m);
        else rset(i,v,2*x+2,m,rx);

        z[x]=z[2*x+1]+z[2*x+2];
        return;
    }

    void rset(int i, ll v)
    {
        if(i<size) rset(i,v,0,0,size);
        return;
    }

    ll sum(int l, int r, int x, int lx, int rx)
    {
        if(lx>=r || l>=rx)
        {
            return 0;
        }
        if(lx>=l && r>=rx)
        {
            return z[x];
        }
        if(rx-lx==1)
        {
            return z[x];
        }


        int m=lx+(rx-lx)/2;
        return sum(l,r,2*x+1,lx,m) + sum(l,r,2*x+2,m,rx);
    }

    ll sum(int l, int r)
    {
        return sum(l,r,0,0,size);
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ts=1;
    //cin>>ts;
    while(ts--)
    {
        int n,q,a;
        cin>>n>>q;

        stree st;
        st.init(n);
        ffn(i,q)
        {
            int op;
            cin>>op;
            if(op==1)
            {
                int l,r;
                ll v;
                cin>>l>>r>>v;
                st.rset(l,v);
                st.rset(r,-v);
            }
            else
            {
                int v;
                cin>>v;
                cout<<st.sum(0,v+1) endl;
            }
        }
    }
    return 0;
}
