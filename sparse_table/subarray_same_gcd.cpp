// https://codeforces.com/contest/1549/problem/D
// if we are on ith ind we do BS to get largert index (j) till where the gcd of subarray is >1


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

void solve()
{
    int n, m;
    cin >> n;

    int a[n + 2];
    fo(i, 0, n - 1)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        cout << 1;
        hh;
        return;
    }

    int d[n + 1];

    fo(i, 0, n - 2)
    {
        d[i] = abs(a[i] - a[i + 1]);
    }

    int ans = 0;

    int table[n + 1][18];

    fo(i, 0, n - 2)
    {
        table[i][0] = d[i];
      
    }

    fo(j, 1, 18)
    {

        for (int i = 0; i + (1 << j) <= n - 1; i++)
        {

            table[i][j] = __gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);

          
        }
    }

    int l = 1, h = n - 1;
    ans = 1;
    int en = 0;

    while (l <= h)
    {

        int m = (l + h) / 2;

        int msb = log2(m);

        int fl = 0;

        fo(i, 0, n - 2)
        {
            if (i + m <= n - 1 and __gcd(table[i][msb], table[i + m - (1 << msb)][msb]) >= 2)
            {
                en = 1;
          

                fl = 1;
                break;
            }
        }



        if (fl)
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }
    if (en == 0)
    {
        cout << 1;
        hh;
        return;
    }
    cout << ans + 1;
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
