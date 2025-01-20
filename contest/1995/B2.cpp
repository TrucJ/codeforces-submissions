/*
__/\\\\\\\\\\\\\\\____________________________________________/\\\\\\\\\\\_
 _\///////\\\/////____________________________________________\/////\\\///__
  _______\/\\\_____________________________________________________\/\\\_____
   _______\/\\\____/\\/\\\\\\\___/\\\____/\\\_____/\\\\\\\\_________\/\\\_____
    _______\/\\\___\/\\\/////\\\_\/\\\___\/\\\___/\\\//////__________\/\\\_____
     _______\/\\\___\/\\\___\///__\/\\\___\/\\\__/\\\_________________\/\\\_____
      _______\/\\\___\/\\\_________\/\\\___\/\\\_\//\\\_________/\\\___\/\\\_____
       _______\/\\\___\/\\\_________\//\\\\\\\\\___\///\\\\\\\\_\//\\\\\\\\\______
        _______\///____\///___________\/////////______\////////___\/////////_______
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#define ll long long
#define II pair<int, int>
#define llll pair<ll, ll>
#define PQ priority_queue
#define MAX 200005
#define INF 1000000009
#define For(_, m, n) for (int _ = m; _ <= n; _++)
#define Rev(_, m, n) for (int _ = m; _ >= n; _--)
const ll BASE_MOD = 1e9 + 7;
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
#define MATRIX_SIZE 2
void matrix_multiply(ll matrix1[][MATRIX_SIZE], ll matrix2[][MATRIX_SIZE], ll result[][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; ++i)
        for (int j = 0; j < MATRIX_SIZE; ++j)
        {
            result[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; ++k)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
                result[i][j] %= BASE_MOD;
            }
        }
}
void matrix_power(ll matrix[][MATRIX_SIZE], ll n, ll result[][MATRIX_SIZE])
{
    if (n == 0)
    {
        for (int i = 0; i < MATRIX_SIZE; ++i)
            for (int j = 0; j < MATRIX_SIZE; ++j)
                result[i][j] = i == j ? 1 : 0;
        return;
    }
    ll tmp[MATRIX_SIZE][MATRIX_SIZE];
    matrix_power(matrix, n / 2, tmp);
    if (n % 2)
    {
        ll tmp_power_2[MATRIX_SIZE][MATRIX_SIZE];
        matrix_multiply(tmp, tmp, tmp_power_2);
        matrix_multiply(tmp_power_2, matrix, result);
    }
    else
        matrix_multiply(tmp, tmp, result);
}
int lcs(string X, string Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);
    else
        return max(lcs(X, Y, m, n - 1),
                   lcs(X, Y, m - 1, n));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // sangnt();
    int t = 1;
    cin >> t;
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

ll n;
ll m;
ll a[MAX];
ll b[MAX];
llll c[MAX];
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        c[i] = make_pair(a[i], b[i]);
    }
    sort(c, c + n);
    ll res = 0;

    for (int i = 0; i < n; i++)
    {
        res = max(res, c[i].first * min(c[i].second, m / c[i].first));
    }

    for (int i = 1; i < n; i++)
    {
        if (c[i].first - c[i - 1].first > 1)
            continue;
        ll x1 = min(c[i - 1].second, m / c[i - 1].first);
        ll s = c[i - 1].first * x1;
        ll x2 = min(c[i].second, (m - s) / c[i].first);
        s += x2 * c[i].first;
        ll x3 = min(m - s, min(c[i].second - x2, x1));
        ll r = s + x3;
        res = max(res, r);
        if (m == 100000 && res == 100000)
        {
            cout << i << " " << x1 - x3 << " " << x2 + x3 << " " << endl;
        }
    }

    cout << res;
}