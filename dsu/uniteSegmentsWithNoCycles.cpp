// https://codeforces.com/contest/1559/problem/D2

simply make dsu and then connect all components with the component having 1.
  then traverse over all nodes of two tress (i, j) such that atleast one of i,j is part of one tree but not other.
  connect these both nodes which will not create cycle.
  
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

typedef struct node
{
    int rank;
    int par;
} dsu;

node t1[100001];
node t2[100001];

int find(int i, dsu t[])
{

    if (t[i].par != i)
    {
        t[i].par = find(t[i].par, t);
    }

    return t[i].par;
}

void Union(int x, int y, dsu t[])
{
    int xr = find(x, t);
    int yr = find(y, t);

    if (t[xr].rank > t[yr].rank)
    {
        t[yr].par = xr;
        t[xr].rank += t[yr].rank;
    }
    else if (t[xr].rank < t[yr].rank)
    {
        t[xr].par = yr;
        t[yr].rank += t[xr].rank;
    }
    else
    {
        t[xr].rank += t[yr].rank;
        t[yr].par = xr;
    }

    return;
}

void solve()
{
    int n, m;
    cin >> n;

    fo(i, 1, n)
    {
        t1[i].rank = 1;
        t1[i].par = i;
        t2[i].rank = 1;
        t2[i].par = i;
    }

    int a, b;
    cin >> a >> b;

    fo(i, 1, a)
    {
        int x, y;
        cin >> x >> y;

        int xr = find(x, t1);
        int yr = find(y, t1);

        if (yr < xr)
        {
            swap(yr, xr);
        }

        if (xr != yr)
        {

            Union(xr, yr, t1);
        }
    }
    hh;
    fo(i, 1, b)
    {
        int x, y;
        cin >> x >> y;

        int xr = find(x, t2);
        int yr = find(y, t2);
        if (yr < xr)
        {
            swap(yr, xr);
        }
        if (xr != yr)
        {

            Union(xr, yr, t2);
        }
        xr = find(x, t2);
        yr = find(y, t2);
    }

    int cnt = 0;
    vector<pair<int, int>> v;

    fo(i, 2, n)
    {

        int x1 = find(i, t1);
        int x2 = find(i, t2);

        if (x1 != find(1, t1) and x2 != find(1, t2))
        {
            cnt++;
            Union(x1, 1, t1);
            Union(x2, 1, t2);

            v.push_back({1, i});
        }
    }

    int n1 = 2, n2 = 2;

    while (1)
    {

        while (n1 <= n and find(n1, t1) == find(1, t1))
            n1++;
        while (n2 <= n and find(n2, t2) == find(1, t2))
            n2++;

        if (n1 > n || n2 > n)
            break;

        cnt++;
        v.push_back({n1, n2});
        Union(n1, n2, t1);
        Union(n1, n2, t2);
        n1++, n2++;
    }

    cout << cnt;
    hh;
    for (auto it : v)
    {
        cout << it.first << " " << it.second;
        hh;
    }

    return;
}

int32_t main()
{
    fast int tc = 1;
    // cin >>tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
