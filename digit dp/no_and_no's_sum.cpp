// https://lightoj.com/problem/investigation

// solution http://gautamdp.blogspot.com/2016/04/1068-investigation-digit-dp.html
// simply maintain sum and rem for each position in num

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

int k;

int cache[10][100][100][2];

int dp(int pos, int sum, int rem, string &t, string s, int tight)
{

    int ans = 0;

    if (pos >= t.size())
    {
        // int temp = stoi(s);
        // int sum = 0;

        // fo(i, 0, s.size() - 1)
        // {
        //     sum += s[i] - '0';
        // }

        if (sum % k == 0 and rem == 0)
        {

            // watch(s);
            return 1;
        }

        return 0;
    }

    if (cache[pos][sum][rem][tight] != -1)
    {
        return cache[pos][sum][rem][tight];
    }

    int ub = tight ? t[pos] - '0' : 9;

    fo(i, 0, ub)
    {

        string temp = s;
        temp.push_back(char('0' + i));
        int s = sum + i;
        int r = rem * 10 + i;
        r %= k;

        ans += dp(pos + 1, s, r, t, temp, (tight && (i == t[pos] - '0')));
    }

    cache[pos][sum][rem][tight] = ans;

    return ans;
}

// int fun(int a, int ans){

//     return ans;
// }

void solve(int t)
{
    int a, b;

    cin >> a >> b >> k;

    if (k > 99)
    {
        cout << "Case " << t << ": " << 0;
        hh;
        return;
    }

    a--;
    memset(cache, -1, sizeof(cache));

    string s1 = to_string(a);
    string s2 = to_string(b);

    int ans1 = dp(0, 0, 0, s2, "", 1);

    memset(cache, -1, sizeof(cache));
    int ans2 = dp(0, 0, 0, s1, "", 1);

    // watch(ans1);
    // watch(ans2);

    cout << "Case " << t << ": " << ans1 - ans2;
    hh;

    return;
}

int32_t main()
{
    fast int tc = 1;
    cin >> tc;
    int i = 1;
    while (tc--)
    {
        solve(i);
        i++;
    }
    return 0;
}

// -------------------------------------------refrence code--------------------------------------
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int lli;
// lli dp[10][2][100][100];
// lli val;
// lli ch(string s)
// {
//     lli num = 0, sum = 0;
//     for (int i = 0; i < s.length(); i++)
//     {
//         num = num * 10 + s[i] - '0';
//         sum += s[i] - '0';
//     }
//     if (num % val == 0 && sum % val == 0)
//         return 1;
//     else
//         return 0;
// }

// lli solve(lli idx, bool tight, lli num, string s, lli n, lli sum)
// {
//     if (idx >= n)
//     {
//         if (num % val == 0 && sum % val == 0)
//             return 1;
//         else
//             return 0;
//     }

//     if (dp[idx][tight][num][sum] != -1)
//     {
//         return dp[idx][tight][num][sum];
//     }
//     if (tight == 1)
//     {
//         lli ret = 0;
//         for (int i = 0; i <= s[idx] - '0'; i++)
//         {
//             lli numm = num * 10 + i;
//             lli summ = sum + i;
//             if (i == s[idx] - '0')
//                 ret += solve(idx + 1, 1, numm % val, s, n, summ);
//             else
//                 ret += solve(idx + 1, 0, numm % val, s, n, summ);
//         }
//         dp[idx][tight][num][sum] = ret;
//         // cout<<" index "<<idx<<" tight "<<tight<<" ans "<<ret<<endl;
//         return ret;
//     }
//     else
//     {
//         lli ret = 0;
//         for (int i = 0; i <= 9; i++)
//         {
//             lli numm = num * 10 + i;
//             lli summ = sum + i;
//             ret += solve(idx + 1, 0, numm % val, s, n, summ);
//         }
//         dp[idx][tight][num][sum] = ret;
//         //  cout<<" index "<<idx<<" tight "<<tight<<" ans "<<ret<<endl;
//         return ret;
//     }
// }

// int main()
// {
//     lli t;
//     cin >> t;
//     lli cas = 1;
//     while (t--)
//     {

//         string l, r;

//         cin >> l >> r >> val;
//         if (val >= 100)
//         {
//             cout << "Case " << cas++ << ": ";
//             cout << 0 << endl;
//             continue;
//         }
//         memset(dp, -1, sizeof dp);
//         lli ans1 = solve(0, 1, 0, r, r.length(), 0);
//         memset(dp, -1, sizeof dp);
//         lli ans2 = solve(0, 1, 0, l, l.length(), 0);
//         if (ch(l))
//             ans1++;
//         cout << "Case " << cas++ << ": ";
//         cout << ans1 - ans2 << endl;
//     }
// }
