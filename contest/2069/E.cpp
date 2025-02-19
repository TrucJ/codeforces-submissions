// Problem: E. A, B, AB and BA
// Contest: Codeforces - Educational Codeforces Round 174 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2069/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define MAX int(5e5 + 5)
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

string s;
int a, b, ab, ba;
// int fa[MAX][3], fb[MAX][3], fab[MAX][3], fba[MAX][3];

void reset()
{
}

string ss(int i) {
	return s[i] + s[i+1];
}

void solve()
{
    cin >> s >> a >> b >> ab >> ba;
    s = s[0] + s + s[s.size()-1];
    int n = s.size();
    if (s[0] == 'A') a++;
    if (s[0] == 'B') b++;
    if (s[n-1] == 'A') a++;
    if (s[n-1] == 'B') b++;
    
    int abab = 0;
    int abab_len = 0;
    int baba = 0;
    int baba_len = 0;
    int flex = 0;
    string cur = "";
    string start = -1;
    for (int i = 0; i < n-1; i++) {
    	if (ss(i) == "AB") {
    		if (ss(i-1) == "AA") {
    			cur = "AB";
    			start = i;
    		}
    		continue;
    	}
    	if (ss(i) == "BA") {
    		if (ss(i-1) == "BB") {
    			cur = "BA";
    			start = i;
    		}
    		continue;
    	}
    	if (ss(i) == "AA") {
    		if (i > 0 && ss(i-1) == "BA") {
    			if (cur = "AB") {
    				a--;
    				flex += (i - start) / 2;
    			} else {
    				baba++;
    			}
    		} else {
    			a--;
    		}
    		continue;
    	}
    	if (ss(i) == "BB") {
    		if (i > 0 && ss(i-1) == "AB") {
    			if (cur = "BA") {
    				b--;
    				flex += (i - start) / 2;
    			} else {
    				abab++;
    			}
    		} else {
    			b--;
    		}
    		continue;
    	}
    }
    if (a < 0 || b < 0) {
    	cout << "NO";
    	return;
    }
    
    
    
    
    
    
    
    
    
    // for (int i = 0; i < n; i++) {
    	// if (i < n-1) {
    		// if (s[i] == 'A' && s[i+1] == 'B') {
	    		// if (ab) {
	    			// ab--;
	    			// i++;
	    			// continue;
	    		// }
	    	// } else if (s[i] == 'B' && s[i+1] == 'A') {
	    		// if (ba) {
	    			// ba--;
	    			// i++;
	    			// continue;
	    		// }
	    	// }
	    // }
    	// if (s[i] == 'A') {
			// if (!a) {
				// cout << "NO";
				// return;
			// }
			// a--;
		// } else if (s[i] == 'B') {
			// if (!b) {
				// cout << "NO";
				// return;
			// }
			// b--;
		// }
    // }
    // cout << "YES";
    
    
    
    
    
}

// fa(i) = ( fa(i-1) + fb(i-1) + fab(i-1) + fba(i-1) ) * (s[i] == 'A')
// fb(i) = ( fa(i-1) + fb(i-1) + fab(i-1) + fba(i-1) ) * (s[i] == 'B')
// fab(i) = ( fb(i-1) ) * (s[i] == 'A')
// fba(i) = ( fa(i-1) ) * (s[i] == 'B')

// f(i,1) = max( f(i-1,1), f(i-1,2) ) 
// f(i,2) = max( f(i-2,1), f(i-2,2) ) 





