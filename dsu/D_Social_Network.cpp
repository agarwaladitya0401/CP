#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ll long long
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rfo(i, a, b) for (int i = (int)a; i >= (int)b; i--)
#define fo(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define see(x) cout << (x) << endl
#define hh cout << endl
#define INF 1e18
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

template <typename C,
          typename T = std::decay_t<decltype(*begin(std::declval<C>()))>,
          typename std::enable_if<!std::is_same<C, std::string>::value>::type * = nullptr>
std::ostream &operator<<(std::ostream &os, const C &container)
{
    bool first = true;
    std::stringstream ss;
    ss << '[';
    for (const auto &x : container)
    {
        if (!first)
        {
            ss << ", ";
        }
        first = false;
        ss << x;
    }
    ss << ']';
    return os << ss.str();
}
template <class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p)
{
    os << '{' << p.first << ", " << p.second << '}';
    return os;
}

ll mod_pow(ll a, ll b)
{
    if (b < 0)
        return 0;
    a %= mod;
    if (b == 0)
        return 1;
    if (b == 1)
        return a % mod;
    if (b == 2)
        return ((a % mod) * (a % mod)) % mod;
    return (mod_pow(mod_pow(a, b / 2), 2) * mod_pow(a, b % 2)) % mod;
}

bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Keep calm and Keep coding //

int mx = -1;
int mxAns = -1;

struct dsu
{
    int rank;
    int par;

    dsu()
    {
        rank = 1;
        par = -1;
    }
};

dsu t1[1001];
int xEdgs = 0;

int find(int x)
{

    while (t1[x].par != x)
    {
        x = t1[x].par;
    }

    return x;
}

void Union(int x, int y)
{

    int xr = find(x);
    int yr = find(y);

    if (xr == yr)
    {
        xEdgs++;
        return;
    }

    if (t1[xr].rank >= t1[yr].rank)
    {
        t1[xr].rank += t1[yr].rank;
        t1[yr].par = xr;

        // watch(xr);
        // watch(t1[xr].rank);
        // watch(mxAns);
        if (t1[xr].rank > mx)
        {
            mx = t1[xr].rank;
            mxAns = xr;
        }
    }
    else
    {
        t1[yr].rank += t1[xr].rank;
        t1[xr].par = yr;

        // watch(yr);
        // watch(t1[yr].rank);
        // watch(mxAns);
        if (t1[yr].rank > mx)
        {
            mx = t1[yr].rank;
            mxAns = yr;
        }
    }
}

void solve()
{
    int n, m;
    cin >> n;
    cin >> m;

    fo(i, 1, n)
    {
        t1[i].rank = 1;
        t1[i].par = i;
    }

    fo(i, 1, m)
    {
        int a, b;
        cin >> a >> b;

        Union(a, b);

        int vis[n + 1] = {0};
        vector<int> v;

        fo(i, 1, n)
        {
            int pr = find(i);
            if (vis[pr] == 0)
            {
                vis[pr] = 1;
                v.push_back(t1[pr].rank);
            }
                }
        sort(all(v));
        reverse(all(v));
        int till = min((int)v.size() - 1, xEdgs);

        int ans = v[0];
        fo(i, 1, till)
        {
            // watch(v[i]);
            ans += v[i];
        }

        cout << ans - 1;
        hh;
    }

    return;
}

int32_t main()
{
    fast int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
