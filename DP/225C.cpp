#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) ((int)(x).size())
#define nl '\n'
#ifdef Rakib_18
#include "debug.hpp"
#else
#define debug(...)
#endif
void init_code() {
#ifdef Rakib_18
	freopen("Error.txt", "w", stderr);
#endif
}
using namespace chrono;

/*_________________________________________________________________________________________________________________________________________________________________________________________________________________________*/
const int mod = 1e9 + 7;
int expo(int a, int b, int mod) { int res = 1; while (b > 0) { if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; }
int mminvprime(int a, int b) { return expo(a, b - 2, b); }
int inv(int i) { if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod; }
bool isPrime(int n) { if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false; for (int i = 5; i * i <= n; i += 6) { if (n % i == 0 || n % (i + 2) == 0)return false; } return true; }
int lcm(int a, int b) { return (a / __gcd(a, b)) * b; }
int mod_add(int a, int b, int m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
int mod_mul(int a, int b, int m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
int mod_sub(int a, int b, int m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
int mod_div(int a, int b, int m) { a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m; }  //only for prime m
int nXOR(int n) { if (n % 4 == 0)return n; if (n % 4 == 1)return 1; if (n % 4 == 2)return n + 1; return 0; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*_________________________________________________________________________________________________________________________________________________________________________________________________________________________*/

bool inRange(int width, int x, int y) {
	if (width < x || width < y)return true;
	else return false;
}
void RakibOne8()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;

	// 0 -> .
	// 1 -> #
	vector<vector<int>>cost(m + 1, vector<int>(2));

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;


		for (int j = 0; j < m; j++) {
			if (s[j] == '.') {
				cost[j + 1][0]++;
			}
			else {
				cost[j + 1][1]++;
			}
		}
	}

	vector<int>prefZero(m + 1);
	vector<int>prefOne(m + 1);

	for (int i = 1; i <= m; i++) {
		prefZero[i] = prefZero[i - 1] + cost[i][0];
		prefOne[i] = prefOne[i - 1] + cost[i][1];
	}

	debug(prefOne, prefZero);

	/*
	dp[i][j] = minimum changes from 0th to ith column such that current column type is j
	*/

	const int INF = 1e18;
	vector<vector<int>>dp(m + 1, vector<int>(2, INF));
	//Base
	dp[0][0] = 0;
	dp[0][1] = 0;


	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= 1; j++) {

			int result = INF;
			for (int range = x; range <= y; range++) {
				if (range <= i) {
					int c = (j ? prefZero[i] - prefZero[i - range] : prefOne[i] - prefOne[i - range]);
					result = min(result, dp[i - range][j ? 0 : 1] + c);
				}

			}

			dp[i][j] = result;

		}
	}
	cout << min(dp[m][0], dp[m][1]) << nl;

}
int32_t main()
{
	init_code();
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	// cin >> t;
	auto start1 = high_resolution_clock::now();
	while (t--)
	{
		RakibOne8();
	}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef Rakib_18
	cerr << "Time: " << duration . count() / 1000 << " ms" << endl;
#endif
	return 0;
}