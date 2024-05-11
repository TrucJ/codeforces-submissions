#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <map>
#define ll long long
#define II pair<int, int>
#define PQ priority_queue
#define MAX 200005
#define INF 1000000009
#define BASE 998244353
#define For(_, m, n) for (int _ = m; _ <= n; _++)
#define Rev(_, m, n) for (int _ = m; _ >= n; _--)
using namespace std;
void reset();
void solve();
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll Pow(ll a, ll n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    ll res = Pow(a, n / 2);
    return res * res * Pow(a, n % 2);
}
bool IsPrime[MAX];
void sangnt()
{
    for (int i = 2; i < MAX; i++)
        IsPrime[i] = 1;
    for (int i = 0; i < MAX; i++)
        if (IsPrime[i])
        {
            for (int j = 2 * i; j < MAX; j += i)
                IsPrime[j] = 0;
        }
}
int main()
{
    if (fopen("trucj.inp", "r"))
        freopen("trucj.inp", "r", stdin),
            freopen("trucj.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // sangnt();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        reset();
        solve();
        cout << endl;
    }
    return 0;
}

void reset()
{
}

void solve()
{
}
