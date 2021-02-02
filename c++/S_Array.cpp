#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<pss> vss;
typedef set<int> si;
typedef set<ll> sl;
typedef set<pii> sii;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef unordered_map<int, int> umii;
typedef unordered_map<char, char> umcc;
typedef unordered_map<ll, ll> umll;
typedef unordered_map<string, ll> umsl;
typedef unordered_map<string, int> umsi;
typedef unordered_map<string, string> umss;
typedef unordered_set<int> usi;
typedef unordered_set<char> usc;
typedef unordered_set<pii> usii;
typedef unordered_set<pll> usll;
typedef unordered_set<ll> usl;
typedef unordered_set<string> uss;

#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ff(i, a, b) for (int i = int(a); i < int(b); i++)
#define ffn(i, n) ff(i, 0, n)
#define rf(i, a, b) for (int i = int(a); i >= int(b); i--)
#define rfn(i, n) rf(i, n - 1, 0)
#define endl \
    << "\n"
#define sp << " " <<


string s;
void sufix_array()
{
    int n = s.size();
    vi p(n),c(n);

    {
        // k = 0
        vector<pair<char,int>> a(n);
        ffn(i,n) a[i] = {s[i],i};
        sort(all(a));

        ffn(i,n) p[i] = a[i].S;
        c[p[0]]=0;
        ff(i,1,n)
        {
            if(a[i].F == a[i-1].F) c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]] + 1;
        }
    }

    int k = 0;
    while((1 << k) < n)
    {
        vector< pair<pair<int,int>, int>> a(n);
        ffn(i,n) a[i] = {{c[i],c[(i + (1<<k)) % n]},i};
        sort(all(a));

        ffn(i,n) p[i] = a[i].S;
        c[p[0]]=0;
        ff(i,1,n)
        {
            if(a[i].F == a[i-1].F) c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]] + 1;
        }
        k++;
    }

    ffn(i,n) cout<<p[i]<<" ";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ts = 1;
    //cin>>ts;
    while (ts--)
    {
       cin>>s;
       s += "$";
       sufix_array();
    }
    return 0;
}
