
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

vector<int>pre;
vector<int>v;
int k;
int convert(int cnt, int i)
{
    int low = i - cnt - 1;
    if (low < 0)
    {
        return  k >= (cnt * v[i] - pre[i - 1]);
    }
    else
    {
        return k >= (cnt * v[i] - (pre[i - 1] - pre[low]));
    }
}
void solve()
{
    int n;
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(all(v));
    debug(v);
    map<int, int>mp;
    for (auto it : v)
        mp[it]++;

    //i need to convert all the values to one particular value
    //a b c x
    //x->target value
    //x-a  x-b   x-c
    //(x-a) + (x-b) + (x-c)
    pre.resize(n);
    pre[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + v[i];
    }
    debug(pre);

    int max1 = 0, val, occ;
    for (int i = 0; i < n; i++)
    {
        int ans = 0;
        int low = 0;
        int high = i ;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            //i will convert mid number of elements to the left to my current value
            if (convert(mid, i))
            {
                low = mid + 1;
                ans = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (ans > max1)
        {
            val = v[i];
            occ = ans;
            max1 = ans;
        }
    }
    cout << occ + 1 << " " << val;

}



int32_t  main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("take.txt", "r", stdin);
    freopen("getac.txt", "w", stdout);
#endif

    fastio();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
