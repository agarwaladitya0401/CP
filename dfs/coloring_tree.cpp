// https://www.hackerearth.com/problem/algorithm/coloring-a-tree/

done dfs, dp[n][0] maintians the min cost we will achieve if color the subtree of node n.
  dp[n][1] maintains the next smallest cost to color subtree of node n (includint n) if we use other color then used in dp[n][0]
 
  then explore all choices and return min ans dp[1][0] with considering root as 1;

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

const int N = 100001;

int dp[100001][2];
int col[100001][2];

int a[N];
int b[N];

vector<int> adj[N];

int n, r;

void dfs(int i, int p)
{

    for (auto j : adj[i])
    {

        if (j == p)
            continue;

        dfs(j, i);
    }

    fo(k, 0, 1)
    {
        dp[i][k] = INF;
        col[i][k] = -1;
    }

    fo(k, 1, r)
    {

        int curr = a[k];

        for (auto j : adj[i])
        {

            if (j == p)
                continue;

            if (col[j][0] == k)
            {
                curr += min(dp[j][0] + b[k], dp[j][1]);
            }
            else
            {
                curr += dp[j][0];
            }
        }

        if (curr < dp[i][0])
        {

            dp[i][1] = dp[i][0];
            col[i][1] = col[i][0];

            dp[i][0] = curr;
            col[i][0] = k;
        }
        else if (curr < dp[i][1])
        {
            dp[i][1] = curr;
            col[i][1] = k;
        }
    }

    // watch(i);
    // watch(p);
    // watch(dp[i][0]);
    // watch(dp[i][1]);
}

void solve()
{
    cin >> n >> r;

    fo(i, 1, r)
    {
        cin >> a[i];
    }
    fo(i, 1, r)
    {
        cin >> b[i];
    }

    fo(i, 1, n - 1)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    cout << dp[1][0];

    return;
}

int32_t main()
{
    fast int tc = 1;
    // cin>>tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}


