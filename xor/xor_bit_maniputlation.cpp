// https://codedrills.io/problems/subsegment-xor-sum

// instead of counting xor of all subarrays just see when the particular bit can contribute.
// make a prefix sum array for each bit (say kth bit) and if on ith index (ind) the sum is odd, we find the no. of past sum that were even (say jth ind) and vice versa,
// so that ith bit will contribute if we take subarray from j+1 to i as they have odd no. of times the kth bit set, i.e. adding (1<<k) to ans as this bit contributers for this particular subarray

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

    int a[n + 1];
    fo(i, 1, n)
    {
        cin >> a[i];
    }

    int ans = 0;

    fo(i, 0, 31)
    {

        int co = 0, ce = 1;
        int c = 0;

        fo(j, 1, n)
        {
            if ((a[j] >> i) & 1)
            {
                c += 1;
            }

            if (c % 2)
            {

                ans += ((ce * (1 << i)) % mod);
                ans %= mod;
            }
            else
            {
                ans += ((co * (1 << i)) % mod);
                ans %= mod;
            }

            if (c % 2)
            {
                co++;
            }
            else
            {
                ce++;
            }
        }
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
