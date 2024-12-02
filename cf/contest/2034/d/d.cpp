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
#define MAX int(2e5 + 5)
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
int MinDivisorPrime[MAX];
void sangnt()
{
    for (int i = 2; i < MAX; i++)
        IsPrime[i] = 1;
    for (ll i = 0; i < MAX; i++)
        if (IsPrime[i])
            for (ll j = i * i; j < MAX; j += i)
            {
                IsPrime[j] = 0;
                MinDivisorPrime[j] = i;
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

int n;
int a[MAX];

void reset()
{
}

void solve()
{
    cin >> n;
    int i1 = -1;
    int cnt0 = 0, cnt1 = 0;
    vector<int> res[2];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            i1 = i;
            cnt1++;
        }
        if (a[i] == 0)
            cnt0++;
    }
    int m0 = n - 1, m2 = 0;
    int i0 = 0, i2 = n - 1;
    while (true)
    {
        if (i0 >= cnt0 && i2 < cnt0 + cnt1)
            break;

        while (m2 < n && a[m2] != 2)
            m2++;
        while (m0 >= 0 && a[m0] != 0)
            m0--;

        // for (int _i = 0; _i < n; _i++)
        // cout << a[_i];
        // cout << " " << i0 << " " << i2 << " " << m0 << " " << m2 << endl;

        if (a[i0] == 0)
        {
            i0++;
            continue;
        }
        if (a[i2] == 2)
        {
            i2--;
            continue;
        }
        if (i0 < cnt0 && a[i0] == 1)
        {
            res[0].push_back(i0);
            res[1].push_back(m0);
            a[i0] = 0;
            a[m0] = 1;
            i1 = m0;
            m0--;
            continue;
        }
        if (i2 >= cnt0 + cnt1 && a[i2] == 1)
        {
            res[0].push_back(i2);
            res[1].push_back(m2);
            a[i2] = 2;
            a[m2] = 1;
            i1 = m2;
            m2++;
            continue;
        }
        if (i0 < cnt0)
        {
            res[0].push_back(i1);
            res[1].push_back(i0);
            a[i1] = 2;
            a[i0] = 1;
            i1 = i0;
        }
        else
        {
            res[0].push_back(i1);
            res[1].push_back(i2);
            a[i1] = 0;
            a[i2] = 1;
            i1 = i2;
        }
    }

    cout << res[0].size() << endl;
    for (int i = 0; i < res[0].size(); i++)
    {
        cout << res[0][i] + 1 << " " << res[1][i] + 1 << endl;
    }
}
