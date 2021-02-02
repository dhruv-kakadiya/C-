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
    vl a;
    int NULL=INT_MAX;
    void init(int n)
    {
        size=1;
        while(size<n) size*=2;
        a.assign(2*size,0ll);
    }

    int merge(int a, int b)
    {
        return min(a,b);
    }

    void set(int i,int v, int x, int lx, int rx)
    {
        if(rx-lx == 1)
        {
            a[x]=v;
            return;
        }

        int m=lx+(rx-lx)/2;
        if(i<m)
        {
            set(i,v,2*x+1,lx,m);
        }
        else set(i,v,2*x+2,m,rx);
        a[x]=merge(a[2*x+1],a[2*x+2]);
    }

    void set(int i,int v)
    {
        set(i,v,0,0,size);
    }

    ll find(int l, int r, int x, int lx, int rx)
    {
        if(lx>=r || l>=rx) return NULL;
        if(lx>=l && rx<=r) return a[x];
        int m=lx+(rx-lx)/2;

        ll s1=find(l,r,2*x+1,lx,m);
        ll s2=find(l,r,2*x+2,m,rx);
        return merge(s1,s2);
    }

    ll find(int l, int r)
    {
        return find(l,r,0,0,size);
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
        int n,m;
        cin>>n>>m;

        stree st;
        st.init(n);
        ffn(i,n)
        {
            int v;
            cin>>v;
            st.set(i,v);
        }
        ffn(i,m)
        {
            int op;
            cin>>op;
            if(op==1)
            {
                int j,v;
                cin>>j>>v;
                st.set(j,v);
            }
            else
            {
                int l,r;
                cin>>l>>r;
                cout<<st.find(l,r) endl;
            }
        }
    }
    return 0;
}
