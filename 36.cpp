
#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef long double lld;
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define lcm(a, b) ((a) * (b)) / __gcd(a, b)
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<ll>v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int>dp1(n, 1);
    vector<int>dp2(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (v[i] > v[i - 1])
        {
            dp1[i] = dp1[i - 1] + 1;
        }

    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] < v[i + 1])
        {
            dp2[i] = dp2[i + 1] + 1;
        }
    }
    debug(dp1);
    debug(dp2);
    int max1 = 1;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && i < n - 1)
        {
            if (v[i - 1] < v[i + 1] && v[i + 1] - v[i - 1] > 1)
            {
                int ans = dp1[i - 1] + dp2[i + 1] + 1;
                max1 = max(ans, max1);
            }
        }
        if (i > 0)
            max1 = max(dp1[i - 1] + 1, max1);

        if (i < n - 1)
            max1 = max(dp2[i + 1] + 1, max1);




    }


    cout << max1 << endl;

}




int32_t  main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("take.txt", "r", stdin);
    freopen("getac.txt", "w", stdout);
#endif

    fastio();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}