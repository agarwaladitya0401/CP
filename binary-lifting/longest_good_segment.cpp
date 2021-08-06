// https://www.codechef.com/LTIME98B/problems/LGSEG

// we want longest subarray with at most k sub subarray with sum of each subarray <= k, 
// we use binary lifting i.e. and take at most k jumps from each ith ind, and then take maximum from them.
  
  #include <bits/stdc++.h>
using namespace std;
#define endl "\n"
// #define int long long
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

void solve()
{
    int n, m;
    cin >> n;

    int k, s;
    cin >> k >> s;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (i != 0)
            a[i] += a[i - 1];
    }

    vector<int> nxt(n + 1);
    nxt[n] = n;

    for (int i = 0; i < n; i++)
    {
        int prev;
        if (i == 0)
            prev = 0;
        else
            prev = a[i - 1];

        nxt[i] = lower_bound(a.begin(), a.end(), prev + s + 1) - a.begin();
    }

    int up[n + 5][20 + 5];

    fo(i, 0, n - 1)
    {
        up[i][0] = nxt[i];
    }

    fo(j, 1, 19)
    {
        fo(i, 0, n - 1)
        {
            if (up[i][j - 1] >= 0 and up[i][j - 1] < n)
                up[i][j] = up[up[i][j - 1]][j - 1];
            else
                up[i][j] = n;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int temp = k;
        int idx = i;

        for (int j = 19; j >= 0; j--)
        {
            if ((1 << j) <= temp)
            {
                idx = up[idx][j];
                temp -= (1LL << j);
            }

            if (idx == n)
                break;
        }

        ans = max(ans, idx - i);
    }

    cout << ans;
    hh;

    return;
}

int32_t main()
{
    fast int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
