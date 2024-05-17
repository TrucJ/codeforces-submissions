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
int arr[MAX];
void reset()
{
    // for (int i = 0; i <= n; i++)
    // {
    //     arr[i] = 0;
    // }
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // cout << arr[i];
    }
    int finalmaxcnt = 0;
    for (int p = 0; p <= 20; p++)
    {
        int maxcnt = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int tmp = arr[i] % 2;
            if (tmp == 1)
            {
                cnt = 0;
            }
            else
            {
                cnt += 1;
            }
            if (cnt > maxcnt)
                maxcnt = cnt;
            arr[i] /= 2;
        }
        // cout << "debug " << maxcnt << endl;
        if (maxcnt == n)
            continue;
        if (maxcnt > finalmaxcnt)
            finalmaxcnt = maxcnt;
    }
    cout << finalmaxcnt + 1;
}
